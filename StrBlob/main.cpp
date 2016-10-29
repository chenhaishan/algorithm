#include <iostream>
#include <initializer_list>
#include "strblob.h"
using namespace std;

int main(int argc, char *argv[])
{
    StrBlob b1{"hello", "world"};
    {
        StrBlob b2{"a", "b", "c", "d"};
        b1 = b2;
        b2.push_back("about");
    }/*b2 is destoried, but the elements in b2 still exist.*/
    cout<<"size of b1:"<<b1.size();
    //cout<<"size of b2:"<<b2.size();

    for(StrBlob::StrBlobPtr ptr = b1.begin(); ptr != b1.end(); ++ptr){
        cout<< *ptr<<endl;
    }

    return 0;
}
