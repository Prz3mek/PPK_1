#ifndef MYSTRING_H
#define MYSTRING_H
using namespace std;
class MyString
{
private:
	int size;
	char* x;
public:
	MyString(int dlugosc, char znak);
	MyString(const MyString& other);
	~MyString();
	void print();
	
};

#endif