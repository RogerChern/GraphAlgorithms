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
#include <cfloat>
using namespace std;

class Edge{
private:
    size_t                  v_      = 0;
    size_t                  w_      = 0 ;
    double                  weight_ = MAX;
    static constexpr double MAX = DBL_MAX;
public:
    Edge(size_t v, size_t w, double weight):
        v_(v),
        w_(w),
        weight_(weight)
    {
        
    }
    
    Edge() = default;
    
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
    
    friend inline bool operator<(const Edge &lhs, const Edge &rhs);
    friend inline bool operator>(const Edge &lhs, const Edge &rhs);
    friend ostream & operator<<(ostream &out, const Edge &e);
};

inline bool operator<(const Edge &lhs, const Edge &rhs)
{
    return lhs.weight() < rhs.weight();
}

inline bool operator>(const Edge &lhs, const Edge &rhs)
{
    return !(lhs < rhs);
}


class EdgeWeightedGraph{
private:
    vector<vector<Edge>>            adjList_;
    size_t                          E_;
    size_t                          V_;
public:
    void addEdge(Edge e)
    {
        auto vertex = e.either();
        adjList_[vertex].push_back(e);
        adjList_[e.other(vertex)].push_back(e);
    }
    
    size_t V() const
    {
        return V_;
    }
    
    size_t E() const
    {
        return E_;
    }
    
    vector<Edge> adj(size_t v) const
    {
        return adjList_[v];
    }
    
    vector<Edge> edges() const
    {
        vector<Edge> ret;
        for(auto &&i : adjList_)
        {
            for(auto &&j : i)
            {
                ret.push_back(j);
            }
        }
        return ret;
    }
    
public:
    EdgeWeightedGraph(size_t V):
        V_(V),
        adjList_(V)
    {
        
    }
    
    EdgeWeightedGraph(istream &in)
    {
        size_t nvertex;
        in >> nvertex;
        *this = EdgeWeightedGraph(nvertex);
        in >> E_;
        
        size_t x, y;
        double w;
        while(in >> x >> y >> w)
        {
            addEdge(Edge(x, y, w));
        }
    }
    
    
    friend ostream & operator<<(ostream &, const EdgeWeightedGraph &);
};

ostream & operator<<(ostream &out, const EdgeWeightedGraph &ewg);
ostream & operator<<(ostream &out, const Edge &e);
#endif
