//
// Created by heisenberg on 12/17/24.
//
#include<bits/stdc++.h>
#include "../RubiksCube.h"
#ifndef BFS_H
#define BFS_H
template<typename T,typename H>
class BFS {
private:
    vector<RubiksCube::MOVE>moves;
    unordered_map<T,bool,H>visited;
    unordered_map<T,RubiksCube::MOVE,H>moves_done;
    T bfs() {
        queue<T>q;
        q.push(RubiksCube);
        visited[RubiksCube]=true;
        while(!q.empty()) {
            T node=q.front();
            q.pop();
            if(node.isSolved(node)) {
                return node;
            }
            for(int i=0;i<18;i++) {
                auto curr_move=RubiksCube::MOVE(i);
                node.move(curr_move);
                if(visited[node]!=true) {
                    visited[node]=true;
                    moves_done[node]=curr_move;
                    q.push(node);
                }
                node.invert(curr_move);
            }

        }
        return rubikscube;
    }
};
#endif //BFS_
