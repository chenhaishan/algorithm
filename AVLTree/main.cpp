#include <iostream>
#include <vector>
#include "avltree.h"
using namespace std;

int main(int argc, char *argv[])
{
    vector<int> vi = {4,2,6,1,3,5,7,16,15};

    AVLTree<int> avlt;
    for(unsigned int i = 0; i < vi.size(); ++i)
        avlt.insert(vi[i]);
    avlt.printtree();
    cout << endl;

    cout<<"insert 14"<<endl;
    avlt.insert(14);
    avlt.printtree();
    cout << endl;

    cout<<"insert 13"<<endl;
    avlt.insert(13);
    avlt.printtree();
    cout << endl;

    cout<<"insert 12"<<endl;
    avlt.insert(12);
    avlt.printtree();
    cout << endl;

    cout<<"insert 11"<<endl;
    avlt.insert(11);
    avlt.printtree();
    cout << endl;

    cout<<"insert 10"<<endl;
    avlt.insert(10);
    avlt.printtree();
    cout << endl;

    cout<<"insert 9"<<endl;
    avlt.insert(9);
    avlt.printtree();
    cout << endl;

    cout<<"insert 8"<<endl;
    avlt.insert(8);
    avlt.printtree();
    cout << endl;

    cout<<"remove 4"<<endl;
    avlt.remove(4);
    avlt.printtree();
    cout << endl;

    cout<<"remove 8"<<endl;
    avlt.remove(8);
    avlt.printtree();
    cout << endl;

    cout<<"remove 13"<<endl;
    avlt.remove(13);
    avlt.printtree();
    cout << endl;

    cout<<"remove 14"<<endl;
    avlt.remove(14);
    avlt.printtree();
    cout << endl;

    cout<<"insert 13"<<endl;
    avlt.insert(13);
    avlt.printtree();
    cout << endl;

    cout<<"remove 10"<<endl;
    avlt.remove(10);
    avlt.printtree();
    cout << endl;

    cout<<"insert 14"<<endl;
    avlt.insert(14);
    avlt.printtree();
    cout << endl;

    cout<<"remove 2"<<endl;
    avlt.remove(2);
    avlt.printtree();
    cout << endl;

    cout<<"remove 5"<<endl;
    avlt.remove(5);
    avlt.printtree();
    cout << endl;
    return 0;
}
