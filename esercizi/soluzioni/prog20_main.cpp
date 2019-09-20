#include "prog20_studente.h"

int main(void) {
	Studente stud("Tizio", "Caio" );
	stud.setScritto(15);
	stud.setOrale(24);
	stud.disp();
	return 0;
}