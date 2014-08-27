//
//  EdgeWeighedDiGraph.cpp
//  ShortestPaths
//
//  Created by RogerChen on 14-8-27.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include "EdgeWeighedDiGraph.h"

bool operator<(const DirectedWeighedEdge &lhs, const DirectedWeighedEdge &rhs)
{
    return lhs.weight() < rhs.weight();
}
bool operator>(const DirectedWeighedEdge &lhs, const DirectedWeighedEdge &rhs)
{
    return lhs.weight() > rhs.weight();
}
ostream & operator<<(ostream &out, const EdgeWeightedDiGraph &ewdg)
{
    for(auto i = 0; i < ewdg.V_; ++i)
    {
        out << i << ": \n";
        for(const auto &x : ewdg.adjList_[i])
        {
            out << "    " << x.to() << "   " << x.weight() << '\n';
        }
    }
    return out;
}

ostream & operator<<(ostream &out, const DirectedWeighedEdge &e)
{
    size_t x = e.from();
    size_t y = e.to();
    
    out << x << ' ' << y << "   " << e.weight();
    return out;
}
