#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream fin("out.txt", std::ios::in);
    std::string word;
    int count = 0;
    fin >> word;
	
    while(!fin.eof()) {
        fin >> word;
          count++;
    }
	
    std::cout << "Numero di parole nel file out.txt: " << count << std::endl;
    
	fin.close();
	
	return 0;
}