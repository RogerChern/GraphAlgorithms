//
//  EdgeWeighedDiGraph.h
//  ShortestPaths
//
//  Created by RogerChen on 14-8-27.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef ShortestPaths_EdgeWeighedDiGraph_h
#define ShortestPaths_EdgeWeighedDiGraph_h
#include <vector>
#include <iostream>
#include <cfloat>
using namespace std;

class DirectedWeighedEdge{
private:
    size_t from_ = 0;
    size_t to_   = 0;
    double weight_ = DBL_MAX;
    
public:
    DirectedWeighedEdge(size_t v, size_t w, double weight):
        from_(v),
        to_(w),
        weight_(weight)
    {
        
    }
    
    DirectedWeighedEdge() = default;
public:
    size_t from() const
    {
        return from_;
    }
    
    size_t to() const
    {
        return to_;
    }
    
    double weight() const
    {
        return weight_;
    }
    
    friend bool operator<(const DirectedWeighedEdge &lhs, const DirectedWeighedEdge &rhs);
    friend bool operator>(const DirectedWeighedEdge &lhs, const DirectedWeighedEdge &rhs);
    friend ostream & operator<<(ostream &out, const DirectedWeighedEdge &e);
};

class EdgeWeightedDiGraph{
private:
    vector<vector<DirectedWeighedEdge>>      adjList_;
    size_t                                   V_;
    size_t                                   E_;
    
public:
    EdgeWeightedDiGraph(size_t v):
        adjList_(v),
        V_(v),
        E_(0)
    {
        
    }
    
    EdgeWeightedDiGraph(istream &in)
    {
        size_t temp;
        in >> temp;
        *this = EdgeWeightedDiGraph(temp);
        in >> E_;
        
        size_t x, y;
        double w;
        while(in >> x >> y >> w)
        {
            addEdge(DirectedWeighedEdge(x, y, w));
        }

    }
public:
    void addEdge(DirectedWeighedEdge e)
    {
        adjList_[e.from()].push_back(e);
    }
    
    size_t V() const
    {
        return V_;
    }
    
    size_t E() const
    {
        return E_;
    }
    
    vector<DirectedWeighedEdge> adj(size_t v) const
    {
        return adjList_[v];
    }
    
    vector<DirectedWeighedEdge> edges() const
    {
        vector<DirectedWeighedEdge> ret;
        for(const auto &i : adjList_)
        {
            for(const auto &j : i)
            {
                ret.push_back(j);
            }
        }
        return std::move(ret);
    }
    
    friend ostream & operator<<(ostream &out, const EdgeWeightedDiGraph &e);
    friend bool operator==(const DirectedWeighedEdge &, const DirectedWeighedEdge &);
    friend bool operator!=(const DirectedWeighedEdge &, const DirectedWeighedEdge &);
};
bool operator==(const DirectedWeighedEdge &, const DirectedWeighedEdge &);
bool operator!=(const DirectedWeighedEdge &, const DirectedWeighedEdge &);
bool operator<(const DirectedWeighedEdge &lhs, const DirectedWeighedEdge &rhs);
bool operator>(const DirectedWeighedEdge &lhs, const DirectedWeighedEdge &rhs);
ostream & operator<<(ostream &out, const EdgeWeightedDiGraph &ewg);
ostream & operator<<(ostream &out, const DirectedWeighedEdge &e);

#endif
