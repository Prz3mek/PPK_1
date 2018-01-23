#include "Projectile.h"
using namespace std;
void ClusterBomb :: Frame(ProjectileCollection& projectiles) 
{
	Projectile::Shift();
	v=v-0.2;
	licznik=licznik-1;
	if(v<0)
	{
		v=0;
		cout<<"Pocisk upad³"<<endl;
	}
	if(licznik<0)
		{
			cout<<"Granat wybucha i ropzpryskuje 4 od³amki"<<endl;
			projectiles.Remove(this);
			Projectile* pocisk = new Cluster(vector(position), vector(1,1));
			projectiles.Add(pocisk);
			Projectile* pocisk1 = new Cluster(vector(position), vector(2,1));
			projectiles.Add(pocisk1);
			Projectile* pocisk2 = new Cluster(vector(position), vector(1,2));
			projectiles.Add(pocisk2);
			Projectile* pocisk3 = new Cluster(vector(position), vector(1,3));
			projectiles.Add(pocisk3);
		}
}
void ShotgunShell :: Frame(ProjectileCollection& projectiles) 
{
	Projectile::Shift();
	v=v-10;
	if(v<0)
	{
		cout<<"Pocisk upad³"<<endl;
		projectiles.Remove(this);
	}
}
void Cluster :: Frame(ProjectileCollection& projectiles) 
{
	Projectile::Shift();
	v=v-5;
	if(v<0)
	{
		cout<<"Od³amek upad³"<<endl;
		projectiles.Remove(this);
	}
}