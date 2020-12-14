#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std;

int dzielimy(int tablica[], int p, int r){
	int x = tablica[p];
	int i = p;
	int j = r;
	int w;
	while (true)
	{
		while (tablica[j] > x)
			j--;
		while (tablica[i] < x)
			i++;
		if (i < j){
			w = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = w;
			i++;
			j--;
		}
		else
			return j;
	}
}

void sortowanie(int tablica[], int p, int r) {
	int q;
	if (p < r){
		q = dzielimy(tablica,p,r);
		sortowanie(tablica, p, q);
		sortowanie(tablica, q+1, r);
	}
}

int main(){
	int rozmiar;
	rozmiar = 100000000;
	int i;
	cout << "Podaj ilosc licz do posortowania: ";
	int *Tliczb = new int [rozmiar];

	for (i = 0; i < rozmiar; i++)
		Tliczb[i] = rand() % 3200 + 1;

	auto t1 = std::chrono::high_resolution_clock::now();
	sortowanie(Tliczb,0,rozmiar-1);


	auto t2 = std::chrono::high_resolution_clock::now();
	int naj = Tliczb[rozmiar - 1];
	int druganaj = Tliczb[rozmiar - 2];
	std::chrono::duration<double> elapsed = t2 - t1;
	cout << "Najwieksza to: " << naj << " Druga najwieksza to: " << druganaj << endl;
	cout << "Czas wykonywania metody/algorytmu to: " << elapsed.count() << " s" << endl;
	delete [] Tliczb;
return 0;
}
