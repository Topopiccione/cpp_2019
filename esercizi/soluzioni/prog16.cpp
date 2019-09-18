#include <iostream>
#include <string>

int main( void ) {
	std::string str("Vuoi un altro tipo di colazione?");
	std::cout << std::hex;
	
	for ( int i = 0; i < str.size(); i++ )
		std::cout << (int)str[i] << " ";

	return 0;
}