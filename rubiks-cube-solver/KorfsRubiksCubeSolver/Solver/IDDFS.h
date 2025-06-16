//
// Created by heisenberg on 12/18/24.
//
#include<bits/stdc++.h>
using namespace std;
#include "DFS.h"
#ifndef IDDFS_H
#define IDDFS_H
template<typename T,typename H>
class IDDFS {
private:
    int max_search_depth;
    vector<RubiksCube::MOVE> moves;
public:
    T rubikscube;
    IDDFS(T _rubikscube,int _max_search_depth=7) {
        max_search_depth=_max_search_depth;
        rubikscube=_rubikscube;
    }
    vector<RubiksCube::MOVE> solve() {
        for(int i=1;i<=max_search_depth;i++) {
            DFSSolver<T,H> d(rubikscube,i);
            moves=d.solve();
            if(d.rubiksCube.isSolved()) {
                rubikscube=d.rubiksCube;
                break;
            }
        }
        return moves;
    }
};
#endif //IDDFS_H
