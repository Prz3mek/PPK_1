#include <iostream>
#include <conio.h>
#include "BattlefieldSimulation.h"
#include "vector.h"
#include <ctime>
#include <cstdlib>
using namespace std;

int main(int argc, char**argv)
{
	vector a(1,1),b(2,2);
	vector a1(1,1),b1(2,2);
	vector a2(1,1),b2(2,2);
	ClusterBomb jeden(a,b);
	Cluster dwa(a1,b1);
	ShotgunShell trzy(a2,b2);
	setlocale(LC_ALL, "Polish");
	srand(time(NULL));
	Simulation* sim = new BattlefieldSimulation;
	sim->Run();
	delete sim;
	return 0;
}