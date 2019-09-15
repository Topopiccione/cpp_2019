#include <iostream>

bool controlloPositivo(int n) {
    if (n <= 0) {
        std::cout << "Avevo detto positivo..." << std::endl;
        return false;
    }
    return true;
}

int main() {
    int nn = 0;
	
	std::cout << "Inserisci un numero positivo, e inseriscilo alla svelta: ";
    std::cin >> nn;

    if (!controlloPositivo(nn))
        return -1;

    for (int i = nn; i != 0; i--) {
		if ((nn % i) == 0) {
			std::cout << i << " ";
		}
    }
    std::cout << std::endl;
}
