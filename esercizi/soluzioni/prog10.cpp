#include <fstream>
#include <string>

int main()
{
    std::ofstream fout("out.txt", std::ios::out);
    std::string str( "All work and no play makes Jack a dull boy" );
	
    for (int i = 0; i < 25472; i++)
        fout << str << std::endl;
    
	fout.close();
    
	return 0;
}
