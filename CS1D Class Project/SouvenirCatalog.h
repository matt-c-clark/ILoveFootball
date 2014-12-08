
#ifndef SOUVENIRCATALOG_H_
#define SOUVENIRCATALOG_H_

#include "OrderedMap.cpp"

class souvenirCatalog
{
public:
	souvenirCatalog();
		//default constructor
		//calls default constructor for orderedMap

	void add(pair<string, double> newSouvenir);
		//adds the pair to the catalog

	void add(string name, double price);
		//adds the pair to the catalog

	pair<string, double>* find(string souvenirName);
		//searched the map for the string
		//if it finds it, returns the pointer to the pair
		//if not returns NULL

	void erase(string souvenirName);
		//erases the string from the catalog if it finds it
		//if it is not found, does not

	vector< pair<string, double>* > getVectorCatalog();
		//returns a vector of the souvenirs in the catalog in alphabetical
		// order

private:
	orderedMap<string, pair<string, double>* > nameIndex;	//ordered map of
															// pairs
};

#endif /* SOUVENIRCATALOG_H_ */
