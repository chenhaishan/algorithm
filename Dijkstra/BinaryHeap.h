#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H
#include <vector>
#include <cmath>
#include "binaryheapexceptins.h"
using namespace std;

template <typename Comparable>
class BinaryHeap{
    template <typename Object>
    friend void printheap(BinaryHeap<Object> &bh);
private:
    unsigned int currentsize;//当前节点的数量
    vector<Comparable> array;

    void buildHeap(){
        for(unsigned int hole=currentsize/2; hole > 0; --hole){
            precolateDown(hole);
        }
    }

    void precolateDown(unsigned int hole){
        unsigned int child;
        Comparable tmp = array[hole];
        for(;hole *2 <= currentsize; hole = child){
            child = hole*2;
            if(child !=currentsize && array[child+1] < array[child])
                ++child;
            if(array[child] < tmp)
                array[hole] = array[child];
            else
                break;
        }
        array[hole] = tmp;
    }

    void precolateUp(int hole){
        int father;
        Comparable tmp = array[hole];
        for(; hole/2 > 0; hole = father){
            father = hole/2;
            if(array[father] > tmp)
                array[hole] = array[father];
            else
                break;
        }
        array[hole] = tmp;
    }

public:
    explicit BinaryHeap():currentsize(0){
        array.resize(1);
    }

    explicit BinaryHeap(const vector<Comparable> & v){
        makeEmpty();
        if(array.size() < v.size()){
            array.resize(v.size() *2);
        }
        currentsize = v.size();
        for(unsigned int i = 1; i <= v.size(); ++i){
            array[i] = v[i-1];
        }
        buildHeap();
    }

    bool isEmpty(){
        return currentsize==0?true:false;
    }

    Comparable findMin() {
        return array[1];
    }

    void insert(const Comparable &x){
        if(currentsize == array.size()-1){
            array.resize(array.size() *2);
        }
        int hole = ++currentsize;
        for(;hole >1 && x < array[hole/2]; hole /=2){
            array[hole] = array[hole/2];
        }
        array[hole] = x;
    }

    void deleteMin(){
        if(isEmpty()){
            throw UnderflowExcpetion();
        }
        array[1] = array[currentsize--];
        precolateDown(1);
    }

    void deleteMin(Comparable &minItem){
        if(isEmpty()){
            throw UnderflowExcpetion();
        }
        minItem = array[1];
        array[1] = array[currentsize--];
        precolateDown(1);
    }

    void makeEmpty(){
        currentsize = 0;
        //array.resize(0);
    }

    void decreasekey(unsigned int pos, unsigned int deta){
        if(isEmpty())
            throw UnderflowExcpetion();
        array[pos] -= deta;
        precolateUp(pos);
    }

    void increasekey(unsigned int pos, unsigned int deta){
        if(isEmpty())
            throw UnderflowExcpetion();
        array[pos] += deta;
        precolateDown(pos);
    }

    void remove(unsigned int pos){

        decreasekey(pos, 0x7fffffff);

        deleteMin();
    }
};

template <typename Object>
void printheap(BinaryHeap<Object> &bh){

    for(unsigned int i = 0; i <=bh.currentsize; ++i){
        cout<<i<<" ";
    }

    cout<<endl<<" "<<endl;
    for(unsigned int i = 1; i <=bh.currentsize; ++i){
        cout<<(bh.array)[i]<<" ";
    }
    cout<<endl;

    unsigned int k = 1, m = 0;
    unsigned int tabs = log(bh.currentsize) / log(2);
    ++tabs;
    for(unsigned int i = bh.currentsize; i >0; i /= 2){
        for(unsigned int j = 0; j < pow(2,m); ++j){
            unsigned int n = 0;
            while(n < 2*pow(2, tabs)){
                cout<<' ';
                ++n;
            }
            if(k <= bh.currentsize)
                cout<<bh.array[k++];
            else
                cout<<"  ";
        }
        cout<<endl;
        ++m;
        --tabs;
    }
}


#endif
