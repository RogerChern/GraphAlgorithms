//
//  Graph.cpp
//  algs
//
//  Created by RogerChen on 14-8-14.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include "Graph.h"

ostream & operator<<(ostream &out, const Graph &g)
{
    for(size_t i = 0; i < g.V(); ++i)
    {
        cout << i << ':';
        for(const auto &j : g.adj(i))
        {
            cout << j << ' ';
        }
        cout << endl;
    }
    return out;
}

vector<size_t> & Graph::adj(size_t i)
{
    return (*adj_)[i];
}

const vector<size_t> & Graph::adj(size_t i) const
{
    return (*adj_)[i];
}

void Graph::addEdge(size_t i, size_t j)
{
    (*adj_)[i].push_back(j);
}

size_t Graph::V() const
{
    return adj_->size();
}

size_t Graph::E() const
{
    size_t ret = 0;
    for(const auto &x : *adj_)
    {
        ret += x.size();
    }
    return ret/2;
}

Graph::Graph(size_t V):
         adj_(make_shared<vector<vector<size_t>>>(V)),
         V_(V),
         E_(0)
{
    
}

Graph::Graph(istream &in)
{
    size_t temp, x, y;
    in >> temp;
    *this = Graph(temp);
    in >> E_;
    
    while(in >> x >> y)
    {
        addEdge(x, y);
        addEdge(y, x);
    }
}
