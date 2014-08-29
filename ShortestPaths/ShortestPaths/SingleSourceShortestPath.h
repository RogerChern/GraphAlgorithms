//
//  SingleSourceShortestPath.h
//  ShortestPaths
//
//  Created by RogerChen on 14-8-29.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef ShortestPaths_SingleSourceShortestPath_h
#define ShortestPaths_SingleSourceShortestPath_h

#include "EdgeWeighedDiGraph.h"
#include "IndexPriorityQueue.h"
#include <cfloat>
#include <vector>
using namespace std;

class SingleSourceShortestPath{
private:
    vector<DirectedWeighedEdge>               pathTo_;
    vector<double>                            distTo_;
    const DirectedWeighedEdge                 GAURD_;
    IndexPriorityQueue<DirectedWeighedEdge>   pq_;
    
private:
    void edgeRelax(DirectedWeighedEdge &e)
    {
        auto v = e.from();
        auto w = e.to();
        if(distTo_[w] > distTo_[v] + e.weight())
        {
            distTo_[w] = distTo_[v] + e.weight();
            pathTo_[w] = e;
        }
    }
    
    void vertexRelax(const EdgeWeightedDiGraph &ewdg, size_t v)
    {
        for(const auto &e : ewdg.adj(v))
        {
            auto w = e.to();
            if(distTo_[w] > distTo_[v] + e.weight())
            {
                distTo_[w] = distTo_[v] + e.weight();
                pathTo_[w] = e;
                if(pq_.contains(w))
                {
                    pq_.changeKey(w, e);
                }
                else
                {
                    pq_.insert(w, e);
                }
            }
        }
    }
    
public:
    SingleSourceShortestPath(const EdgeWeightedDiGraph &ewdg, size_t source):
        pathTo_(ewdg.V()),
        distTo_(ewdg.V(), DBL_MAX),
        GAURD_(0, 0, 0),
        pq_(ewdg.V())
    {
        pathTo_[source] = GAURD_;
        distTo_[source] = 0;
        pq_.insert(source, GAURD_);
        while(!pq_.empty())
        {
            vertexRelax(ewdg, pq_.removeMin());
        }
    }
    
public:
    bool hasPathTo(size_t v) const
    {
        return distTo_[v] < DBL_MAX;
    }
    
    double distTo(size_t v) const
    {
        return distTo_[v];
    }
    
    vector<DirectedWeighedEdge>  pathTo(size_t v) const
    {
        vector<DirectedWeighedEdge> ret;
        if(!hasPathTo(v))
        {
            return ret;
        }
        while(pathTo_[v] !=  GAURD_)
        {
            ret.push_back(pathTo_[v]);
            v = pathTo_[v].from();
        }
        return ret;
    }
    
};

#endif
