#ifndef _PROJECTILE_H
#define _PROJECTILE_H
#include "ProjectileCollection.h"
#include "vector.h"
#include <iostream>
using namespace std;
class ProjectileCollection;
class Projectile
{
protected:
	vector position;
	vector direction;
	double v;
	char* name;
public:
	//vector(double x, double y): x(x),y(y){}
	Projectile(vector a, vector d, double b, char* c): position(a),direction(d), v(b)
	{
		direction.normalize();
		name = new char[strlen(c)+1];
		//strncpy(name, c, strlen(c) + 1);
		for (int i = 0; i < strlen(c) + 1; i++)
		{
			name[i] = c[i];
		}
	}
	virtual ~Projectile()
	{
		delete[] name;
	}
	virtual void Display()
	{
		cout << position.getX() <<" "<< position.getY() << " " <<direction.getX() <<" "<< direction.getY() << " " << v <<endl;
	}
	//
	virtual void Frame(ProjectileCollection& projectiles) = 0;
	void Shift()
	{
		position+=direction*v;
	}
};
class ClusterBomb : public Projectile
{
	int licznik;
public:
	ClusterBomb(vector a, vector d): Projectile(a,d,2,"jeden"), licznik(5){}
	 void Frame(ProjectileCollection& projectiles) ;
	void Display()
	{
		cout << name<<endl;
		Projectile::Display();
	}
};
class ShotgunShell : public Projectile
{
	public:
	ShotgunShell(vector a, vector d): Projectile(a,d,50,"dwa"){}
	void Frame(ProjectileCollection& projectiles) ;
	void Display()
	{
		cout << name<<endl;
		Projectile::Display();
	}
};
class Cluster : public Projectile
{
	public:
	Cluster(vector a, vector d): Projectile(a,d,100,"trzy"){}
	void Frame(ProjectileCollection& projectiles) ;
	void Display()
	{
		cout << name<<endl;
		Projectile::Display();
	}
};
#endif