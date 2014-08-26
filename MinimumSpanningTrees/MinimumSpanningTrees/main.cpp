//
//  main.cpp
//  MinimumSpanningTrees
//
//  Created by RogerChen on 14-8-24.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include "EdgeWeightedGraph.h"
#include "LazyPrimMST.h"
#include "EagerPrimMST.h"
#include "IndexPriorityQueue.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[])
{
    fstream fin("/Users/rogerchen/Desktop/data/tinyEWG.txt");
    EdgeWeightedGraph ewg(fin);
    cout << ewg << endl;
    
    LazyPrimMST lpmst(ewg);
    for(const auto &x : lpmst.edges())
    {
        cout << x << '\n';
    }
    cout << lpmst.weight() << endl;
    return 0;
}
