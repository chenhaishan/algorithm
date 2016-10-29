#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2 || !strcmp("-h", argv[1])){
        cout << "usage: %s file.txt" << endl;
        return 0;
    }
    map<char, unsigned int> freq;
    char c;
    ifstream ifile(argv[1],ios::binary);
    while((c=ifile.get()) != EOF){
        freq[c]++;
    }

    for(auto item : freq){
        cout << item.first << ":" << item.second <<endl;
    }
    return 0;
}
