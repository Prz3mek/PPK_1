#ifndef _PROJECTILE_COLLECTION_H
#define _PROJECTILE_COLLECTION_H
#include <set>
#include "Projectile.h"
class Projectile;
class ProjectileCollection
{
	std::set<Projectile*> projectiles, to_remove, to_add;
	void free_set_mem(std::set<Projectile*>& _data);
public:

	//////////////////////////////////////////////////////////////////////////
	//Przekazywane tutaj objekty musz� by� zaalokowane przez new!
	//Dodaje nowy pocisk do kolekcji
	//////////////////////////////////////////////////////////////////////////
	void Add(Projectile* projectile);

	//////////////////////////////////////////////////////////////////////////
	//Usuwa pocisk z kolekcji
	//Zapewnia r�wnie� zwolnienie zaalokowanej Pami�ci!
	//////////////////////////////////////////////////////////////////////////
	void Remove(Projectile* projectile);


	//////////////////////////////////////////////////////////////////////////
	//Dla ka�dego dodanego objektu wywo�uje metod� Frame
	//////////////////////////////////////////////////////////////////////////
	void FrameAll();


	//////////////////////////////////////////////////////////////////////////
	//Dla ka�dego dodanego objektu wywo�uje metod� Display
	//////////////////////////////////////////////////////////////////////////
	void DisplayAll();

	void Commit();
	~ProjectileCollection();
};

#endif