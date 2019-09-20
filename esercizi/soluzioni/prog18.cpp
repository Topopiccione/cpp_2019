#include <iostream>
#include <vector>
#include <algorithm>

bool okQuadratoMagico( const std::vector<int> qm ) {
	int diag1 = qm[0] + qm[4] + qm[8];
	int sommaRiferim = diag1;
	int diag2 = qm[2] + qm[4] + qm[6];
	if ( diag2 != sommaRiferim )
		return false;
	
	for (int i = 0; i < 3; i++) {
		int sommaRighe = 0;
		int sommaColonne = 0;
		for (int j = 0; j < 3; j++) {
			sommaRighe += qm[i * 3 + j];
			sommaColonne += qm[j * 3 + i];
		}
		if ((sommaRighe != sommaRiferim) || (sommaColonne != sommaRiferim))
			return false;
	}
	return true;
}

void stampaQuadrato( const std::vector<int> qm ) {
	for( int i = 0; i < 3; i++ ) {
		for (int j = 0; j < 3; j++) {
			std::cout << qm[i * 3 + j] << " ";
		}
		std::cout << std::endl;
	}
}


int main() {
	// Combinazione di partenza:
	std::vector<int> candidato{1, 2, 3, 4, 5, 6, 7, 8, 9};
	// Oppure...
	// std::vector<int> candidato;
	// for (int i = 1; i <= 9; i++)
	//  	candidato.push_back(i);*/
	
	while (true) {
		if (okQuadratoMagico( candidato )) {
			std::cout << "Trovata una soluzione!" << std::endl;
			stampaQuadrato( candidato );
		}
		
		bool ancora = std::next_permutation( candidato.begin(), candidato.end() );
		if (!ancora) break;
	}

  return 0;
}

	