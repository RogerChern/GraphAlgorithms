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
        if(!temp.empty())//in case of mutliple appearance of delimiters
        {
            ret.push_back(temp);
        }
        cursor = index + 1;
        index = raw.find_first_of(delim, cursor);
    }
    if(cursor < raw.size())
    {
        ret.push_back(raw.substr(cursor, string::npos));//append the rest of the raw string to vec
    }
    return std::move(ret);
}
