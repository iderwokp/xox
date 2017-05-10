#pragma once
#include <iostream>
#include <ostream>
#include <string>
#include <map>

enum class Rute_verdi {
	Kryss, Sirkel, Blank
};

class Rute {

	Rute_verdi mInt_val;
	//std::string mStr_val;
	  std::map<Rute_verdi, std::string> Val{ { Rute_verdi::Kryss, "X" },{ Rute_verdi::Blank, "." },{ Rute_verdi::Sirkel, "O" } };

public:
	Rute() : Rute(Rute_verdi::Blank) {}
	Rute(Rute_verdi rv): mInt_val { rv } {}
	~Rute() {
		//std::cout << "Rute::~Rute()\n";
	}
	std::string str_val(Rute_verdi) const ;
	Rute_verdi int_val() const { return mInt_val; }
	void set_val(Rute_verdi rv) { mInt_val = rv;}
	bool operator==(const Rute& rhs) const {
		return mInt_val == rhs.mInt_val;
	}
	bool operator!=(const Rute& rhs) const {
		return !(mInt_val == rhs.mInt_val);
	}
};

std::ostream& operator<<(std::ostream& os, Rute &rute) {
	os << rute.str_val(rute.int_val());
	return os;
}

std::string Rute::str_val(Rute_verdi rv)  const {
	return Val.at(rv); //Må bruke at() siden Val er const
}
