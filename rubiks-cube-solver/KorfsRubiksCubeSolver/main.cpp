#include <bits/stdc++.h>
// #include "RubiksCube.h"
// #include "RubiksCube3d.cpp"
// #include "RubiksCube1D.cpp"
// #include "RubiksCubeBitBoard.h"
// #include "./Solver/DFS.h"
// #include "./Solver/IDDFS.h"
#include "./Solver/IDAstarSolver.h"
#include "PatternDatabase/CornerDBMaker.h"
using namespace std;
#include <chrono>
using namespace chrono;

int main()
{
    RubiksCubeBitBoard cube;
    string fileName="/home/heisenberg/CLionProjects/KorfsRubiksCubeSolver/Database.txt";
//        CornerDBMaker dbMaker(fileName, 0x99);
//    dbMaker.bfsAndStore();
   vector<RubiksCube::MOVE>movesMade= cube.randomShuffle(13);
   for(auto x:movesMade){
    cout<<cube.getMoveLetter(x)<<" ";
   }
   cout<<"\n";
   auto start = high_resolution_clock::now(); // Start time
    IDAstarSolver<RubiksCubeBitBoard,HashBitBoard>idaStar(cube,fileName);
    vector<RubiksCube::MOVE>allMoves=idaStar.solve();
    for(auto x:allMoves){
        cout<<cube.getMoveLetter(x)<<" ";
    }
    cout<<"\n";
    auto stop = high_resolution_clock::now();  // Stop time
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken: " << duration.count() << " microseconds" << endl;
    return 0;
    return 0;
}
