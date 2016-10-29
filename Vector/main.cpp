#include <iostream>
#include <string>
#include "Vector.h"
#include <stdexcept>
using namespace std;

int main(int argc, char **argv)
{
	Vector<string> VS;
	Vector<int> VI={1,2,3};
	Vector<int> VI2{1,2,3};
	VS.push_back("hello");
	VS.push_back("world");
	VS.push_back("!");
	for(Vector<string>::iterator i = VS.begin(); i!=VS.end(); ++i){
		cout<<*i<<endl;
	}
	cout << "size is:"<<VS.size() <<endl;
	cout << "back is:"<<VS.back() <<endl;
	cout << "capacity is:" <<VS.capacity() <<endl;
	VS[VS.size()-1] = "!!";
	cout << "last is:" << VS[2] <<endl;
	cout << "after change, back is:" <<VS.back()<<endl;
	try{
		cout << "越界访问:VS[5]" ;
		
		cout << VS[5] <<endl;
		
	}
	catch(ArrayIndexOutOfBoundsException AIBE)
	{
		cout <<"AIBE"<<endl;
	}
	
	for(Vector<int>::iterator i = VI.begin(); i!=VI.end(); ++i){
		cout<< *i <<endl;
	}
	
	cout << "comparation of VI and VI2 :" ;
	if(VI == VI2) {
		cout << "equal"<<endl;
	}
	else{
		cout<<"not equal" <<endl;
	}


	return 0;
}
