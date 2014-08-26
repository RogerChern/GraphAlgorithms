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
    vector<double> vec{11, 10, 9 ,8 ,7 ,6, 5, 4, 3, 2, 1, 0};
    random_shuffle(vec.begin(), vec.end());

    IndexPriorityQueue<double, less<double>> ipq(vec);
	cout << ipq << endl;
    
    return 0;
}
