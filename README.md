# Rubik's Cube Solver

This project implements a Rubik’s Cube solver using **Korf’s Algorithm**, an optimal solution technique designed to solve the cube in the minimum number of moves. Written in **C++** for high performance, this project demonstrates advanced search strategies and heuristics in a practical setting.

## 🧩 Why Rubik’s Cube?
In 2010, it was proven that any scrambled Rubik’s Cube configuration (out of 43 quintillion possibilities) can be solved in **20 moves or fewer**—a number famously called **God’s Number**. Our solver aims to achieve this optimal solution.

---

## 🚀 Features

- Solves the cube using **Korf’s Algorithm** (optimal move count).
- Accepts **interactive input** for the current cube state.
- Displays a **step-by-step** solution.
- Modular structure—easy to extend with other solving techniques.

---

## 📚 Table of Contents

- [Introduction](#introduction)
- [How It Works](#how-it-works)
- [Installation](#installation)
- [Usage](#usage)
- [Algorithm Overview](#algorithm-overview)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)

---

## 🧠 Introduction

This project uses **Korf's Algorithm**, a highly efficient and optimal method for solving the Rubik's Cube. It combines:

- **Iterative Deepening A*** (IDA\*): A space-efficient search method.
- **Pattern Databases**: Precomputed tables to guide the solver heuristically.

It's perfect for those interested in **AI, heuristics, search algorithms**, or simply a deeper understanding of cube-solving.

---

## ⚙️ How It Works

1. **Input**: User provides the scrambled cube state.
2. **Initialization**: Loads heuristic values using precomputed pattern databases.
3. **Search**: Korf’s Algorithm searches for the shortest path to the solved state.
4. **Output**: Displays each move in the solution sequence step-by-step.

---

## 🛠️ Installation

### 📋 Prerequisites

- C++ compiler (e.g., g++, clang++)
- Python 3 (for utility scripts, if any)

### 📦 Steps

```bash
git clone https://github.com/your-username/rubiks-cube-solver.git
cd rubiks-cube-solver
