//
//  main.cpp
//  MinimumSpanningTrees
//
//  Created by RogerChen on 14-8-26.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include "IndexPriorityQueue.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

int main(int argc, char **argv)
{
    random_device rd;
    mt19937 g(rd());

    vector<double> vec{11, 10, 9 ,8 ,7 ,6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7};
    IndexPriorityQueue<double, greater<double>> ipq(vec);
    while(!ipq.empty())
    {
        cout << ipq.getItem(ipq.removeMin()) << ' ';
    }
    return 0;
}
