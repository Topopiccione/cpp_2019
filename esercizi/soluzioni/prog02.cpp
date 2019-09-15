#include <iostream>
#include <string>

int main(void) {
    std::string nome;
    std::cout << "Scrivi il tuo nome" << std::endl;
    
    std::cin >> nome;
    
    std::cout << "Ciao " << nome << std::endl;
    return 0;
}
