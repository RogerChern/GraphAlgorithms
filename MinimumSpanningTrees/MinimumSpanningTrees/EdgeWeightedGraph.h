//
//  EdgeWeightedGraph.h
//  MinimumSpanningTrees
//
//  Created by RogerChen on 14-8-25.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef MinimumSpanningTrees_EdgeWeightedGraph_h
#define MinimumSpanningTrees_EdgeWeightedGraph_h

#include <queue>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

class Edge{
private:
    size_t         v_;
    size_t         w_;
    double         weight_;
public:
    Edge(size_t v, size_t w, double weight):
        v_(v),
        w_(w),
        weight_(weight)
    {
        
    }
public:
    double weight() const
    {
        return weight_;
    }
    
    size_t either() const
    {
        return v_;
    }
    
    size_t other(size_t v) const
    {
        if(v == v_)
        {
            return w_;
        }
        else if(v == w_)
        {
            return v_;
        }
        else
            return -1;
    }
};

class EdgeWeightedGraph{
private:
    vector<vector<Edge>>    adjList_;
    size_t                  E_;
    size_t                  V_;
public:
    void addEdge(Edge e)
    {
        auto temp = e.either();
        adjList_[temp].push_back(e);
        adjList_[e.other(temp)].push_back(e);
    }
    
    size_t V() const
    {
        return V_;
    }
    
    size_t E() const
    {
        return E_;
    }
    
    const vector<Edge> adj(size_t v) const
    {
        return adjList_[v];
    }
    
    const vector<Edge> edges() const
    {
        vector<Edge> ret;
        for(const auto &i : adjList_)
        {
            for(const auto &j : i)
            {
                ret.push_back(j);
            }
        }
        return std::move(ret);
    }
public:
    EdgeWeightedGraph(size_t V):
        V_(V)
    {
        
    }
    
    EdgeWeightedGraph(istream &in)
    {
        size_t temp;
        in >> temp;
        *this = EdgeWeightedGraph(temp);
        in >> E_;
        
        size_t x, y;
        double w;
        while(in >> x >> y >> w)
        {
            addEdge(Edge(x, y, w));
        }
    }
};

#endif
