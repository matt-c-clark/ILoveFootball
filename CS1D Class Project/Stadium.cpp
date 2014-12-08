#include "Stadium.h"

//default constructor
		//name, city are set to "Not Set"
		//has open roof
		//date is set to the beginning of time JAN 1, 1970
stadium::stadium() : dateOpened(), teams()
{
	//set string to "Not Set
	name = "Not Set";
	city = "Not Set";

	//openRoof set to true
	openRoof = true;
}

//non-default constructor
//passed parameters are set to the data fields
stadium::stadium(string name, string city, date dateOpened, bool openRoof)
{
	//set fields to passed parameter
	this->name = name;
	this->city = city;
	this->openRoof = openRoof;

	//use passed date object to initialize dateOPened
	this->dateOpened.setDate(dateOpened.getDay(),dateOpened.getMonth(), dateOpened.getYear());
}


//same as previous default constructor
//uses day, month, year to create date object
stadium::stadium(string name, string city, int year, int month, int day, bool openRoof)
{
	//set fields to passed parameter
	this->name = name;
	this->city = city;
	this->openRoof = openRoof;

	//use passed date components to initialize dateOPened
	this->dateOpened.setDate(day, Month(month), year);

}

//returns the name as the stadium as a string
string stadium::getName()
{
	return name;	//returns name field
}

//returns the name as the city of the stadium as a string
string stadium::getCity()
{
	return city;	//return city field
}

//returns pointer to a vector that has the names of the teams
vector<string>*stadium::getTeams()
{
	//pointer that will be returned
	vector<string> *temp;

	temp = &teams;	//point to the address of the vector

	return temp;	//return pointer
}


//name is set to the passed parameter
void stadium::setName(string name)
{
	this->name = name;	//set name equal to passed parameter
}

//city is set to the passed parameter
void stadium::setCity(string city)
{
	this->city =  city;	//set name equal to passed parameter
}

//adds the newTeam to the vector of teams
void stadium::addTeam(string newTeam)
{
	//push string to the teams vector
	teams.push_back(newTeam);
}

//adds the newTeam to the vector of teams
void stadium::removeTeam(string team)
{
	//iterate through vector searching for team
	for(vector<string>::iterator i = teams.begin(); i != teams.end(); i++)
	{
		//if team found remove it
		if(*i == team)
		{
			teams.erase(i);	//remove team
		}
	}
}


//returns true if the stadium has an open roof, not a retractable roof
bool stadium::hasOpenRoof()
{
	return openRoof;	//returns boolean
}

//returns the info of the stadium as a string
string stadium::toString()
{
	//string that will be returned
	string returnString;

	//add data fields to the string
	returnString += city;
	returnString += "\n";
	returnString += name;
	returnString += "\nDate Opened: ";
	returnString += dateOpened.toString();
	returnString += "\n";

	return returnString;	//return the string
}
