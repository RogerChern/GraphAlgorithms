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
    vector<string> strings = { "it", "was", "the", "best", "of", "times", "it", "was", "the", "worst" };
    IndexPriorityQueue<string, less<string>> ipq(strings);
    ipq.changeKey(3, "not");
    while(!ipq.empty())
    {
        cout << ipq.getItem(ipq.removeMin()) << ' ';
    }
    cout << '\n';

    for(auto i = 0; i < strings.size(); ++i)
    {
        ipq.insert(i, strings[i]);
    }
    
    while(!ipq.empty())
    {
        cout << ipq.getItem(ipq.removeMin()) << ' ';
    }

    return 0;
}
