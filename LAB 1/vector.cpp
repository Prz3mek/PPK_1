#include <math.h>
#include <iostream>
#include "vector.h"


using namespace std;

vector::vector(float xx, float yy, float zz) : x(xx), y(yy), z(zz){};
vector::vector(const vector& m) : x(m.x), y(m.y), z(m.z){};
void vector::print()
{
	cout <<"u=("<< x << "," << y << "," << z <<")"<< endl;

};
float vector::module()
{
	return sqrt(x*x+y*y+z*z);
};
void add(const vector& a,const vector& b, vector& c)
{
	c.setX(a.getX()+b.getX());
	c.setY(a.getY()+b.getY());
	c.setZ(a.getZ()+b.getZ());
	
};
float dot(const vector& a,const vector& b)
{
	float c=a.getX()*b.getX() + a.getY()*b.getY() + a.getZ()*b.getZ();
	return c;
	
};
void cross(const vector& a,const vector& b, vector& c)
{
	c.setX(a.getY()*b.getZ()-a.getZ()*b.getY());
	c.setY(-(a.getX()*b.getZ()-a.getZ()*b.getX()));
	c.setZ(a.getX()*b.getY()-a.getY()*b.getX());
	
};
void add(vector& a, float c)
{
	a.setX(a.getX()+c);
	a.setY(a.getY()+c);
	a.setZ(a.getZ()+c);

}
