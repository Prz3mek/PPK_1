#include <cmath>
#include <iostream>
#include "class.h"
#include <fstream>

using namespace std;
using namespace data_structures;
int main(void)
{
	SortedList<int> Lista;
	cout<<Lista.getCount()<<endl;
	Lista.add(2);
	cout << Lista.getCount()<<endl;
	Lista.add(4);
	cout << Lista.getCount()<<endl;
	Lista.add(1);
	
	cout << Lista.getCount() << endl;
	if (Lista.find(4) == nullptr)
	{
		cout << "10" << endl;
	}
	else
	{
		cout << "11" << endl;
	}
	Lista.save(cout);
	Lista.clear();
	Lista.load(cin);
	cout << endl<< Lista.getCount() << endl;
	//SortedList<string> Listas;
	//Listas.add("Belgia"); 
	//Listas.add("Afryka");
	//Listas.add("algorytm");
	//Listas.add("bisekcja");
	//Listas.save(cout);
	//system("pause");
}