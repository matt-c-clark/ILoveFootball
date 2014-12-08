
#ifndef TEAM_H_
#define TEAM_H_
#include "Stadium.h"
using namespace std;
class team
{
public:
	team();
		//default constructor
		//name is set to "Not Set
		//AFC set to true
		//stadium will point to NULL

	team(string name, bool AFC, stadium teamsStadium);
		//non-defalut constructor
		//fields set equal to passed parameters

	string getName();
		//returns the name

	stadium getStadium();
		//returns the stadium

	void setName(string name);
		//sets name eual to passed parameter

	void setStadium(stadium newStadium);
		//sets stadium to the new passed parameter

	bool isAFC();
		//returns true if the stadium is part of the afc

private:
	string name;			//name of the team
	stadium teamsStadium;	//pointer to stadium the team is a part of
	bool AFC;				//bool to determine if team is part of AFC or NFC
};



#endif /* TEAM_H_ */
