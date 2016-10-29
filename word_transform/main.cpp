#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <stdexcept>

using namespace std;

map<string, string> buildMap(ifstream &map_file){
    map<string, string> ret;
    string key, value;
    while(map_file >> key && getline(map_file, value)){
        if(value.size() > 1)
            ret[key] = value.substr(1);
        else
            throw runtime_error("no rule for "+key);

    }
    return ret;
}

const string &
transform(const string & word, const map<string, string> &trans_map){
    auto map_it = trans_map.find(word);
    if(map_it != trans_map.cend())
        return map_it->second;
    else
        return word;
}

void word_transform(ifstream &map_file, ifstream &input){
    auto trans_map = buildMap(map_file);
    string text;
    while(getline(input, text)){
        istringstream is(text);
        string word;
        bool firstword = true;
        while(is >> word){
            if(firstword)
                firstword = false;
            else
                cout <<" ";
            cout << transform(word, trans_map);
        }
        cout<<endl;
    }
}

int main(int argc, char *argv[])
{
    string map_file, input;
    cout << "input map_file:" << endl;
    cin >> map_file;
    cout << "input file to transform:"<<endl;
    cin >> input;

    ifstream is_map_file(map_file);
    ifstream is_input(input);
    word_transform(is_map_file, is_input);
    return 0;
}
