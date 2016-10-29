#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending){
    return (ctr>1)?word+ending:word;
}

class QueryResult{
    using line_no = vector<string>::size_type;
private:
    /*word to find*/
    string sought;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;

public:
    QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f)
        :sought(s), lines(p), file(f){}



    ostream &print(ostream &os){
        os << this->sought<<" occurs "<< this->lines->size() << " "
           <<make_plural(this->lines->size(), "time", "s") <<endl;
        for(auto num:*this->lines)
            os<<"\t(line " << num + 1 <<")"<< *(this->file->begin() +num)<<endl;
        return os;
    }

};

#endif // QUERYRESULT_H
