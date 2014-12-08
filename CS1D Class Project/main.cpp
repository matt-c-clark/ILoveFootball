
#include <iomanip>
#include <iostream>
#include "Team.h"
#include "SouvenirList.h"
using namespace std;

int main()
{
	//red black tree testing
#if 0
	redBlackTree<int, char> tree;
	tree.insertNode(2, 'C');
	tree.insertNode(3, 'D');
	tree.insertNode(4, 'E');
	tree.insertNode(5, 'F');
	tree.insertNode(8, 'I');
	tree.insertNode(9, 'J');
	tree.insertNode(10, 'K');
	tree.insertNode(11, 'L');
	tree.insertNode(12, 'M');
	tree.insertNode(13, 'N');
	tree.insertNode(0, 'A');
	tree.insertNode(1, 'B');
	tree.insertNode(6, 'G');
	tree.insertNode(7, 'H');
	tree.insertNode(7, 'M');

	tree.breadthFirstTraversal();
	tree.blackHeightTraversal();

	tree.deleteNode(11);

	tree.breadthFirstTraversal();
	tree.blackHeightTraversal();

	cout << "inorder traversal:\n";
	vector<rbNode<int, char>*> v = tree.inOrderTraversal();

	for(vector<rbNode<int, char>*>::iterator i = v.begin(); i != v.end(); i++)
	{
		rbNode<int, char> *temp;
		temp = *i;
		cout << temp->getKey() << " ";
	}
#endif

	//ordered map testing
#if 0
	orderedMap<int, char> map;

	map.insert(2, 'C');
	map.insert(3, 'D');
	map.insert(4, 'E');
	map.insert(5, 'F');
	map.insert(8, 'I');
	map.insert(9, 'J');
	map.insert(10, 'K');
	map.insert(11, 'L');
	map.insert(12, 'M');
	map.insert(13, 'N');
	map.insert(0, 'A');
	map.insert(1, 'B');
	map.insert(6, 'G');
	map.insert(7, 'H');
	map.insert(7, 'M');

	vector< pair<int, char> > v;
	v = map.getOrderedVector();


	for(vector< pair<int, char> >::iterator i = v.begin(); i != v.end(); i++)
	{
		pair<int, char> temp;
		temp = *i;
		cout << temp.first << " ";
	}

	pair<int, char> temp;
	temp = map.find(8);

	cout << temp.second;
 #endif

	stadium s("Qualcomm Stadium", "San Diego, California", 1967, 7, 20, true);
	stadium s2("At&T Stadium", "Arlington, Texas", 2009, 4, 20, false);
	s.addTeam("Chargers");
	s2.addTeam("Cowboys");

	team chargers("Chargers", true, s);
	team cowboys("Cowboys", false, s2);
	cout << chargers.getStadium().getCity() << endl;

	souvenirCatalog catalog;
	catalog.add("Team Hat", 18.99);
	catalog.add("Team Jersey", 35.35);
	catalog.add("Team Pennant", 12.99);
	catalog.add("Autographed Football", 79.99);

	vector< pair<string, double>* > v2 = catalog.getVectorCatalog();

	for(vector< pair<string, double>* >::iterator i = v2.begin(); i != v2.end(); i++)
	{
		pair<string, double> *temp;
		temp = *i;
		cout << temp->first << " / ";
	}

	souvenir so("Team Pennant", chargers, catalog);
	souvenir so2("Team Jersey", cowboys, catalog);
	cout << "\n$" << so.getPrice() << endl;

	catalog.find("Team Pennant")->second = 16.99;
	cout << "\n$" << so.getPrice() << endl;

	catalog.erase("Team Pennant");

	catalog.add("Team Pennant", 6.99);
	so.updatePrice();
	cout << "\n$" << so.getPrice() << endl;

	souvenirList sl;
	sl.add(so);
	sl.add(so2);
	cout << "\n$" << sl.getTotalPrice() << endl;

	vector<souvenir> v3 = sl.getOrderedListByName();

	for(vector<souvenir>::iterator i = v3.begin(); i != v3.end(); i++)
	{
		cout << i->getName() << " ";
	}

	cout << endl;

	v3 = sl.getOrderedListByPrice();
	for(vector<souvenir>::iterator i = v3.begin(); i != v3.end(); i++)
	{
		cout << i->getName() << " ";
	}
	return 0;
}
