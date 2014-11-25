//
//  EdgeWeightedGraph.cpp
//  MinimumSpanningTrees
//
//  Created by RogerChen on 14-8-25.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include "EdgeWeightedGraph.h"
#include <cfloat>


ostream & operator<<(ostream &out, const EdgeWeightedGraph &ewg)
{
    for(auto i = 0; i < ewg.V_; ++i)
    {
        out << i << ": \n";
        for(const auto &x : ewg.adjList_[i])
        {
            out << "    " << x.other(i) << "   " << x.weight() << '\n';
        }
    }
    return out;
}

ostream & operator<<(ostream &out, const Edge &e)
{
    size_t x = e.either();
    size_t y = e.other(x);
    
    out << x << ' ' << y << "   " << e.weight();
    return out;
}