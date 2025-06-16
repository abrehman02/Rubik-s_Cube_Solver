cmake_minimum_required(VERSION 3.29)
project(KorfsRubiksCubeSolver)

set(CMAKE_CXX_STANDARD 20)

add_executable(KorfsRubiksCubeSolver 
        main.cpp
        RubiksCube.cpp
        RubiksCube.h
        RubiksCube3d.cpp
        
        Solver/DFS.h
        Solver/BFS.h
        Solver/IDDFS.h
        Solver/IDAstarSolver.h
        
        PatternDatabase/PatternDatabase.cpp
        PatternDatabase/PatternDatabase.h
        PatternDatabase/NibbleArray.cpp
        PatternDatabase/NibbleArray.h
        PatternDatabase/CornerPatternDatabase.cpp
        PatternDatabase/CornerPatternDatabase.h
        PatternDatabase/CornerDBMaker.cpp
        PatternDatabase/CornerDBMaker.h
        PatternDatabase/PermutationIndexer.h
        PatternDatabase/math.cpp
        PatternDatabase/math.h


)
