#pragma once					// Questa direttiva di compilazione indica al compilatore di includere solo una volta le intestazioni presenti in studente.h 
#include <string>
#include <iostream>

class Studente {								// Dichiarazione della classe studente
public:											// Da questa linea in poi vengono dichiarati i membri pubblici della classe
	Studente();									// Costruttore di default
	Studente(std::string cogn, std::string nm);	// Costruttore specializzato
	
	void disp();								// fuzioni membro pubbliche
	void setScritto( int );
	void setOrale( int );
private:										// Da questa linea in poi vengono dichiarati i membri privati della classe
	std::string nome;
	std::string cognome;
	int voti[2];
	
	int media();
};