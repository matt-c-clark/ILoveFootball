
#ifndef SOUVENIR_H_
#define SOUVENIR_H_

#include "SouvenirCatalog.h"
#include "Team.h"
using namespace std;

class souvenir
{
public:
	souvenir();
		//default constructor
		//name is set to "Not Set"
		//price is set to 0.00
		//catalog set to NULL

	souvenir(string name, team souvenirTeam, souvenirCatalog & catalog);
		//non-defalut constructor
		//data fileds are set to the passd parameters

	string getName();
		//returns name of the souvenir as a string

	double getPrice();
		//returns price as a double

	team getTeam();
		//returns copy of the team object

	void setName(string name);
		//name is set to passed string

	void setTeam(team newTeam);
		//sets team equal to passed team object

	void updatePrice();
		//re initializes the price from the catalog

private:
	string name;				//name of the souvenir
	double* price;				//price of the souvenir
	team souvenirTeam;			//team the souvenir is from
	souvenirCatalog* catalog;	//pointer to the catalog the souvenir belongs
								// to
};



#endif /* SOUVENIR_H_ */
