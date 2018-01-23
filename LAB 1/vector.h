#ifndef VECTOR_H
#define VECTOR_H
using namespace std;
class vector
{
private:
	float x, y, z;
public:

	float inline getX() const { return x; }
	void inline setX(float x) { this->x = x; }
	float inline getY() const { return y; }
	void inline setY(float y) { this->y = y; }	float inline getZ() const { return z; }
	void inline setZ(float z) { this->z = z; }	inline vector() : x(0), y(0), z(0){};
	vector(float xx, float yy, float zz);
	vector(const vector& m);
	void print();
	float module();

};

void add(const vector& a,const vector& b, vector& c);
float dot(const vector& a,const vector& b);
void cross(const vector& a,const vector& b, vector& c);
void add(vector& a, float c);



#endif