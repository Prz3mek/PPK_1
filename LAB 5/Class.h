#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <set>
#include <queue>
#include <list>
#include <sstream> 
#include <memory>
#include <functional>
class Geometry//zadanie 1
{
public:
	virtual float perimeter() = 0;
	virtual float area() = 0;
	virtual std::string toString() = 0;
	virtual ~Geometry() {}
};
class Triangle : public Geometry//zadanie 2,3,4
{
	float a;
public:
	Triangle(long A) : a(A) {};
	Triangle(const Triangle& A) : a(A.a) {};
	Triangle(Triangle&& A) : a(A.a) {};
	virtual float perimeter() { return 3 * a; }
	virtual float area() { return ((a*a*std::sqrt(3.0)) / 4); }
	virtual std::string toString()
	{
		std::string s = "Triangle a: "+ std::to_string(a) +"area: " + std::to_string(area()) + " perimeter: " + std::to_string(perimeter());
		return s;
	}

};
class Circle : public Geometry//zadanie 2,3,4
{
	float r;
public:
	Circle(long A) : r(A) {};
	Circle(const Circle& A) : r(A.r) {};
	Circle(Circle&& A) : r(A.r) {};
	virtual float perimeter() { return 2*3.14*r; }
	virtual float area() { return 3.14*r*r; }
	virtual std::string toString()
	{
		std::string s = "Triangle r: " + std::to_string(r) + " area: " + std::to_string(area()) + " perimeter: " + std::to_string(perimeter());
		return s;
	}
};
class Rectangle : public Geometry//zadanie 2,3,4
{
	float a,b;
public:
	Rectangle(long A, long B) : a(A), b(B){};
	Rectangle(const Rectangle& A) : a(A.a), b(A.b) {};
	Rectangle(Rectangle&& A) : a(A.a), b(A.b) {};
	virtual float perimeter() { return 2*a + 2*b; }
	virtual float area() { return a*b; }
	virtual std::string toString()
	{
		std::string s = "Triangle a: " + std::to_string(a) + " b: " + std::to_string(b) + " area: " + std::to_string(area()) + " perimeter: " + std::to_string(perimeter());
		return s;
	}
};
class GeometryFactory//zadanie 5
{
public:
	static Geometry* create(std::string s)
	{
		std::istringstream d(s);
		std::string name;
		float a;
		d >> name;
		d >> a;
		if (name == "circle")
		{
			return new Circle(a);
		}
		else if (name == "triangle")
		{
			return new Triangle(a);
		}
		else if (name == "rectangle")
		{
			float b;
			d >> b;
			return new Rectangle(a, b);
		}
		return nullptr;
	};
};
class UniqueGeometryList//zadanie 6
{
public:
	std::list<std::unique_ptr<Geometry>> UniquePointerList;
	UniqueGeometryList(const std::string& file_name)
	{
		std::ifstream File_in;
		File_in.open(file_name);
		if (File_in.good() == false)
		{
			std::cout << "Nie mozna otworzyc pliku " << file_name << std::endl;
			return;
		}
		std::string s;
		while (getline(File_in,s))
		{
			UniquePointerList.emplace_back(GeometryFactory::create(s));
		}
	}
};
class GeometrySet//zadanie 7
{
public:
	std::set<std::shared_ptr<Geometry>, std::function<bool(const std::shared_ptr<Geometry>&, const std::shared_ptr<Geometry>&)>> SharePointerSet;
	GeometrySet(UniqueGeometryList&& Lista) : SharePointerSet([](const  std::shared_ptr<Geometry>&a, const  std::shared_ptr<Geometry>&b)->bool
	{
		return a->area() > b->area();
	
	}) 
	{
		for (auto a = Lista.UniquePointerList.begin(); a != Lista.UniquePointerList.end(); a++)
		{
			SharePointerSet.insert(std::move(*a));
		}
	};
};