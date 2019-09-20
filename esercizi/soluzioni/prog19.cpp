#include <iostream>
#include <map>
#include <string>
#include <iomanip>

int main( void ) {
	std::map<int, std::string> contenuti;
	contenuti[1]   = "Introduzione";
	contenuti[35]  = "Capitolo 1: Ripasso C";
	contenuti[42]  = "Capitolo 2: Stream";
	contenuti[77]  = "Capitolo 3: STL: Containers";
	contenuti[91]  = "Capitolo 4: STL: Iterators";
	contenuti[127] = "Capitolo 5: STL: Algorithm";
	contenuti[154] = "Capitolo 6: Classi e costruttori";
	
	// std::cout.width( 45 );
	// std::cout << std::left << std::setfill( '.' ) << "Ehilà!";

	for (auto it = contenuti.begin(); it != contenuti.end(); it++) {
		std::cout.width( 60 );
		std::cout << std::left << std::setfill( '.' ) << it->second;
		std::cout.width( 5 );
		std::cout << std::right << std::setfill( ' ' ) << it->first;
		std::cout << std::endl;
	}

	return 0;
}