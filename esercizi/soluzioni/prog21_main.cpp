#include <iostream>
#include "prog21_vocabolario.h"

int main(void) {
	Vocabolario vvv("parole.txt");
	
	for (int i = 0; i < 10; i++)
		std::cout << vvv.getRandomWord() << std::endl;
	
	return 0;
}