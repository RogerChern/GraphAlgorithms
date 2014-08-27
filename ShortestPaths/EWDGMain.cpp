//
//  EWDGMain.cpp
//  ShortestPaths
//
//  Created by RogerChen on 14-8-27.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//
#include "EdgeWeighedDiGraph.h"
#include <fstream>
using namespace std;
int main(int argc, char **argv)
{
    fstream fin("/Users/rogerchen/Desktop/data/tinyEWD.txt");
    EdgeWeightedDiGraph ewdg(fin);
    cout << ewdg << endl;
    return 0;
}