#include <math.h>
#include <iostream>
#include "MyString.h"


using namespace std;
MyString::MyString(int dlugosc, char znak)
{
	size=dlugosc;
	x=new char[size+1];
	
	
	for(int a=0; a<size; a++)
	{
		x[a]=znak;
	}
	x[dlugosc]=0;
};
MyString::MyString(const MyString& other)
{
	size=other.size;
	x=new char[size+1];
	for(int a=0; a<=size; a++)
	{
		x[a]=other.x[a];
	}

};
MyString::~MyString()
{
	delete[] x;
};
void MyString::print()
{
	for(int a=0; a<size; a++)
	{
		cout <<x[a]<<" ";
	}
	cout <<endl;
}