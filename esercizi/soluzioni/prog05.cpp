/* Nota: per randomizzare il seed del generatore di numeri casuali, importare
#include <time.h>
e, prima delle chiamate a rand(), eseguire una volta l'istruzione
srand( time( NULL ) );
*/

#include <iostream>
#include <stdlib.h>
constexpr int N = 10;

int main() {
    int numeri[N];

    for (int i = 0; i < N; i++) {
        numeri[i] = rand() % 101; // Genera numero casuale da 0 a 100
        std::cout << numeri[i] << " ";
    }
	std::cout << std::endl;

    int maxN = -1;
    int minN = 101;

    for (int i = 0; i < N; i++) {
        if (numeri[i] < minN) 
			minN = numeri[i];
        if (numeri[i] > maxN) 
			maxN = numeri[i];
    }

    std::cout << "Min: " << minN << " Max: " << maxN << std::endl;
}
