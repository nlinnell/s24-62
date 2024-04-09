
#include <iostream>
#include <fstream>
#include "graph.h"
#include <iostream>
using namespace std;



int main(int argc, char *argv[])
{
    Graph g;
    for(int i=0; i<5; i++)
        g.add_vertex();

    g.add_edge(2, 0);
    g.add_edge(1, 2);
    g.add_edge(3, 1);
    g.add_edge(2, 3);
    g.remove_edge(0, 3);
    cout << g.is_edge(0, 2) << endl;
    cout << g.n() << " " << g.m() << endl;
    g.bfs(0);
   // cout << g << endl;

    
    return 0;
}
