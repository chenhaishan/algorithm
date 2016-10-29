#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <vector>
using namespace std;

template <typename Object>
void swap(Object &left, Object &right){
    Object tmp = left;
    left = right;
    right = tmp;
}

template <typename T>
class MinHeap{
private:
    /*
     * dad = i;
     * leftson = i<<1 +1;
     * rightson = leftson+1 = i<<1 + 2;
    */
    vector<T> hp;
    void min_heapify();
public:
    MinHeap();
    MinHeap(const MinHeap &);
    ~MinHeap();

    //check if heap is empty
    bool empty()const;
    //check head of heap
    T top()const;

    //insert one node
    MinHeap & insert(const T &);

};

#endif // MINHEAP_H
