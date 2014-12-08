#include "SouvenirCatalog.h"

//default constructor
//calls default constructor for orderedMap
souvenirCatalog::souvenirCatalog() : nameIndex()
{
	//calls default constructor if ordered
}

//adds the pair to the catalog
void souvenirCatalog::add(pair<string, double> newSouvenir)
{
	//dynamically create a pair to store the passed pair
	pair<string, double> *temp = new pair<string, double>;

	//store the data into the dynamic pair
	temp->first = newSouvenir.first;
	temp->second = newSouvenir.second;

	//wrapper for orderedMap insert
	nameIndex.insert(temp->first, temp);
}

//adds the pair to the catalog
void souvenirCatalog::add(string name, double price)
{
	//dynamically create a pair to store the passed pair
	pair<string, double> *temp = new pair<string, double>;

	//store the data into the dynamic pair
	temp->first = name;
	temp->second = price;

	//wrapper for orderedMap insert
	nameIndex.insert(temp->first, temp);
}

//searched the map for the string
//if it finds it, returns the pointer to the pair
//if not returns NULL
pair<string, double>* souvenirCatalog::find(string souvenirName)
{
	return nameIndex.find(souvenirName).second;	//wrapper for search function
}

//erases the string from the catalog if it finds it
//if it is not found, does not
void souvenirCatalog::erase(string souvenirName)
{
	nameIndex.remove(souvenirName);	//wrapper of erase function
}

//returns a vector of the souvenirs in the catalog in alphabetical
// order
vector< pair<string, double>* > souvenirCatalog::getVectorCatalog()
{
	//vector that will be returned
	vector< pair<string, double>* > returnVector;

	//temp vector to store the return vector from the ordered map
	vector< pair< string, pair<string, double>* > > temp;

	//store orderd map vector into temp
	temp = nameIndex.getOrderedVector();

	//iterate through vector
	for(vector< pair< string, pair<string, double>* > >::iterator i = temp.begin(); i != temp.end(); i++)
	{
		//push the pair pointer into returnVector
		returnVector.push_back(i->second);
	}
	return returnVector;	//returnVector
}
