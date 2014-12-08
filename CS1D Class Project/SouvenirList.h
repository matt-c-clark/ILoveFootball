
#ifndef SOUVENIRLIST_H_
#define SOUVENIRLIST_H_

#include "Souvenir.h"

class souvenirList
{
public:
	souvenirList();
		//defalut constructor
		//calls default constructor for both ordered map

	void add(souvenir newSouvenir);
		//adds the souvenir to both orderedMap

	void remove(string souvenirName);
		//removes the souvenir with the given name from both souvenirs maps

	double getTotalPrice();
		//returns price of the combined souvenirs prices

	vector<souvenir> getOrderedListByName();
		//returns a vector of the souvenirs in alphabetical order

	vector<souvenir> getOrderedListByPrice();
		//returns a vector of the souvenirs by price order

private:
	orderedMap<string, souvenir> nameIndex;		//map that will store the
												//souvenirs alphabetically
	orderedMap<double, souvenir> priceIndex; 	//map that will store the
												//souvenirs by price
	double totalPrice;							//total amount of souvenir
												//prices in the list
};




#endif /* SOUVENIRLIST_H_ */
