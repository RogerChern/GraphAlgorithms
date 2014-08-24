//
//  DirectedGraph.h
//  DirectedGraph
//
//  Created by RogerChen on 14-8-18.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef DirectedGraph_DirectedGraph_h
#define DirectedGraph_DirectedGraph_h

#include <iostream>
#include <vector>
using namespace std;

class DirectedGraph{
private:
    vector<vector<size_t>>          adjList_;
    unsigned int                    E_ = 0;
    unsigned int                    V_ = 0;
public:
    DirectedGraph() = default;
    DirectedGraph(unsigned int V);
    DirectedGraph(istream &);
public:
    unsigned int          V() const;
    unsigned int          E() const;
    const vector<size_t>  adj(size_t) const;
    void                  addEdge(size_t, size_t);
    DirectedGraph         reverse() const;

    friend ostream & operator<<(ostream&, const DirectedGraph &);
};

ostream & operator<<(ostream &out, const DirectedGraph &dg);

#endif
