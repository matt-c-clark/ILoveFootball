#include "Souvenir.h"

//default constructor
//name is set to "Not Set"
//price is set to NULL
//catalog set to NULL
souvenir::souvenir()
{
	//set name to "Not Set
	name = "Not Set";

	//price set to 0
	price = NULL;

	//catalog will point to NULL
	catalog = NULL;
}

//non-defalut constructor
//data fileds are set to the passd parameters
souvenir::souvenir(string name, team souvenirTeam, souvenirCatalog & catalog)
{
	//set fields equal to passed parameters
	this->name = name;
	this->souvenirTeam = souvenirTeam;
	this->catalog = &catalog;

	//search for name if souvenir in souvenirCatlog for price
	//point price to the souvenir
	//initializes the price
	updatePrice();
}

//returns name of the souvenir as a string
string souvenir::getName()
{
	return name;	//returns name string
}

//returns price as a double
double souvenir::getPrice()
{
	return *price;	//returns price double
}

//returns copy of the team object
team souvenir::getTeam()
{
	return souvenirTeam;	//return souvenirTeam team object
}

//name is set to passed string
void souvenir::setName(string name)
{
	this->name = name;	//name is set to passed parameter
}

//sets team equal to passed team object
void souvenir::setTeam(team newTeam)
{
	souvenirTeam = newTeam;	////team is set to passed parameter
}

//re initializes the price from the catalog
void souvenir::updatePrice()
{
	//search for name if souvenir in souvenirCatlog for price
	//point price to the souvenir
	price = &(catalog->find(name)->second);
}
