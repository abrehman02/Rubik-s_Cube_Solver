//
// Created by heisenberg on 12/18/24.
//
#include <bits/stdc++.h>
using namespace std;
#include "IDDFS.h"
#include "DummyHeuristic.h"
#include "../PatternDatabase/CornerPatternDatabase.h"
#ifndef IDASTAR_H
#define IDASTAR_H
// #define F first
#define S second
template <typename T, typename H>
class IDAstarSolver
{
private:
    CornerPatternDatabase cornerDB;
    unordered_map<T, bool, H> visited;
    vector<RubiksCube::MOVE> mvs;
    DummyHeuristic<T> dummy;
    unordered_map<T, RubiksCube::MOVE, H> moves_done;
    string fileName;
    struct Node
    {
        T config;
        int depth;
        int heuristic;
        Node(T config_, int depth_, int heuristic_)
        {
            config = config_;
            depth = depth_;
            heuristic = heuristic_;
        }
    };
    struct compare
    {
        bool operator()(pair<int, Node> a, pair<int, Node> b)
        {
            int d1 = a.second.depth + a.S.heuristic;
            int d2 = b.second.depth + b.S.heuristic;
            if (d1 == d2)
            {
                return a.second.heuristic > b.second.heuristic;
            }
            return d1 > d2;
        }
    };

public:
    T rubiksCube;
    IDAstarSolver(T rubiksCube_)
    {
        rubiksCube = rubiksCube_;
    }
    IDAstarSolver(T rubiksCube_,string fileName_)
    {
        rubiksCube = rubiksCube_;
        fileName=fileName_;
        cornerDB.fromFile(fileName);
    }
    pair<T, int> IDAstar(int bound)
    {
        // int next_bound=100;
        priority_queue<pair<int, Node>, vector<pair<int, Node>>, compare> pq;
        // Node start = Node(rubiksCube, 0, dummy(rubiksCube));
        Node start = Node(rubiksCube, 0, cornerDB.getNumMoves(rubiksCube));
        pq.push(make_pair(0, start));
        int next_bound = 100;
        while (!pq.empty())
        {
            auto tp = pq.top();
            int move = tp.first;
            Node curr = tp.second;
            pq.pop();

            if (visited[curr.config])
                continue;
            visited[curr.config] = true;
            moves_done[curr.config] = RubiksCube::MOVE(move);
            if (curr.config.isSolved())
            {
                return make_pair(curr.config, bound);
            }
            int depth = curr.depth + 1;

            for (int i = 0; i < 18; i++)
            {

                T temp = curr.config;
                temp.move(RubiksCube::MOVE(i));
                if (!visited[temp])
                {
                    if (depth + cornerDB.getNumMoves(temp)> bound)
                    {
                        next_bound = min(next_bound, depth + cornerDB.getNumMoves(temp));
                    }
                    else
                    {
                        // mvs.push_back(RubiksCube::MOVE(i));
                        Node nd = Node(temp, depth,cornerDB.getNumMoves(temp));
                        pq.push(make_pair(i, nd));
                    }
                }
            }
            // moves_done[curr.config]=RubiksCube::MOVE(i);
        }
        return make_pair(rubiksCube, next_bound);
    }
    void resetStructure()
    {
        mvs.clear();
        moves_done.clear();
        visited.clear();
    }
    vector<RubiksCube::MOVE> solve()
    {
        int bound = 1;
        auto p = IDAstar(bound);
        while (p.second != bound)
        {
            resetStructure();
            bound = p.second;
            p = IDAstar(bound);
        }
        T solved_cube = p.first;
        assert(solved_cube.isSolved());
        T curr_cube = solved_cube;
        while (curr_cube != rubiksCube)
        {
            mvs.push_back(moves_done[curr_cube]);
            curr_cube.invert(moves_done[curr_cube]);
        }
        rubiksCube = solved_cube;
        reverse(mvs.begin(), mvs.end());
        return mvs;
    }
};
#endif // IDASTAR_H
