GraphAlgorithms
===============

Modern C++ implementation of Graph Algorithms for Sedgewick's *Algotirhms 4th*
When I say modern C++, I mean C++11/14

Currently version 1.0 has come out
the list below shows the data structure and algorithms has been implemented.
##Auxliary
###String Process
split method
###IndexPriorityQueue
this structure is quite a little bit fuzzy, read the source code to gain more info
###UnionFind
Weighted quick-union with path compression

##Undirected Unweighted Graph
  using vector<vector<size_t>>  adjList as core structure
###BFS/DFS on UUG
  BFS features a queue<size_t> structure while DFS takes advantage of system call stack
###CC on UUG
  using DFS
###Search/FindPath on CC
  using DFS
###SymbolGraph
  using a map string ---> index

##Directed Unweighted Graph
  also using vector<vector>> adjList as core structure
###BFS/DFS on DUG
###Cycle Detection
###SymbolDiGraph
###SCC

##Mimimum Spanning Tree
###Lazy Prim
###Eager Prim(using IndexPQ)
###Kruskal

##Shortest Path
###Dijkstra
###Topological Order for DAG
###BellmanFord
