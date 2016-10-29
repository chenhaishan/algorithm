#include <iostream>
#include <vector>
#include "binarysearchtree.h"
#include "binarysearchtreeexceptions.h"
using namespace std;

int main(int argc, char *argv[])
{
    BST<int> bsti;
    bsti.printtree();
    cout << endl;

    cout<<"insert 5"<<endl;
    bsti.insert(5);
    bsti.printtree();
    cout << endl;

    bsti.makeEmpty();
    vector<int> vi = {6,2,8,1,5,3,4};\
    /*
                6

        2               8

    1       5

          3

           4
    */
    for(unsigned i = 0; i != vi.size(); ++i)
        bsti.insert(vi[i]);
    bsti.printtree();
    cout << endl;

    cout<<"remove 2"<<endl;
    /*
                6

        3               8

    1       5

          4

    */
    bsti.remove(2);
    bsti.printtree();
    cout << endl;

    cout<<"bsti2 is copy of bsti"<<endl;
    BST<int> bsti2(bsti);
    bsti2.printtree();
    cout << endl;

    cout<<"findMin of bsti2:"<<bsti2.findMin()<<endl;
    cout<<"findMax of bsti2:"<<bsti2.findMax()<<endl;
    return 0;
}
