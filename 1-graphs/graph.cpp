#include "graph.h"
#include <cassert>
#include <queue>
#include <set>


    // pre: none
    // post: an empty Graph has been created
    Graph::Graph()
    {
        data_ = std::vector<std::set<std::size_t> >();
    }

    // pre: none
    // post: returns the number of vertices in this Graph
    std::size_t Graph::n() const
    {
        return data_.size();

    }

    // pre: none
    // post: returns the number of edges in this Graph
    std::size_t Graph::m() const
    {
        std::size_t count = 0;
        for(auto vx: data_){
            count+=vx.size();
        }
        return count/2;
    }

    // pre: i < n()
    // post: returns the adjacency list of i in this Graph
    std::set<std::size_t> Graph::adj(std::size_t i) const
    {
        assert(i<n());
        return data_[i];
    }

    // pre: none
    // post: a new vertex with label n() has been added to this Graph
    void Graph::add_vertex()
    {
        data_.push_back(std::set<std::size_t>());
    }

    // pre: i < n() && j < n()
    // post: edge {i, j} has been added to this Graph
    //       if it is not an edge already
    void Graph::add_edge(std::size_t i, std::size_t j)
    {
        assert(i < n() && j < n());
        data_[i].insert(j);
        data_[j].insert(i);
    }

    // pre: i < n() && j < n()
    // post: edge {i, j} has been removed from this Graph
    //       if it is currently an edge; otherwise do nothing
    void Graph::remove_edge(std::size_t i, std::size_t j)
    {
        assert(i < n() && j < n());
        data_[i].erase(j);
        data_[j].erase(i);
    }
    

    // pre: i < n() && j < n()
    // post: returns true iff {i, j} is an edge of this Graph
    bool Graph::is_edge(std::size_t i, std::size_t j)  const
    {
        assert(i < n() && j < n());
        return data_[i].find(j)!=data_[i].end();

    }





    //pre:none
    //post: Print the vertices of the Graph in BFS order starting at 0
    void Graph::bfs(std::size_t source){
        //What information do we need to track?
        //What data structures should we use?
        std::queue<std::size_t> q;
        std::vector<bool> visited(n(), false);
        visited[source]=true;
        q.push(source);
        while(!q.empty()){
            //Explore the neighbors of one vertex
            std::size_t curr = q.front();//front, not top
            q.pop();
            std::cout<<curr<<" ";
            for(auto neighbor: data_[curr]){
                if(!visited[neighbor]){
                    visited[neighbor]=true;
                    q.push(neighbor);
                }
            }//HERE
        }
 
    }

/*

std::vector<std::size_t> Graph::at_depth(std::size_t origin, std::size_t d){


    }











    // pre: none
    // post: returns the number of connected components of this Graph
    std::size_t Graph::ncc() const{

}

/*
    // pre: none
    // post: returns true if this Graph is connected
    bool Graph::is_connected() const;


    // pre: none
    // post: returns true if this Graph has no cycles
    bool Graph::is_acyclic() const;



    // pre: none
    // post: returns true iff this Graph is a complete Graph
    bool Graph::is_complete() const;

// pre: none
// post: outputs g to stream os in the following format
//  n m
//  i1 j1  (where i1 < j1)
//  ...
//  im jm
std::ostream & operator << (std::ostream & os, const Graph & g);
std::istream & operator >> (std::istream & is, Graph & g);
*/
