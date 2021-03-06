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
#include <string>
#include <random>
using namespace std;

int main(int argc, char **argv)
{
    vector<string> test = { "it", "was", "the", "best", "of", "times", "it", "was", "the", "worst", "of", "times" };
    IndexPriorityQueue<string, less<string>> ipq(test);
    ipq.changeKey(3, "not");
    while(!ipq.empty())
    {
        cout << ipq.getItem(ipq.removeMin()) << ' ';
    }
    cout << '\n';

    for(auto i = 0; i < test.size(); ++i)
    {
        ipq.insert(i, test[i]);
    }
    
    while(!ipq.empty())
    {
        cout << ipq.getItem(ipq.removeMin()) << ' ';
    }

    return 0;
}
