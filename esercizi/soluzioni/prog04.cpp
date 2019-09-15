#include <iostream>

bool controlloPositivo( int n ) {
    if (n < 0) {
        std::cout << "Avevo detto positivo..." << std::endl;
        return false;
    }
    return true;
}

int sommaRic( int n ) {
	if (n == 0)
		return 0;
	else
		return n + sommaRic( n - 1 );
}

int main() {
    int nn = 0;
    int res = 0;

	std::cout << "Inserisci un numero positivo, subito! ";
    std::cin >> nn;

    if (!controlloPositivo(nn))
        return -1;

    for (int i = 0; i <= nn; i++) {
        res += i;
    }
    std::cout << "res(for) = " << res << std::endl;

    res = 0;
    int count = 0;
    while (count <= nn) {
        res += count;
        count++;
    }
    std::cout << "res(while) = " << res << std::endl;

    res = 0;
    count = 0;
    do {
        res += count;
    } while ((++count) <= nn);
    std::cout << "res(do) = " << res << std::endl;
	
	std::cout << "res(ric) = " << sommaRic(nn) << std::endl;
}
