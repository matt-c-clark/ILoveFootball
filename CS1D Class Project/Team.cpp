#include "Team.h"

//default constructor
//name is set to "Not Set
//AFC set to true
//stadium will point to NULL
team::team() : teamsStadium()
{
	//name set to "Not Set"
	name = "Not Set";

	//AFC set to true
	AFC = true;

}

//non-defalut constructor
//fields set equal to passed parameters
team::team(string name, bool AfC, stadium teamsStadium)
{
	this->name = name;
	this->teamsStadium = teamsStadium;
	this->AFC = AFC;
}

//returns the name
string team::getName()
{
	return name;	//returns name as string
}


//returns the stadium
stadium team::getStadium()
{
	return teamsStadium;	//returns stadium object
}

//sets name eual to passed parameter
void team::setName(string name)
{
	this->name = name;	//field set to passed parameter
}

//sets stadium to the new passed parameter
void team::setStadium(stadium newStadium)
{
	this->teamsStadium = newStadium;	//field set to passed parameter
}

//returns true if the stadium is part of the afc
bool team::isAFC()
{
	return AFC;	//return boolean
}
