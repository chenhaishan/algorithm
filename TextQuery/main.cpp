#include <iostream>
#include <fstream>
#include "textquery.h"
#include "queryresult.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout<<"input file:"<<endl;
    string file, sought;
    cin >> file;
    ifstream is(file);
    TextQuery tq(is);
    cout<<"word to search:"<<endl;
    cin>>sought;
    (tq.query(sought)).print(cout);
    return 0;
}
