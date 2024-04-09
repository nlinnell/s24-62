#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <set>
#include <vector>



// assumption: vertices are numbered 0, 1, ..., n-1

class Graph
{
public:

    // pre: none
    // post: an empty Graph has been created
    Graph();

    // pre: none
    // post: returns the number of vertices in this Graph
    std::size_t n() const;

    // pre: none
    // post: returns the number of edges in this Graph
    std::size_t m() const;

    // pre: i < n()
    // post: returns the adjacency list of i in this Graph
    std::set<std::size_t> adj(std::size_t i) const;

    // pre: none
    // post: a new vertex with label n() has been added to this Graph
    void add_vertex();

    // pre: i < n() && j < n()
    // post: edge {i, j} has been added to this Graph
    //       if it is not an edge already
    void add_edge(std::size_t i, std::size_t j);

    // pre: i < n() && j < n()
    // post: edge {i, j} has been removed from this Graph
    //       if it is currently an edge; otherwise do nothing
    void remove_edge(std::size_t i, std::size_t j);

    // pre: i < n() && j < n()
    // post: returns true iff {i, j} is an edge of this Graph
    bool is_edge(std::size_t i, std::size_t j)  const;

    //pre:none
    //post: Print the vertices of the Graph in BFS order starting at 0
    void bfs(std::size_t source);
/*
    // pre: none
    // post: returns the number of connected components of this Graph
    std::size_t ncc() const;
 

    // pre: none
    // post: returns true if this Graph is connected
    bool is_connected() const;

    // pre: none
    // post: returns true if this Graph has no cycles
    bool is_acyclic() const;

    // pre: none
    // post: returns true iff this Graph is a complete Graph
    bool is_complete() const;

    */

 private:

    std::vector<std::set<std::size_t> > data_;

    // class invariants:
    // this Graph has data_.size() vertices labeled 0, 1, ...,
    //   data_.size() - 1
    // data_[i] is the adjacency list of vertex i

};

// pre: none
// post: outputs g to stream os in the following format
//  n m
//  i1 j1  (where i1 < j1)
//  ...
//  im jm
//std::ostream & operator << (std::ostream & os, const Graph & g);
//std::istream & operator >> (std::istream & is, Graph & g);


#endif // GRAPH_H
