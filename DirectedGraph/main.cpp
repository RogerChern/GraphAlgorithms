//
//  main.cpp
//  DirectedGraph
//
//  Created by RogerChen on 14-8-18.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "DirectedGraph.h"
#include "DirectedCycle.h"
#include "DirectedFindPath.h"
#include "DirectedSearchGraph.h"
#include "DirectedAuxiliary.h"
#include "DirectedDepthFirstOrder.h"
#include "StrongConnectedComponent.h"
using namespace std;

int main(int argc, const char * argv[])
{
	fstream fin("testsuit");
    cout << "Test for DirectedGraph.h\n";
    DirectedGraph dg(fin);
    cout << dg << '\n';
    
    cout << "Test for DirectedCycle\n";
    DirectedCycle dc(dg);
    cout << dc.cycle() << "\n\n";
    
    cout << "Test for DirectedBFP/DFP\n";
    DirectedBreathFirstPath dbfp(dg, 3);
    DirectedDepthFirstPath ddfp(dg, 3);
    for(auto i = 0; i < dg.V(); ++i)
    {
        cout << dbfp.pathTo(i) << "    " << ddfp.pathTo(i) << '\n';
    }
    cout << '\n';
    
    cout << "Test for DirectedBFS/DFS\n";
    DirectedSearchGraph &&rdsg = DirectedBreathFirstSearch(dg, {0,9});
    //DirectedBreathFirstSearch dbfs(dg, {0, 9});
    DirectedDepthFirstSearch ddfs(dg, {0, 9});
    for(auto i = 0; i < dg.V(); ++i)
    {
        cout << boolalpha << " reachable " << rdsg.reachable(i) << ' ' << " correspondness "<< (rdsg.reachable(i) == ddfs.reachable(i)) << '\n';
    }
    
    cout << "Test for DirectedDepthFirstOrder\n";
    DirectedDepthFirstOrder ddfo(dg);
    stack<size_t> order = ddfo.reversePostOrder();
    while(!order.empty())
    {
        cout << order.top() << ' ';
        order.pop();
    }
    cout << endl;
    
    cout << "Test for SCC\n";
    StrongConnectedComponent scc(dg);
    cout << scc.count() << endl;
}

