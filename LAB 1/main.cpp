#include <iostream>
#include "vector.h"
#include "MyString.h"


using namespace std;

int main(void)
{
	vector d1(1,2,3);
	vector d2(4,5,6), d3;

	
	float c=dot(d1,d2);
	cout<<c<<endl;
	cross(d1,d2,d3);
	d3.print();
	d1.print();
	add(d1,dot(d1,d2));
	d1.print();
	MyString abc(5,'a');
	abc.print();
	MyString cba(abc);
	cba.print();
	

}