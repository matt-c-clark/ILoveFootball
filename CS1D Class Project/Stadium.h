
#ifndef STADIUM_H_
#define STADIUM_H_

#include "Date.h"
#include <vector>

using namespace std;
class stadium
{
public:
	stadium();
		//default constructor
		//name, city are set to "Not Set"
		//has open roof
		//date is set to the beginning of time JAN 1, 1970

	stadium(string name, string city, date dateOpened, bool openRoof);
		//non-default constructor
		//passed parameters are set to the data fields

	stadium(string name, string city, int year, int month, int day, bool openRoof);
		//same as previous default constructor
		//uses day, month, year to create date object

	string getName();
		//returns the name as the stadium as a string

	string getCity();
		//returns the name as the city of the stadium as a string

	vector<string>* getTeams();
		//returns pointer to a vector that has the names of the teams

	void setName(string name);
		//name is set to the passed parameter

	void setCity(string city);
		//city is set to the passed parameter

	void addTeam(string newTeam);
		//adds the newTeam to the vector of teams

	void removeTeam(string team);
		//adds the newTeam to the vector of teams

	bool hasOpenRoof();
		//returns true if the stadium has an open roof, not a retractable roof

	string toString();
		//returns the info of the stadium as a string

private:
	string name;					//name of the stadium
	string city;					//name of the city the stadium is in
	bool openRoof;				//determined if stadium has open roof
	date dateOpened;				//date the stadium was opened
	vector<string> teams;	//orderedMap of players that play at the
									// current stadium
};



#endif /* STADIUM_H_ */
