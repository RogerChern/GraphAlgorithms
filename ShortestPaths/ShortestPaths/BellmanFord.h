//
//  BellmanFord.h
//  ShortestPaths
//
//  Created by RogerChen on 14-8-31.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef ShortestPaths_BellmanFord_h
#define ShortestPaths_BellmanFord_h
#include <vector>
#include <queue>
#include <cfloat>
#include "EdgeWeighedDiGraph.h"
using namespace std;

class BellmanFord{
private:
    vector<bool>                      onQueue_;
    queue<size_t>                     queue_;
    vector<DirectedWeighedEdge>       pathTo_;
    vector<double>                    distTo_;
    const DirectedWeighedEdge         GAURD;
private:
    void vertexRelax(const EdgeWeightedDiGraph &ewdg, size_t vertex)
    {
        for(const auto &e : ewdg.adj(vertex))
        {
            if(distTo_[e.to()] > distTo_[vertex] + e.weight())
            {
                distTo_[e.to()] = distTo_[vertex] + e.weight();
                pathTo_[e.to()] = e;
                onQueue_[e.to()] = true;
                queue_.push(e.to());
            }
        }
    }
public:
    BellmanFord(const EdgeWeightedDiGraph &ewdg, size_t source):
        onQueue_(ewdg.V(), false),
        pathTo_(ewdg.V()),
        distTo_(ewdg.V(), DBL_MAX),
        GAURD()
    {
        distTo_[source] = 0.0f;
        pathTo_[source] = GAURD;
        onQueue_[source] = true;
        queue_.push(source);
        
        while(!queue_.empty())
        {
            auto temp = queue_.front();
            queue_.pop();
            onQueue_[temp] = false;
            vertexRelax(ewdg, temp);
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
        while(pathTo_[v] !=  GAURD)
        {
            ret.push_back(pathTo_[v]);
            v = pathTo_[v].from();
        }
        return ret;
    }
};


template<typename T>
class TD;
#endif
