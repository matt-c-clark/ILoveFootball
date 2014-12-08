#include "SouvenirList.h"

//defalut constructor
//calls default constructor for both ordered map
souvenirList::souvenirList() : nameIndex(), priceIndex()
{
	//calls default constructor for nameIndex and priceIndex

	//totalPrice set to 0
	totalPrice = 0;
}

//adds the souvenir to both orderedMap
void souvenirList::add(souvenir newSouvenir)
{
	//update price
	totalPrice += newSouvenir.getPrice();

	//store the souvenir in name index
	nameIndex.insert(newSouvenir.getName(), newSouvenir);

	//store the souvenir in price index
	priceIndex.insert(newSouvenir.getPrice(), newSouvenir);
}

//removes the souvenir with the given name from both souvenirs maps
void souvenirList::remove(string souvenirName)
{
	//pointer to the souvenir in the map
	souvenir temp;

	//point temp to the returned souvenir
	temp = nameIndex.find(souvenirName).second;

	if(temp.getPrice() != 0.0)
	{
		//update price
		totalPrice -= temp.getPrice();

		//delete souvenir from name index
		nameIndex.remove(souvenirName);

		//delete souvenir from price index
		priceIndex.remove(temp.getPrice());
	}

}

//returns price of the combined souvenirs prices
double souvenirList::getTotalPrice()
{
	return totalPrice;	//return totalPrice
}

//returns a vector of the souvenirs in alphabetical order
vector<souvenir> souvenirList::getOrderedListByName()
{
	//vector that will be returned
	vector<souvenir> returnVector;

	//temp vector to store the return vector from the ordered map
	vector< pair<string, souvenir> > temp;

	//store orderd map vector into temp
	temp = nameIndex.getOrderedVector();

	//iterate through vector
	for(vector< pair<string, souvenir> >::iterator i = temp.begin(); i != temp.end(); i++)
	{
		//push the pair pointer into returnVector
		returnVector.push_back(i->second);
	}
	return returnVector;	//return vector
}

//returns a vector of the souvenirs by price order
vector<souvenir> souvenirList::getOrderedListByPrice()
{
	//vector that will be returned
	vector<souvenir> returnVector;

	//temp vector to store the return vector from the ordered map
	vector< pair<double, souvenir> > temp;

	//store orderd map vector into temp
	temp = priceIndex.getOrderedVector();

	//iterate through vector
	for(vector< pair<double, souvenir> >::iterator i = temp.begin(); i != temp.end(); i++)
	{
		//push the pair pointer into returnVector
		returnVector.push_back(i->second);
	}
	return returnVector;	//return vector
}
