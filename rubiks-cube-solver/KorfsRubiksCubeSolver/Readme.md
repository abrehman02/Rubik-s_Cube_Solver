# Rubik's Cube Solver
- C++ is used when we need performance in our system, we will use C++ to solve our Rubiks Cube.
- In 2010 a proposition was made that any cube out of its 43 quintillion(4.3 * 10^19) state can be solved under 20 moves, so 20 was said to be GOD's number
- So by this the maximum entropy of rubiks cube can be attained by 20 movies only
- This project implements a Rubik's Cube solver using **Korf's Algorithm**, which is an optimal solution method for solving the cube in the minimum number of moves. The solver is designed to explore and demonstrate advanced search techniques and heuristics in solving the Rubik's Cube.

---

## Features

- Implements **Korf's Algorithm** to solve the Rubik's Cube in the fewest possible moves.
- Provides an interactive way to input cube states.

- Step-by-step solution.
- Extendable and modular design for integrating additional solving algorithms.
---

## Table of Contents

- [Introduction](#introduction)
- [How It Works](#how-it-works)
- [Installation](#installation)
- [Usage](#usage)
- [Algorithm Overview](#algorithm-overview)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)

---

## Introduction

The Rubik's Cube Solver project uses **Korf's Algorithm**, a state-of-the-art technique for solving the cube optimally. Korf's Algorithm combines:

- **Iterative Deepening A* (IDA*)**: A search technique to find the shortest solution.
- **Pattern Databases**: Precomputed tables storing minimal moves to solve specific cube configurations.

The project is ideal for enthusiasts and students interested in learning about algorithms, heuristics, and problem-solving in computer science.

---

## How It Works
- Initially when the Object of Rubiks Cube is made, the 
1. **Input**: The user provides the cube's current scrambled state.
2. **Initialization**: The solver initializes heuristic values using precomputed pattern databases.
3. **Search**: The algorithm explores possible move sequences to find the optimal solution.
4. **Output**: The optimal solution sequence and intermediate cube states are displayed.

---

## Installation

### Prerequisites


### Steps

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/rubiks-cube-solver.git
   cd rubiks-cube-solver
   ```

2. Install dependencies:
   ```bash
   pip install -r requirements.txt
   ```

3. Run the solver:
   ```bash
   python solver.py
   ```

---

## Usage

1. Launch the script and follow the prompts to input the cube state.
2. The solver will compute and display the solution step-by-step.
3. For visual representation, a GUI can be enabled (if implemented).

---

## Algorithm Overview

### Korf's Algorithm

Korf's Algorithm solves the Rubik's Cube using the following steps:

- **Problem Representation**: The cube is represented as a state tree where each node is a configuration.
- **Iterative Deepening A***: Combines depth-first search's space efficiency with breadth-first search's optimality.
- **Heuristics**: Pattern databases store precomputed optimal solutions for subproblems (e.g., corners, edges).

### Why Korf's Algorithm?

- Guarantees the optimal solution.
- Efficient use of memory with iterative deepening.
- Demonstrates advanced algorithmic concepts.

---

## Project Structure

```
Rubiks-Cube-Solver/
├── solver.py           # Main script for the solver
├── README.md           # Documentation
├── requirements.txt    # Dependencies
├── pattern_db/         # Precomputed pattern databases
├── tests/              # Unit tests
└── gui/                # GUI implementation (if any)
```

---

## Contributing

Contributions are welcome! If you want to contribute:

1. Fork the repository.
2. Create a feature branch:
   ```bash
   git checkout -b feature-name
   ```
3. Commit your changes and push to the branch:
   ```bash
   git push origin feature-name
   ```
4. Open a pull request.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---
