#include <iostream>
#include <string>
#include <algorithm>
#include "prog21_vocabolario.h"

bool letteraOk(const char carattereImmesso, std::vector<char> &lettereImmesse);
bool testLettera(const std::string parolaMisteriosa, const char carattereImmesso, int &caratteriMancanti, std::vector<char> &parolaCorrente);

int main(void) {
	int maxTentativi = 5;
	Vocabolario vvv("parole.txt");
	
	std::string parolaMisteriosa = vvv.getRandomWord();
	char carattereImmesso;
	int caratteriMancanti = parolaMisteriosa.size();
	std::vector<char> lettereImmesse;
	std::vector<char> parolaCorrente(parolaMisteriosa.size(), '_');	
	
	while (maxTentativi > 0) {
		std::cout << "Tentativo rimanenti:" << maxTentativi << " ";
		
		// input lettera + check
		do {
			std::string stringaImmessa;
			std::cin >> stringaImmessa;
			carattereImmesso = stringaImmessa[0];
		} while (!letteraOk(carattereImmesso, lettereImmesse));

		// test lettera + update display + update lettere usate
		if (!testLettera(parolaMisteriosa, carattereImmesso, caratteriMancanti, parolaCorrente))
			maxTentativi--;

		// Se non ci sono più caratteri da indovinare, esci dal loop
		if (caratteriMancanti == 0)
			break;
	}
	
	if (caratteriMancanti == 0)
		std::cout << "Ok, hai vinto. Ok, sei bravo. Ok, ora vai a fare altro." << std::endl;
	else {
		std::cout << "Hai rovinato tutto, come tuo solito." << std::endl;
		std::cout << "Davvero, non ho parole - a parte quella segreta, ovviamente, che era: " << parolaMisteriosa << std::endl;
	}
	
}



bool letteraOk(const char carattereImmesso, std::vector<char> &lettereImmesse) {
	if ((carattereImmesso < 'a') || (carattereImmesso > 'z')) {
		std::cout << "carattere non valido" << std::endl;
		return false;
	}
	if (std::find(lettereImmesse.begin(), lettereImmesse.end(), carattereImmesso ) != lettereImmesse.end()) {
		std::cout << "lettera già immessa" << std::endl;
		return false;
	}
	lettereImmesse.push_back(carattereImmesso);
	return true;
}


bool testLettera(const std::string parolaMisteriosa, const char carattereImmesso, int &caratteriMancanti, std::vector<char> &parolaCorrente) {
	bool letteraTrovata = false;
	for (int i = 0; i < parolaMisteriosa.size(); i++) {
		if (carattereImmesso == parolaMisteriosa[i]) {
			caratteriMancanti--;
			parolaCorrente[i] = carattereImmesso;
			letteraTrovata = true;
		}
		std::cout << parolaCorrente[i] << " ";
	}
	std::cout << std::endl;
	return letteraTrovata;
}