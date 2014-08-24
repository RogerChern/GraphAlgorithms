//
//  DirectedAuxiliary.cpp
//  DirectedGraph
//
//  Created by RogerChen on 14-8-19.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include "DirectedAuxiliary.h"

ostream & operator<<(ostream &out, const vector<size_t>  &path)
{
    if(path.size() == 1)
    {
        out << "None";
        return out;
    }
    
    for(auto beg = path.rbegin(), end = path.rend(); beg != end; ++beg)
    {
        out << *beg << ' ';
    }
    return out;
}

vector<string> split(const string &raw, const string &delim)
{
    vector<string> ret;
    string         temp;
    size_t         cursor = 0;
    size_t         index  = 0;
    
    index = raw.find_first_of(delim, cursor);
    while(index != string::npos)
    {
        temp = raw.substr(cursor, index - cursor);
        if(!temp.empty())//address mutli-appearance of delim
        {
            ret.push_back(temp);//the count parameter should be 1 longer
        }
        cursor = index + 1;
        index = raw.find_first_of(delim, cursor);
    }
    if(cursor < raw.size())
    {
        ret.push_back(raw.substr(cursor, string::npos));//push the rest of raw string to vec
    }
    return std::move(ret);
}
