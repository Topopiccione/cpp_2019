#include <iostream>
#include <iomanip>	// stream manipulators - solo per std::setprecision()
#include <cmath>	// per la funzione sqrt()

int main(void) {
	double laradice = sqrt(18.24);
	
	std::cout << std::fixed;

	// con precision()
	for (int i = 0; i < 11; i++) {
		std::cout.precision(i);
		std::cout << laradice << std::endl;
	}

	// con setprecision()
	for (int i = 0; i < 11; i++) {
		std::cout << std::setprecision(i) << laradice << std::endl ;
	}
}