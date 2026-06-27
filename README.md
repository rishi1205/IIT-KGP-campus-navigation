# 🗺️ IIT Kharagpur Campus Navigation System (C++)

A console-based navigation system built in **C++** that computes the shortest path between major locations within the IIT Kharagpur campus using **Dijkstra's Shortest Path Algorithm**. The project models the campus as a weighted graph and helps users find the most efficient route between two locations.

---

## 📌 Features

- Find the shortest path between campus locations
- Calculate the minimum travel distance
- Display the complete route from source to destination
- Uses Dijkstra's Algorithm for shortest path computation
- Simple and interactive command-line interface
- Handles invalid user input gracefully

---

## 🛠️ Tech Stack

- **Language:** C++
- **Algorithm:** Dijkstra's Algorithm
- **Data Structure:** Graph (Adjacency Matrix)
- **IDE:** VS Code / CodeBlocks 

---

## 📍 Locations Included

- Main Gate
- Central Library
- Vikramshila
- Takshashila
- Nalanda
- Netaji Auditorium
- Kalidas Auditorium
- Gymkhana
- BC Roy Hospital
- Nehru Hall
- Azad Hall
- Patel Hall
- LBS Hall
- MMM Hall
- RP Hall
- RK Hall
- HJB Hall
- LLR Hall
- JCB Hall
- Tata Sports Complex
- Hijli Gate

---

## 📂 Project Structure

```
IIT-KGP-campus-navigation/
│── project1Dijkstra.cpp
│── README.md
└── screenshots/
    ├── home.png
    ├── input.png
    └── output.png
```

---

## 💻 Sample Output

```
====================================
     IIT KHARAGPUR NAVIGATION
====================================

Available Locations

1. Main Gate
2. Central Library
...
21. Hijli Gate

Enter Source Location Number: 1
Enter Destination Location Number: 15

====================================
SOURCE      : Main Gate
DESTINATION : RP Hall
====================================

Shortest Distance = 1950 meters

Shortest Route:

Main Gate
-> Central Library
-> Gymkhana
-> Tata Sports Complex
-> BC Roy Hospital
-> RP Hall
```

---

## 🧠 Algorithm

The project uses **Dijkstra's Algorithm**, a greedy algorithm that computes the shortest path from a source node to every other node in a weighted graph with non-negative edge weights.

---

## 📚 Concepts Used

- Graphs
- Adjacency Matrix
- Greedy Algorithms
- Dijkstra's Algorithm
- Path Reconstruction
- Arrays
- Functions
- User Input Validation

---

## 🎯 Learning Outcomes

This project helped strengthen my understanding of:

- Graph representation using adjacency matrices
- Implementation of Dijkstra's Algorithm
- Shortest path problems
- Modular programming in C++
- Designing interactive console applications

---

## 👨‍💻 Author

**Rishi Trivedi**

---
