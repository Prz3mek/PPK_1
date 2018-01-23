#ifndef ELEMENT_H
#define ELEMENT_H
#ifndef SORTEDLIST_H
#define SORTEDLIST_H
#include <string>
#include<algorithm>
namespace data_structures
{
	template <class T>
	class Element
	{
		Element<T>* Next;
		T Value;
	public:
		Element() : Next(nullptr) {};
		Element(Element<T>* arg, const T& data) : Next(arg), Value(data) {};
		inline Element<T>* GetNext()
		{
			return Next;
		}
		inline void SetNext(Element<T>* arg)
		{
			Next = arg;
		}
		inline T& operator*()
		{
			return Value;
		}
		inline T GetValue()
		{
			return Value;
		}
		inline void SetValue(const T& arg)
		{
			Value = arg;
		}
		inline bool isLower(const T& arg)
		{
			if (arg < Value)
				return true;
			else
				return false;
		}
		inline bool isEqual(const T& arg)
		{
			if (arg == Value)
				return true;
			else
				return false;
		}
	};
	//template<>
	//inline bool Element<std::string>::isLower(const std::string& arg)
	//{
	// 
	//	std::string ss = arg;// std::tolower(arg);
	//	std::transform(ss.begin(), ss.end(), ss.begin(), ::tolower);
	//	std::string s = Value;// std::tolower(arg);
	//	std::transform(s.begin(), s.end(), s.begin(), tolower);
	//	
	//	return ss < s;
	//	
	//}
	//
	//template<>
	//inline bool Element<std::string>::isEqual(const std::string& arg)
	//{
	//
	//	std::string ss = arg;// std::tolower(arg);
	//	std::transform(ss.begin(), ss.end(), ss.begin(), tolower);
	//	std::string s = Value;// std::tolower(arg);
	//	std::transform(s.begin(), s.end(), s.begin(), tolower);
	//	if (arg == Value)
	//		return true;
	//	else
	//		return false;
	//}
	template <class T>
	class SortedList
	{
	private:
		Element<T>* First;
		int Counter;
	public:
		SortedList() : First(nullptr), Counter(0) {};
		~SortedList()
		{
			clear();
		}
		inline Element<T>* getFirst() { return First; };
		inline int getCount() { return Counter; };
		inline void add(const T& arg)
		{
			if (Counter == 0)
			{
				First = new Element<T>;
				First->SetValue(arg);
				++Counter;
				return;
			}
			Element<T>* Bufor = First;
			Element<T>* BBufor = First;
			while (true)
			{

				if (Bufor->isLower(arg))
				{
					if (Bufor->GetNext() == nullptr)
					{
						Element<T>* Bufor2 = new Element<T>(nullptr, arg);
						Bufor->SetNext(Bufor2);
						++Counter;
						return;
					}
					BBufor = Bufor;
					Bufor = Bufor->GetNext();

				}

				else if (First == Bufor)
				{
					Element<T>* Bufor2 = new Element<T>(Bufor, arg);
					First = Bufor2;
					++Counter;
					return;

				}

				else
				{
					Element<T>* Bufor2 = new Element<T>(Bufor, arg);
					BBufor->SetNext(Bufor2);
					++Counter;
					return;

				}
			}
		}
		inline Element<T>* find(const T& arg)
		{
			Element<T>* Bufor = First;
			while (true)
			{
				if (Bufor->isEqual(arg))
				{
					return Bufor;
				}
				if (Bufor->GetNext() == nullptr)
				{
					return nullptr;
				}
				Bufor = Bufor->GetNext();
			}
		}
		inline void clear()
		{

			Element<T>* Bufor = First;
			Element<T>* BBufor = First;
			while (true)
			{
				if (Bufor->GetNext() == nullptr)
				{
					delete Bufor;
					--Counter;
					First = nullptr;
					return;
				}
				BBufor = Bufor;
				Bufor = Bufor->GetNext();
				delete BBufor;
				--Counter;
			}
		}
		void save(std::ostream &s)
		{
			Element<T>* Bufor = First;
			while (Bufor)
			{

				s << *(*Bufor) << " ";
				Bufor = Bufor->GetNext();
			}
		}
		inline void load(std::istream &s)
		{
			T Bufor;
			while (s >> Bufor)
			{
				add(Bufor);
			}
		}
	};
	template <class T>
	void operator<<(std::ostream &s,SortedList<T>& Lista)
	{
		Lista.save(s);
	}
	template <class T>
	void operator>>(std::istream &s,SortedList<T>& Lista)
	{
		Lista.load(s);
	}
}
#endif
#endif