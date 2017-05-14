#include <iostream>
//#include "stdafx.h"
//#include "Grid.h"
//#include "Rute.h"
#include "Tboard.h"
Tboard func(Tboard);
int main() {
	
	std::cout << "Tboard tb(3)\n";
	Tboard tb(3);
	
	
	//tb.fill();
	if(tb.isEmptyBoard()) std::cout << "Empty board!\n";
	else std::cout << "Not empty board!\n";
	std::cout << "std::cout << tb;\n";
	Tboard tb2{tb};
	std::cout << tb << std::endl;
	tb.set_val(0, 0, Rute_verdi::Kryss);
	tb.set_val(1, 1, Rute_verdi::Kryss);
	tb.set_val(2, 2, Rute_verdi::Kryss);
	if(tb.isEmptyBoard()) std::cout << "Empty board!\n";
	else std::cout << "Not empty board!\n";
	std::cout << tb << std::endl;
	std::cout << tb2 << std::endl;
	Tboard tbb = func(std::move(tb));
	std::cout << "tb = func()\n" << tbb << std::endl;
	
	return 0;

}

Tboard func(Tboard tt) {
	//Tboard t(3);
	tt.set_val(2, 0, Rute_verdi::Sirkel);
	tt.set_val(1, 1, Rute_verdi::Sirkel);
	tt.set_val(0, 2, Rute_verdi::Sirkel);
	return std::move(tt);
	
}

