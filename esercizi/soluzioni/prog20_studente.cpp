#include "prog20_studente.h"

Studente::Studente(std::string cogn, std::string nm) :
	cognome{cogn}, nome{nm} 	// Lista di inizializzazione dei membri della classe
{
	voti[0] = 0;
	voti[1] = 0;
}

Studente::Studente() :
	cognome{""}, nome{""} 		// Lista di inizializzazione dei membri della classe
{
	voti[0] = 0;
	voti[1] = 0;
}

int Studente::media() {
	return (voti[0] + voti[1]) / 2;
}

void Studente::disp() {
	std::cout << "Nome: " << nome << " Cognome: " << cognome << " Media dei voti: " << media() << std::endl;
}

void Studente::setScritto(int voto) {
	if ((voto >= 0) && ( voto <= 30))
		voti[0] = voto;
	else
		std::cout << "Voto non valido!" << std::endl;
}

void Studente::setOrale(int voto) {
	if ((voto >= 0) && (voto <= 30))
		voti[1] = voto;
	else
		std::cout << "Voto non valido!" << std::endl;
}


	