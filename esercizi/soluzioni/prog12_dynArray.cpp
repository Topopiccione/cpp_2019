#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

int main(int argc, char **argv) {

   // Riempire e stampare array con numeri generati casualmente
   // usare "rand() % 101" (per questo #include di stdlib)
   // oppure usare <random> http://www.cplusplus.com/reference/random/

	int n;
	
	if (argc > 1) {
		std::string str( argv[1] );
		n = std::stoi( str );
	} else {
		std::cout << "Inserisci n: ";
		std::cin >> n;
	}
	
	int * vettore = new int[n];
	for (int i = 0; i < n; i++)
		vettore[i] = rand() % 101;
	
	int maxN = vettore[0];
	int minN = vettore[0];
	
	for (int i = 0; i < n; i++) {
		if (vettore[i] > maxN)
			maxN = vettore[i];
		if (vettore[i] < minN)
			minN = vettore[i];
		std::cout << vettore[i] << " ";
	}
	
	std::cout << std::endl;
	
    std::cout << "Min: " << minN << " Max: " << maxN << std::endl;
	
	delete[] vettore;
}