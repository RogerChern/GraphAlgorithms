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
#include "KruskalMST.h"
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main(int argc, const char * argv[])
{
    fstream fin("/Users/rogerchen/Desktop/data/mediumEWG.txt");

    EdgeWeightedGraph ewg(fin);
    
    auto start = clock();
    EagerPrimMST epmst(ewg);
    auto middle = clock();
    LazyPrimMST lpmst(ewg);
    auto later = clock();
    KruscalMST kmst(ewg);
    auto end = clock();
    
    auto duration1 = middle - start;
    auto duration2 = later - middle;
    auto duration3 = end - later;
    cout << "eager Prim consumes "<< double(duration1) / CLOCKS_PER_SEC << "ms" <<endl;
    cout << "lazy Prim consumes "<< double(duration2) / CLOCKS_PER_SEC << "ms" <<endl;
    cout << "Kruscal consumes "<< double(duration3) / CLOCKS_PER_SEC << "ms" <<endl;
    cout << "lazy Prim consumes "<<double(duration2) / duration1 << "X time compared to eager Prim"<< endl;
    cout << "Kruscal consumes "<<double(duration3) / duration1 << "X time compared to eager Prim"<< endl;
    
    return 0;
}
