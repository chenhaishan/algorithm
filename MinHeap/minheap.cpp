#include "minheap.h"
#include "minheapexception.h"
#include <vector>
#include <iostream>
using namespace std;

template<typename T>
MinHeap<T>::MinHeap(){}

template<typename T>
MinHeap<T>::MinHeap(const MinHeap & other){
    hp = other;
}

template<typename T>
MinHeap<T>::~MinHeap(){}

template<typename T>
T MinHeap<T>::top()const{
    if(!empty())
        return hp[0];
    else
        throw EmptyHeap();
}

template<typename T>
bool MinHeap<T>::empty() const{
    return hp.empty();
}

template<typename T>
void MinHeap<T>::min_heapify(){
    auto sz = hp.size();
    vector<T>::size_type dad = sz/2 - 1,
            son = dad << 1 + 1;
    while(son < sz){
        if(son+1 < sz && hp[son] > hp[son+1])
            son++;
        if(hp[dad] < hp[son] )return;
        else{
            swap(hp[dad], hp[son]);
            dad =
        }
    }

}

template<typename T>
MinHeap & MinHeap<T>::insert(const T &t){

    hp.push_back(t);
    min_heapify();
    return *this;
}
