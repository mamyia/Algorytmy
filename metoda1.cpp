#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std;

int main(){
	srand(time(NULL));
    int rozmiar;
    rozmiar = 1000000000;
    int *Tliczb = new int [ rozmiar];
	int naj = 0;
	int druganaj = 0;

    for ( int i = 0 ; i < rozmiar ; i++)
    {
        Tliczb[i] = rand()% 3200 + 1;
    }


    auto t1 = std::chrono::high_resolution_clock::now();
	for(int i = 0; i < rozmiar; i++){
		if(naj < Tliczb[i])
			naj = Tliczb[i];
	}
	for(int i = 0; i < rozmiar; i++){
		if(naj != Tliczb[i] && druganaj < Tliczb[i])
			druganaj = Tliczb[i];
	}
	auto t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = t2 - t1;
	cout << "Najwieksza to: " << naj << " Druga najwieksza to: " << druganaj << endl;
	cout << "Czas wykonywania metody/algorytmu to: " << elapsed.count() << " s" << endl;
	system("pause");
	return 0;
}
