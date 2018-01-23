#ifndef _VECTOR_H
#define _VECTOR_H
#include "math.h"
#include <iostream>
using namespace std;
class vector
{
protected:
	double x,y;
public:
	//vector(): x(0),y(0){}
	void setX(double xx)
	{
		x=xx;
	}
	void setY(double yy)
	{
		y=yy;
	}
	double getX()
	{
		return x;
	}
	double getY()
	{
		return y;
	}
	
	vector(double x, double y): x(x),y(y){}
	vector(vector& b)
	{
		x=b.getX();
		y=b.getY();
	}
	void show()
	{
		cout<<x<<" "<<y<<endl;
	}
	vector& operator=(const vector& b) 
	{
		x=b.x;
		y=b.y;
		return *this;
	}
	vector operator*(const double& b) 
	{
		vector c(0,0);
		c.x=x*b;
		c.y=y*b;
		return c;
	}
	vector& operator+=(const vector& b) 
	{
		x=x+b.x;
		y=y+b.y;
		return *this;
	}
	vector& operator--() 
	{
		x -= 1;
		y -= 1;
		return *this;
	}
	vector operator--(int) 
	{
		vector copy(*this);
		x -= 1;
		y -= 1;
		return copy;
	}
	void normalize() 
	{
		double xx=x, yy=y;

		x=x/sqrt(xx*xx+yy*yy);
		y=y/sqrt(xx*xx+yy*yy);
	}
	double& operator[](int i) {
	if (i == 0) 
	{
		return x; 
	}
	else 
	{
		return y; 
	}

}

};
#endif