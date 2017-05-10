#include "Grid.h"
#include "Rute.h"

class Tboard: public Grid<Rute> {
	
	public:
		Tboard(int sz) : Grid(sz) {}
		~Tboard() { //std::cout << "Tboard::~Tboard()\n"; 
		}
		Rute_verdi set_val(int x, int y, Rute_verdi rv);
		Rute_verdi get_val(int x, int y);
};

Rute_verdi Tboard::set_val(int x, int y, Rute_verdi rv) {
	Rute ru = getElement(x, y);
	std::cout << "ru = " << ru << std::endl;
	Rute temp{ru};
	ru.set_val(rv);
	setElement(x, y, ru);
	std::cout << "ru = " << ru << std::endl;
	return temp.int_val();
	
}

Rute_verdi Tboard::get_val(int x, int y) {
	Rute ru = getElement(x, y);
	return ru.int_val();
	
}
