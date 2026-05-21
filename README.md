# DS_Project

Small Qt (C++/Qt Widgets) application demonstrating an undirected weighted graph data structure
with GUI to add cities (vertices), add edges, traverse (BFS/DFS) and find shortest paths (Dijkstra / Bellman-Ford).

This repository was cleaned and improved for publishing on GitHub. Changes made:

- Converted `Graph` to a header-only template (`DS/Graph.h`) to fix template-linking issues.
- Stopped including generated/IDE files in source (`*.pro.user`, build artifacts) and added `.gitignore`.
- Improved `mainwindow.h` to include `Graph.h` instead of `Graph.cpp`.

ملحوظة (عربي): لقد قمت بتحسين المشروع قليلًا وتجهيز الملفات للنشر على GitHub. يمكن بناء المشروع باستخدام Qt Creator أو عبر سطر الأوامر.

## Build / Run

Requirements:

- Qt 6 (the project was generated with Qt 6.9.0)
- A C++17-capable compiler (MinGW or MSVC)

Using Qt Creator (recommended):

1. Open `DS/untitled13.pro` in Qt Creator.
2. Configure a kit (e.g., Desktop Qt 6.x MinGW or MSVC).
3. Build and Run.

Using command line (qmake + make / mingw32-make):

```powershell
cd DS
qmake untitled13.pro
mingw32-make   # or make on other platforms
```

# DS_Project

I developed a small Qt (Qt Widgets) application in C++ that demonstrates an undirected,
weighted graph data structure and a simple GUI for interacting with it.

Overview
--------
This application models cities as vertices and roads (with distances) as weighted edges.
From the GUI you can add and remove cities and edges, view the graph, perform traversals
(BFS and DFS), and compute shortest paths using Dijkstra's and Bellman–Ford algorithms.

Key features
------------
- Add / remove cities (vertices).
- Add / remove edges with integer weights (undirected).
- BFS and DFS traversals with simple output.
- Shortest path calculations: Dijkstra (non-negative weights) and Bellman–Ford (handles negative weights and reports negative cycles).
- Save and load the graph to a local file (`Graph_DB.txt`).

How it works
------------
- The graph implementation is a templated, header-only class (`DS/Graph.h`) that uses
	an adjacency map: `unordered_map<Vertex, unordered_map<Vertex, int>>`.
- Traversals and shortest-path algorithms are implemented as member functions of `Graph`.
- The GUI is implemented with Qt Widgets (`DS/mainwindow.ui` and `DS/mainwindow.*`) and
	connects UI actions (buttons, dropdowns) to the `Graph` API.

Build and run
-------------
Requirements:
- Qt 6 (the project was created with Qt 6)
- A C++17-capable compiler (MinGW on Windows or MSVC)

Recommended (Qt Creator):
1. Open `DS/untitled13.pro` in Qt Creator.
2. Configure a desktop kit (e.g., Desktop Qt 6.x MinGW or MSVC).
3. Build and run from the IDE.

Command line (qmake + make, example for MinGW on Windows):
```powershell
cd DS
qmake untitled13.pro
mingw32-make
```

Usage notes
-----------
- Launch the application and use the provided screens to add cities and edges.
- To view traversal results, choose BFS or DFS and select a start city.
- To compute a shortest path, select source and destination cities and pick Dijkstra
	or Bellman–Ford depending on weight characteristics.
- Saving writes the current graph state to `Graph_DB.txt` in the application directory; loading reads from the same file.

Important files
---------------
- `DS/Graph.h` — templated header-only graph implementation (core algorithms).
- `DS/main.cpp` — application entry point.
- `DS/mainwindow.ui`, `DS/mainwindow.h`, `DS/mainwindow.cpp` — GUI definition and logic.
- `DS/untitled13.pro` — Qt project file.

Notes
-----
- The `DS/build/` directory and IDE user files are build artifacts and should not be committed.
- `Graph_DB.txt` is created at runtime when saving the graph.

If you need, I can add a small console test to demonstrate the `Graph` API or create a CI workflow
to build the project automatically on push.
