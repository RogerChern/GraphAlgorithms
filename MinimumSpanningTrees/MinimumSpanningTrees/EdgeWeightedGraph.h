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
    size_t                  v_      = 0;
    size_t                  w_      = 0 ;
    double                  weight_ = MAX_;
    static const double     MAX_;
public:
    Edge(size_t v, size_t w, double weight):
        v_(v),
        w_(w),
        weight_(weight)
    {
        
    }
    
    Edge()
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
    
    friend bool operator<(const Edge &lhs, const Edge &rhs);
    friend bool operator>(const Edge &lhs, const Edge &rhs);
    friend ostream & operator<<(ostream &out, const Edge &e);
};

class EdgeWeightedGraph{
private:
    vector<vector<Edge>>                   adjList_;
    size_t                                 E_;
    size_t                                 V_;
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
    
    vector<Edge> adj(size_t v) const
    {
        return adjList_[v];
    }
    
    vector<Edge> edges() const
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
        V_(V),
        adjList_(V)
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
    
    
    friend ostream & operator<<(ostream &, const EdgeWeightedGraph &);
};
bool operator<(const Edge &lhs, const Edge &rhs);
bool operator>(const Edge &lhs, const Edge &rhs);
ostream & operator<<(ostream &out, const EdgeWeightedGraph &ewg);
ostream & operator<<(ostream &out, const Edge &e);
#endif
