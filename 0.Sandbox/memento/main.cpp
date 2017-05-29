#include "Notes.h"

int main(void) {
	Article a1("01", "Article 1", "Hello les amis !");	
	Tache t1("02", "Tache 1", "Faire à manger", 5);
	
	Version *va1 = a1.creerVersion(1);

	a1.afficher();
	std::cout << std::endl;

	a1.setTitre("Article 2");

	Version *va2 = a1.creerVersion(2);

	a1.afficher();
	std::cout << std::endl;

	a1.restaurerVersion(va1);

	a1.afficher();
	std::cout << std::endl;

	a1.restaurerVersion(va2);

	a1.afficher();
	std::cout << std::endl;
	return 0;
}
