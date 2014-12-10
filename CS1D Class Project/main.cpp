
#include <iomanip>
#include <iostream>
#include "Team.h"
#include "SouvenirList.h"
#include "Graph.h"
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

#if 0
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
#endif

	    //Create Graph Instance
	    Graph g;

	    //Create the vertexes
	    Vertex seattle    = Vertex("Seattle");
	    Vertex sanFran    = Vertex("San Francisco");
	    Vertex lA         = Vertex("Los Angeles");
	    Vertex denver     = Vertex("Denver");
	    Vertex chicago    = Vertex("Chicago");
	    Vertex kansasCity = Vertex("Kansas City");
	    Vertex dallas     = Vertex("Dallas");
	    Vertex houston    = Vertex("Houston");
	    Vertex boston     = Vertex("Boston");
	    Vertex newYork    = Vertex("New York");
	    Vertex atlanta    = Vertex("Atlanta");
	    Vertex miami      = Vertex("Miami");


	    //ADDING EDGES TO EACH VERTEX

	    cout << "\nAdding San Francisco, Denver, and Chicago to SEATTLE";
	    seattle.addEdge( &sanFran, 807);
	    seattle.addEdge( &denver, 1331);
	    seattle.addEdge( &chicago, 2097);


	    cout << "\nAdding Seattle, LA, and Denver to SAN FRANCISCO";
	    sanFran.addEdge( &seattle, 381);
	    sanFran.addEdge( &lA, 381);
	    sanFran.addEdge( &denver, 1267);

	    cout << "\nAdding San Francisco, Denver, Kansas City, and Dallas to LA";
	    lA.addEdge( &sanFran, 381);
	    lA.addEdge( &denver, 1015);
	    lA.addEdge(&kansasCity, 1663);
	    lA.addEdge(&dallas, 1435);

	    cout << "\nAdding Seattle, San Francisco, LA, Chicago, and Kansas City to DENVER";
	    denver.addEdge( &seattle, 1331);
	    denver.addEdge( &sanFran, 1267);
	    denver.addEdge( &lA, 1015);
	    denver.addEdge( &chicago, 1003);
	    denver.addEdge( &kansasCity, 599);

	    cout << "\nAdding Seattle, Denver, Kansas City, New York, and Boston to CHICAGO";
	    chicago.addEdge( &seattle, 2097);
	    chicago.addEdge( &denver, 1003);
	    chicago.addEdge( &kansasCity, 533);
	    chicago.addEdge( &newYork, 787);
	    chicago.addEdge( &boston, 983);

	    cout << "\nAdding Denver, New York, LA, Dallas, Atlanta, and CHICAGO to KANSAS CITY";
	    kansasCity.addEdge( &denver, 599);
	    kansasCity.addEdge( &newYork, 1260);
	    kansasCity.addEdge( &lA, 1663);
	    kansasCity.addEdge( &dallas, 496);
	    kansasCity.addEdge( &atlanta, 864);
	    kansasCity.addEdge(&chicago, 533);

	    cout << "\nAdding LA, Kansas City, Atlanta, and Houston to DALLAS";
	    dallas.addEdge( &lA, 1435);
	    dallas.addEdge( &kansasCity, 496);
	    dallas.addEdge( &atlanta, 781);
	    dallas.addEdge( &houston, 239);

	    cout << "\nAdding Dallas, Atlanta, and Miami to HOUSTON";
	    houston.addEdge( &dallas, 239);
	    houston.addEdge( &atlanta, 810);
	    houston.addEdge( &miami, 1187);

	    cout << "\nAdding Chicago and New York to BOSTON";
	    boston.addEdge( &chicago, 983);
	    boston.addEdge( &newYork, 214);

	    cout << "\nAdding Boston, Chicago, Kansas City, and Atlanta to NEW YORK";
	    newYork.addEdge( &boston, 214);
	    newYork.addEdge( &chicago, 787);
	    newYork.addEdge( &kansasCity, 1260);
	    newYork.addEdge( &atlanta, 888);

	    cout << "\nAdding Kansas City, Miami, Dallas, Houston, and New York to ATLANTA";
	    atlanta.addEdge( &kansasCity, 864);
	    atlanta.addEdge( &miami, 661);
	    atlanta.addEdge( &dallas, 781);
	    atlanta.addEdge( &houston, 810);
	    atlanta.addEdge( &newYork, 888);

	    cout << "\nAdding Houston and Atlanta to MIAMI";
	    miami.addEdge( &houston, 1187);
	    miami.addEdge( &atlanta, 661);


	    //END OF ADDING EDGES
	    cout << endl << endl;


	    // ADD VERTEXES INTO GRAPH


	    cout << "\nAdding SEATTLE to the graph";
	    g.insert( &seattle );
	    cout << "\nAdding SAN FRANCISCO to the graph";
	    g.insert( &sanFran );
	    cout << "\nAdding LA to the graph";
	    g.insert( &lA );
	    cout << "\nAdding DENVER to the graph";
	    g.insert( &denver );
	    cout << "\nAdding CHICAGO to the graph";
	    g.insert( &chicago );
	    cout << "\nAdding KANSAS CITY to the graph";
	    g.insert( &kansasCity );
	    cout << "\nAdding DALLAS to the graph";
	    g.insert( &dallas );
	    cout << "\nAdding HOUSTON to the graph";
	    g.insert( &houston );
	    cout << "\nAdding BOSTON to the graph";
	    g.insert( &boston );
	    cout << "\nAdding NEW YORK to the graph";
	    g.insert( &newYork );
	    cout << "\nAdding ATLANTA to the graph";
	    g.insert( &atlanta );
	    cout << "\nAdding MIAMI to the graph";
	    g.insert( &miami );


	    //GET INPUT
	    int input = -1;
	    do
	    {
	        cout << endl << setw(70) << setfill('*') << "" << endl;
	        printf("* %-67s%c\n* %-67s%c\n* %-67s%c\n* %-67s%c\n* %-67s%c\n* %-67s%c\n* %-67s%c\n* %-67s%c\n* %-67s%c\n* %-67s%c\n* %-67s%c\n* %-67s%c\n* %-67s%c\n", "0) Seattle" , '*', "1) San Francisco", '*', "2) LA" , '*', "3) Denver", '*', "4) Chicago" , '*', "5) Kansas City", '*', "6) Dallas", '*', "7) Houston", '**', "8) Boston", '*', "9) New York", '*', "10) Atlanta", '*', "11) Miami", '*', "-1) EXIT", '*');
	        cout << setw(70) << setfill('*') << "" << endl;


	        cout << "Enter your starting point: ";
	        cin >> input;

	        if(input == -1)
	            exit(EXIT_SUCCESS);
	        else
	        {
	            cout << "\nYour path is:\n";
	            cout << g.Depth_First_Search(input);
	        }

	    }
	    while(true);

	    return 0;
}
