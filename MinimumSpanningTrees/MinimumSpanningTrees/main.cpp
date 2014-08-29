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
#include <chrono>
using namespace std;

int main(int argc, const char * argv[])
{
    fstream fin("/Users/rogerchen/Desktop/data/mediumEWG.txt");

    EdgeWeightedGraph ewg(fin);
//    cout << ewg << "\n\n";
    
//    LazyPrimMST  lpmst(ewg);
//    EagerPrimMST epmst(ewg);
//    KruscalMST   kmst(ewg);
    
    auto start = chrono::system_clock().now();
    EagerPrimMST epmst(ewg);
    auto middle = chrono::system_clock().now();
    LazyPrimMST lpmst(ewg);
    auto later = chrono::system_clock().now();
    KruscalMST kmst(ewg);
    auto end = chrono::system_clock().now();
    
    auto duration1 = middle - start;
    auto duration2 = later - middle;
    auto duration3 = end - later;
    cout << duration1.count() << endl;
    cout << duration2.count() << endl;
    cout << duration3.count() << endl;
    cout << double(duration2.count()) / duration1.count() << endl;
    cout << double(duration3.count()) / duration1.count() << endl;
    
    return 0;
}
