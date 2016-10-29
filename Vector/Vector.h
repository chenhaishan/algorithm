#ifndef VECTOR_H
#define VECTOR_H
#include "dsexceptions.h"
#include <initializer_list>
#include <algorithm>
using namespace std;
template <typename Object>
class Vector
{	
	template <typename T>
	friend bool operator== (const Vector<T> &lhs, const Vector<T> &rhs);
public:
	/***带有表长度参数的初始化***/
	explicit Vector(int initSize = 0)
	: theSize(initSize), theCapacity(initSize + SPARE_CAPACITY)
	{
		objects = new Object[theCapacity];
	}
	/***拷贝初始化***/
	Vector(const Vector & rhs):objects(nullptr)
	{
		operator=(rhs);
	}
	/***可变参数初始化***/
	Vector(initializer_list<Object> ILO):theSize(ILO.size()), theCapacity(theSize + SPARE_CAPACITY)
	{
		objects = new Object[theCapacity];
		copy(ILO.begin(), ILO.end(), objects);
	}
	
	~Vector()
	{
		delete [] objects;
	}
	
	const Vector & operator= (const Vector &rhs)
	{
		if(this != &rhs)
		{
			delete [] objects;
			theSize = rhs.size();
			theCapacity = rhs.theCapacity;
			objects = new Object[theSize];
			for(int i = 0; i < theSize; ++i)
			{
				objects[i] = rhs.objects[i];
			}
			
		}
		return *this;
	}
	
	void resize(int newSize)
	{
		if(newSize > theCapacity){
			reserve(newSize *2 +1);
		}
		theSize = newSize;
	}
	
	void reserve(int newCapacity)
	{
		if(newCapacity < theCapacity){
			return ;
		}
		
		Object *oldArray = objects;
		objects = new Object[newCapacity];
		for(int i = 0; i < theSize; ++i){
			objects[i] = oldArray[i];
		}
		
		theCapacity = newCapacity;
		delete []oldArray;
	}
	
	
	const Object & operator[] (int index) const
	{
        if(index<0 || index+1 > theSize)
			throw ArrayIndexOutOfBoundsException();
		return objects[index];
	}
	Object & operator[](int index)
	{
		if(index<0 || index > theSize)
			throw ArrayIndexOutOfBoundsException();
		return objects[index];
	}
	
	
	
	bool empty() const
	{return size() == 0;}
	int size() const
	{return theSize;}
	int capacity() const
	{return theCapacity;}
	
	
	void push_back(const Object & x)
	{
		if(theSize == theCapacity){
			reserve(theSize *2 +1);
		}
		objects[theSize++] = x;
	}
	void pop_back()
	{
		if(!empty()){
			--theSize;
		}
		else{
			throw UnderflowException();
		}
	}
	
	
	const Object & back() const{
		if(!empty()){
			return objects[theSize -1];
		}
		else{
			throw UnderflowException();
		}
	}
	
	
	typedef Object * iterator;
	typedef const Object * const_iterator;
	
	
	iterator begin(){
		if(!empty()){
			return &objects[0];
		}
		else{
			throw IteratorUninitializedException();
		}
	}

	const_iterator begin() const{
		if(!empty()){
			return &objects[0];
		}
		else{
			throw IteratorUninitializedException();
		}
	}	
	iterator end(){
		if(!empty()){
			return &objects[size()];
		}
		else{
			throw IteratorUninitializedException();
		}
	}

	const_iterator end() const{
		if(!empty()){
			return &objects[size()];
		}
		else{
			throw IteratorUninitializedException();
		}
	}	
	
	/***默认容量***/
	enum{SPARE_CAPACITY = 10};

private:
	int theSize;
	int theCapacity;
	Object *objects;
};

template <typename T>
bool operator== (const Vector<T> &lhs, const Vector<T> &rhs)
{
	if(lhs.size() != rhs.size()){
		return false;
	}
	else if(!lhs.size() && !rhs.size()){
		return true;
	}
	else
	{
		typename Vector<T>::const_iterator l = lhs.begin(), r = rhs.begin();
		while(l != lhs.end()){
			if(*l != *r)
				break;
			++l, ++r;
		}
		return l==lhs.end();
	}
}


#endif
