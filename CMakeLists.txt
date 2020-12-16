cmake_minimum_required(VERSION 3.12)
project(EC_6)

set(CMAKE_CXX_STANDARD 14)

add_executable(EC_6 main.cpp UnionFind.h UnionFind.cpp UndirectedWeightedEdge.h UndirectedWeightedEdge.cpp UndirectedWeightedGraph.h UndirectedWeightedGraph.cpp KruskalMST.h KruskalMST.cpp PrimMST.cpp PrimMST.h min_heap.h DirectedWeightedEdge.cpp DirectedWeightedEdge.h DirectedWeightedGraph.cpp DirectedWeightedGraph.h Dijkstra.cpp Dijkstra.h)
