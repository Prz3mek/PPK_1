#ifndef _BATTLEFIELDSIMULATION_H
#define _BATTLEFIELDSIMULATION_H
#include "Simulation.h"

class BattlefieldSimulation : public Simulation
{
protected:
		//wywolywane w kazdej klatce symulacji
	void Frame()
	{
	
	}
	//Inicjalizacja gry - tutaj umieszczenie pociskow w symulacji
	void Init()
	{
	projectiles.Add(new ClusterBomb(vector(0, 0), vector(1, 1)));
	projectiles.Add(new ShotgunShell(vector(-10, -20), vector(-10, -5)));
	}
	
};

#endif