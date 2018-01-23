#pragma once
#include <vector>
template <class T, class Comp>

class BinaryHeap
{
public:
	std::vector<T> Wektor;
	Comp Comparator;
	BinaryHeap(std::vector<T>&& Data, const Comp& Comparator) : Wektor(std::move(Wektor)), Comparator(Comparator) 
	{
		std::make_heap(Wektor.begin(), Wektor.end(), Comparator);
	};
	void Add(const T& a)
	{
		Wektor.push_back(a);
		std::push_heap(Wektor.begin(), Wektor.end(),Comparator);
	}
	const T& Download()
	{
		return Wektor.front();
	}
	auto DeleteFormHeap()
	{
		auto a = (Wektor.end()-1);
		std::pop_heap(Wektor.begin(), Wektor.end(), Comparator);
		Wektor.pop_back();
		return a;
	}
	bool IsEmpty()
	{
		return Wektor.begin() == Wektor.end();
	}
	/*void ShowHeap()
	{
		for(auto x : Wektor)
		{
			std::cout << x << std::endl; 
		};
	}*/
};
