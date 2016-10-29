#include <vector>
#include <string>
#include <iostream>
#include "BinaryHeap.h"
using namespace std;

int main(int argc, char *argv[])
{
    vector<int> vi = {13,21,16,24,31,19,18,65,26,32};
    BinaryHeap<int> BH(vi);
    printheap(BH);
    cout<<"insert 14"<<endl;
    BH.insert(14);
    printheap(BH);
    cout<<"deleteMin"<<endl;
    BH.deleteMin();
    printheap(BH);
    cout<<"decreasekey(10,20)"<<endl;
    BH.decreasekey(10,20);
    printheap(BH);
    cout<<"increase(1,20)"<<endl;
    BH.increasekey(1, 20);
    printheap(BH);
    cout<<"remove(5)"<<endl;
    BH.remove(5);
    printheap(BH);
    return 0;
}
