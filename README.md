
# Cody Lejang – Data Structures & Algorithms (DSA) Repository

This repository contains a series of C++ projects developed to demonstrate core concepts in Data Structures and Algorithms at UCLA. Each project explores different structures, programming paradigms, and problem-solving strategies using object-oriented design, recursion, file I/O, and algorithmic logic.

## Project 1 – Blackjack Hand Evaluator
- **Focus**: Object-oriented design, enums, and strategy modeling
- **Files**: `Card.cpp/h`, `Hand.cpp/h`, `Enums.h`, `main.cpp`
- **Description**: 
  Implements a simulation of two-card Blackjack hands and determines the optimal player move (Hit, Stand, Split, etc.) based on a hardcoded strategy matrix. Emphasizes enum handling and encapsulated game logic.

## Project 2 – Recursive Algorithms
- **Focus**: Recursion fundamentals
- **File**: `project2.cpp`
- **Description**: 
  Implements four recursive functions:
  - `modulo(m, n)` – Performs modulo using subtraction
  - `occurrences(num, digit)` – Counts occurrences of a digit in an integer
  - `lucky7s(str)` – Inserts "77" between duplicate characters
  - `combinations(arr, size, target)` – Solves subset sum problem
  Includes full assertion-based testing.

## Project 3 – Singly Linked List
- **Focus**: Linked list implementation, memory management
- **Files**: `List.cpp/h`, `ListNode.cpp/h`, `main.cpp`, `ListMenu.cpp`
- **Description**: 
  A custom singly linked list class supporting:
  - Insertion, deletion, and search
  - Lexicographical `min()` retrieval
  - Conditional filtering (`removeAllBiggerThan`)
  - Positioning and ordering logic

## Project 4 – Titanic Survival Data Analysis
- **Focus**: CSV parsing, dynamic memory, data grouping
- **Files**: `main.cpp`, `CSVFile.cpp/h`, `DataCollectorCallback.h`, `Passenger.cpp/h`, `PassengerDatabase.cpp/h`, `PassengerOutputTable.cpp/h`, `OutputTableRow.cpp/h`, `Enums.h`, `Settings.h`
- **Description**: 
  Parses CSV data on Titanic passengers to compute survival rates across:
  - Travel class (First, Second, Third)
  - Port of embarkation (Cherbourg, Queenstown, Southampton)
  - Fare ranges
  Uses dynamic filtering, enum classification, and formatted table display.

## Project 5 – CricketTeam
- **Focus**: Doubly linked list with sorting and merging
- **File**: `CricketTeam.cpp`
- **Description**: 
  Manages a team roster using a custom doubly linked list with support for:
  - Sorted insertion by name
  - Substitution and removal
  - Copy control and object integrity
  - Team merging and filtering

## Project 6 – Cyborgs
- **Focus**: Game simulation and grid-based logic
- **File**: `cyborgs.cpp`
- **Description**: 
  Implements a turn-based arena simulation with:
  - Player and cyborg interactions
  - Wall-bound grid movement
  - Input validation and AI behavior
  Demonstrates game loop management using object-oriented logic.

## Author

**Cody Lejang**  
B.S. in Cognitive Science, Specialization in Computing, minor in Data Science Engineering – UCLA  
Interested in the intersection of machine learning, psychology, and data analytics.
