
#include "Rute.h"

class Players {
	
		Rute_verdi rute_verdi;
		bool isComputer;
		sendKoordsFromPlayer(int, int);
	public:
		Players(bool comp, Rute_verdi rv): isComputer{comp}, rute_verdi{rv} {}
		virtual std::pair<int, int> getKoordsFromPlayer();
			
	
	
};
