#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <memory>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include "queryresult.h"
using namespace std;

class QueryResult;

class TextQuery{
    using line_no = vector<string>::size_type;
private:
    /*input file, every line*/
    shared_ptr<vector<string>> file;

    /*line and its line-number*/
    map<string, shared_ptr<set<line_no>>> wm;

public:
    TextQuery(ifstream & is):file(new vector<string>){
        string text;
        while(getline(is, text)){
            file->push_back(text);
            int n = file->size() -1;
            istringstream line(text);
            string word;
            while(line>>word){
                auto &lines = wm[word];
                if(!lines)
                    lines.reset(new set<line_no>);
                lines->insert(n);
            }
        }
    }

    QueryResult query(const string &sought) const{
        static shared_ptr<set<line_no>> nodata(new set<line_no>);
        auto loc = wm.find(sought);
        if(loc == wm.end())
            return QueryResult(sought, nodata, file);
        else
            return QueryResult(sought, loc->second, file);
    }

};

#endif // TEXTQUERY_H
