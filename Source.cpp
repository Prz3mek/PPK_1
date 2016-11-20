#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <ctime>
using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	int k, n,x,y=0;
	
	cout << "Wprowadz ilosc losowanych liczb\n";
	cin >> k;
	cout << "\nPodaj zakres losowania\n";
	cin >> n;
		cout << "\nRozpoczyna sie losowanie " << k << " liczb z zakresu od 0 do " << n << endl;
	cout << "Wylosowano: ";
	for (int i = 0; i < k; i++)
	{
		x = (rand() % n);
		if (x % 2 == 0)
		{
			cout << x << " ";
			if (x > y)
				y = x;
		}
	}
	cout << "\nNajwieksza: " << y;
	cout << "\n***********************************************************\n";

//Zad 2

	int a, b;
	cout << "\nWprowadz wysokosc\n";
	cin >> a;
	cout << "\nWprowadz szerokosc\n";
	cin >> b;
	
	for (int i = 0; i < a; i++)
	{
		
		for (int j=b-i ; j > 0; j--)
		{
			if (i % 2 == 0)
				cout << "*";
			else
				cout << "0";

		}
		cout << endl;
	}
	cout << "\n***********************************************************\n";

		//Zad3
		srand((unsigned)time(NULL));
		int q, w, e, r = 0,u=0;
		double t = 0;
		const int K = 1000;
		cout << "Wprowadz ilosc losowanych liczb\n";
		cin >> q;
		cout << "\nPodaj zakres losowania\n";
		cin >> w;
		if (w > K)
			w = K;
		int * tab = new int[q];
		cout << "\nRozpoczyna sie losowanie " << q << " liczb z zakresu od 0 do " << w << endl;
		cout << "Wylosowano: ";
		for (int i = 0; i < q; i++)
		{
			e = (rand() % w);
			tab[i] = e;
			if (e % 2 == 0)
			{
				cout << e << " ";
				if (e > r)
					r = e;
			}
		}
		cout << "\nNajwieksza: " << r;
		
		for (int i = 0; i < q; i++)
		{
			t = t + tab[i];
			if (u > tab[i])
				u = tab[i];

		}
		cout << "\nSrednia = " << t / q<<endl;
		cout << "minimalna = " << u;
		cout << "\n***********************************************************\n";




	system("pause");
}
