//
//  main.cpp
//  ShortestPaths
//
//  Created by RogerChen on 14-8-27.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "SingleSourceShortestPath.h"
#include "EdgeWeighedDiGraph.h"
#include "DAGShortestPath.h"
using namespace std;

int main(int argc, const char * argv[])
{
    fstream fin("/Users/rogerchen/Desktop/data/tinyEWD.txt");
    EdgeWeightedDiGraph ewdg(fin);
    
    DAGShortestPath sssp(ewdg, 5);
    
    for(auto i = 0; i < ewdg.V(); ++i)
    {
        if(sssp.hasPathTo(i))
        {
            cout << "5 to " << i << " :\n";
            for(const auto &x : sssp.pathTo(i))
            {
                cout << "    " << x << '\n';
            }
            cout << "    " << sssp.distTo(i) << '\n';
        }
    }
    return 0;
}

