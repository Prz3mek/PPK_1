#include "Class.h"
#include <vector>
using namespace std;

int main(void)
{
	//Zadanie 1, 2, 3, 4
	Triangle T(3);
	Circle C(4);
	Rectangle R(5,5);
	cout<<T.toString()<<endl;
	cout<<C.toString()<<endl;
	cout<<R.toString()<<endl;

	cout << endl;
	//zadanie 5

	string s = "triangle 2.4";
	auto Figure = GeometryFactory::create(s);
	cout << Figure->toString() << endl;

	cout << endl;
	//zadanie 6

	s = "FileIn.txt";
	UniqueGeometryList Lista(s);
	for (auto a=Lista.UniquePointerList.begin();a!=Lista.UniquePointerList.end();a++)
	{
		cout << a->get()->toString()<<endl;
	}

	cout << endl;
	//zadanie 7

	GeometrySet Drzewo(std::move(Lista));
	for (auto a = Drzewo.SharePointerSet.begin(); a != Drzewo.SharePointerSet.end(); a++)
	{
		cout << a->get()->toString() << endl;
	}

	cout << endl;
	//zadanie 8

	vector<std::weak_ptr<Geometry>> Tab;
	int i = 0;
	for (auto a = Drzewo.SharePointerSet.begin(); a != Drzewo.SharePointerSet.end(); a++)
	{
		Tab.emplace_back(*a);
	}
	cout <<endl<< endl;
	auto a = Drzewo.SharePointerSet.begin();
	a++;
	Drzewo.SharePointerSet.erase(a);
	for (auto a = Tab.begin(); a != Tab.end(); a++)
	{
		if (shared_ptr<Geometry> b = a->lock())
		{
			cout << b->toString() << endl;
		}
		else
		{
			cout << "error" << endl;
		}
	}
	system("pause");
}