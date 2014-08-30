//
//  DAGShortestPath.h
//  ShortestPaths
//
//  Created by RogerChen on 14-8-30.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef ShortestPaths_DAGShortestPath_h
#define ShortestPaths_DAGShortestPath_h

#include "EdgeWeighedDiGraph.h"
#include "TopologicalSort.h"
#include <vector>
#include <cfloat>
using namespace std;

class DAGShortestPath
{
private:
    vector<DirectedWeighedEdge>       pathTo_; //index-indexed DWE array
    vector<double>                    distTo_; //index-indexed distance array
    DirectedWeighedEdge               GAURD_;
private:
    void vertexRelax(const EdgeWeightedDiGraph &ewdg, size_t source)
    {
        for(const auto &e : ewdg.adj(source))
        {
            if(distTo_[e.to()] > distTo_[source] + e.weight())
            {
                distTo_[e.to()] = distTo_[source] + e.weight();
                pathTo_[e.to()] = e;
            }
        }
    }
public:
    DAGShortestPath(const EdgeWeightedDiGraph &ewdg, size_t source):
        distTo_(ewdg.V(), DBL_MAX),
        pathTo_(ewdg.V())
    {
        distTo_[source] = 0.0f;
        pathTo_[source] = GAURD_;
        
        TopologicalSort ts(ewdg);
        for(const auto &e : ts.reversePostOrder())
        {
            vertexRelax(ewdg, e.from());
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
