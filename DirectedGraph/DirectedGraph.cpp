//
//  DirectedGraph.cpp
//  DirectedGraph
//
//  Created by RogerChen on 14-8-18.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include "DirectedGraph.h"
#include <utility>

ostream & operator<<(ostream &out, const DirectedGraph &dg)
{
    for(size_t i = 0; i < dg.adjList_.size(); ++i)
    {
        out << i << ": ";
        for(const auto &x : dg.adj(i))
        {
            out << x << ' ';
        }
        out << '\n';
    }
    return out;
}

unsigned int DirectedGraph::E() const
{
    return E_;
}

unsigned int DirectedGraph::V() const
{
    return static_cast<unsigned int>(adjList_.size());
}

const vector<size_t> DirectedGraph::adj(size_t v) const
{
    return adjList_[v];
}

void DirectedGraph::addEdge(size_t v, size_t w)
{
    adjList_[v].push_back(w);
    ++E_;
}

DirectedGraph DirectedGraph::reverse() const
{
    DirectedGraph ret(V_);
    for(size_t i = 0; i < adjList_.size(); ++i)
    {
        for(const auto &x : adjList_[i])
        {
            ret.addEdge(x, i);
        }
    }
    return std::move(ret);
}

DirectedGraph::DirectedGraph(unsigned int V):
    adjList_(V),
    V_(V)
{
    
}

DirectedGraph::DirectedGraph(istream &in)
{
    int temp;
    in >> temp;
    *this = std::move(DirectedGraph(temp));
    in >> temp;
    
    size_t v, w;
    while(in >> v >> w)
    {
        addEdge(v, w);
    }
}