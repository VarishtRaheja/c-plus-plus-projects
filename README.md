# 🎯 C++ Development Projects

Welcome to my **C++ Development Repository**!  
This repository is a collection of modern **C++20 applications**, starting with a **Number Guessing Game**.  
The purpose of this repo is to learn, experiment with, and showcase modern C++ development practices by building projects ranging from beginner-friendly CLI applications to more advanced features.

---

## 🚀 Features of this Repository

- Written in **Modern C++ (C++20)**.
- Code follows **best practices**: organized, readable, and expandable.
- Demonstrates key C++20 features:
  - `std::vector` for **dynamic memory management** and statistics tracking.
  - `std::tuple` for **returning multiple results** from functions.
  - Range-based for loops, `auto` type deduction, and structured bindings.
  - Strong typing and modern headers only (`<vector>`, `<tuple>`, `<iostream>`, etc).
- Designed with **future scalability** in mind — new applications will be added in structured categories.

---


## 🕹️ Project 1: Number Guessing Game

### 📖 Description
The **Number Guessing Game** is a simple console-based application where:
- The program generates a random number within a defined range.
- The player tries to guess the number.
- Hints (too high / too low) are provided.
- Statistics are recorded after the game:
  - Number of attempts
  - Success/failure status
  - Average attempts across multiple sessions

### 🔑 Key Concepts Demonstrated
- **Random number generation** using `<random>`.
- **Dynamic arrays (`std::vector`)** for storing per-game statistics such as attempts, game outcomes, or execution results.
- **Returning multiple values** — game functions return both status and number of attempts packaged neatly in a `std::tuple`.
- **Control flow & loops**: iterative guess-check loop.
- **Structured bindings**: cleaner handling of tuples.

---

## 📊 Game Statistics
Game statistics are maintained using `std::vector` where each game’s result is appended.  
This allows features like:
- Tracking win/loss ratio.
- Displaying attempt count history.

## Project 2: Login Registration Console Application

### 📖 Description/Overview
The **Login&Registration App** lets a single user register and then log in using stored credentials. Data is kept in a CSV file. Passwords use a simple Caesar cipher (letters shifted by 3, digits squared) and input is validated at each step. On first run, it enters registration mode; on subsequent runs, it prompts for login and verifies the entered credentials.

### 🔑 Key Concepts
- Validates first and last names for alphabetic input and minimum length
- Validates username for non-empty, alphanumeric characters only
- Prompts for password confirmation before encrypting
- Encrypts passwords by shifting letters forward by 3 and squaring digits
- Stores data in a custom made file path with columns ID,First,Last,Username,Password
- Reads back stored username and encrypted password, decrypts, and compares

### Building
#### Using CMAKE
mkdir build
cd build
cmake ..
cmake --build .

#### Using Using g++
g++ -std=c++20 -I include src/*.cpp -o login_app

### Future Improvements
- Support multiple user records in the CSV file
- Replace custom cipher with a secure hash (e.g., SHA-256)
- Add unit tests using Catch2 or GoogleTest
- Implement error handling for malformed CSV lines and I/O failures
- Refactor into classes or structs once OOP concepts are learned


---


## 🛠️ Development Environment

- **Language Standard**: C++20
- **Compiler**: Tested with
  - GCC 11+
  - Clang 12+
  - MSVC 2019/2022
- **Build System**: Simple compilation (can extend with CMake later).

### 🔧 Compilation Instructions
To compile the current project:
Using g++
g++ -std=c++20 App1-Nnumber-Guessing-Game.cpp -o number_guess
./number_guess


## 📌 Future Planned Projects

This repository is meant to evolve over time. Planned additions include:
1. **System Utilities** ⚙️
   - File Management Tool (read/write/parse files)
   - Text Analyzer (word frequency, sentiment analysis basics)

2. **Application-like Projects** 🖥️
   - Banking System (account management, transactions)
   - Simple Encrypted Messenger
   - Task Manager / To-Do List

---


## 🌟 Contributions & Learning Goals

This repository is **primarily a personal learning journey** into writing clean, maintainable, and modern **C++20 applications**.  
However, contributions, suggestions, and improvements are always welcome!

### Learning Goals:
- Apply **modern C++ idioms** instead of legacy approaches.
- Gain fluency in dynamic memory handling (`std::vector`, smart pointers).
- Get hands-on with tuples, ranges, lambdas, and functional-style coding in C++20.
- Build increasingly complex projects step by step.

---


## ✅ Current Status
- [x] Number Guessing Game — Complete 🎉
- [x] Login and Registration CLI Application - Complete 🎉
- [ ] Expand into system utilities  
- [ ] Begin more advanced application development  

---


## 📜 License
This project is open-source under the **MIT License** — feel free to use, modify, and learn from it.
