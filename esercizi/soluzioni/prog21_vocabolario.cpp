#include "prog21_vocabolario.h"

Vocabolario::Vocabolario( std::string filename ): fileNm( filename ) {
	std::ifstream fin(fileNm, std::ios::in);
	std::string tempWord;
	
	// leggi fin fino alla fine del file e voc.push_back di ogni parola nel container
	while (!fin.eof()) {
		fin >> tempWord;
		voc.push_back(tempWord);
	}
	std::cout << "Lette " << voc.size() << " parole." << std::endl;
	
	// inizializza il seed del generatore random
	srand(time(NULL));
}

Vocabolario::~Vocabolario() {
	// Chiudi fin
	fin.close();
}
		
std::string Vocabolario::getRandomWord() {
	// return di un elemento a caso di diz
	int numeroRandom = rand() % voc.size();
	return voc[numeroRandom];
}