#include "BinaryHeap.h"
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <iostream>
using namespace std;
void wypisz(vector<int> Viktor)
{
	for (int i : Viktor)
	{
		cout << i << " ";
	}
}
void wypisz(vector<pair<int,int>> Viktor)
{
	for (auto i : Viktor)
	{
		cout << i.first << " " <<i.second<<endl;
	}
}
int main(void)
{
	//zad 1
	default_random_engine gen;
	uniform_int_distribution<int> dist(1, 10);
	vector<int> Viktor(100); 
	generate(Viktor.begin(), Viktor.end(), [&dist, &gen]()->int {return dist(gen); });
	//wypisz(Viktor);
	sort(Viktor.begin(), Viktor.end());
	auto tmp = unique(Viktor.begin(), Viktor.end());
	Viktor.erase(tmp,Viktor.end());
	//wypisz(Viktor);
	//vector nie jest posortowany
	//zad 2
	reverse(Viktor.begin(), Viktor.end());
	wypisz(Viktor);
	int x = 2;
	auto it = find(Viktor.begin(), Viktor.end(), x);
	bool b = binary_search(Viktor.begin(), Viktor.end(), x);
	bool c = binary_search(Viktor.rbegin(), Viktor.rend(), x);
	//zad 3
	poisson_distribution<int> dist2(5.0);
	vector<pair<int,int>> Vejktor(100);
	generate(Vejktor.begin(), Vejktor.end(), [&]()->pair<int, int> {return make_pair(dist2(gen), dist2(gen)); });
	//wypisz(Vejktor);
	sort(Vejktor.begin(), Vejktor.end(), [](auto a, auto b)->bool {return a.second>b.second; });
	sort(Vejktor.begin(), Vejktor.end(), [](auto a, auto b)->bool {return a.first<b.first; });
	//wypisz(Vejktor);
	stable_sort(Vejktor.begin(), Vejktor.end(), [](auto a, auto b)->bool {return a.second>b.second; });
	stable_sort(Vejktor.begin(), Vejktor.end(), [](auto a, auto b)->bool {return a.first<b.first; });
	//wypisz(Vejktor);

	//stable_sort zachowuje wzglêdna kolejnoœæ równych elementów przy sortowaniu
	
	//zad 4
	vector<int> Wektor;
	auto lambda = [](auto a, auto b)->bool {return abs(a) < abs(b); };
	BinaryHeap<int, decltype(lambda)> Kopiec(std::move(Wektor), lambda);
	Kopiec.Add(22);
	Kopiec.Add(23);
	Kopiec.Add(21);
	Kopiec.Add(3);
	Kopiec.Add(-5);
	while(!Kopiec.IsEmpty())
	{
		auto a=Kopiec.DeleteFormHeap();
	}
	system("pause");
}