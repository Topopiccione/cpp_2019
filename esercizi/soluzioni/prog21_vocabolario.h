#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>

class Vocabolario {
public:
	Vocabolario(std::string filename);	// costruttore pubblico, prende il nome file come parametro
	~Vocabolario();						// distruttore pubblico
	std::string getRandomWord();		// funzione che restituisce una parola a caso, tra quelle presenti in elenco

private:
	std::string fileNm;					// nome del file
	std::fstream fin;					// oggetto fstream: è il file da cui prelevare le parole
	std::vector<std::string> voc;		// container per le parole; io ho usato vector, ma quale potrebbe essere più appropriato?
};