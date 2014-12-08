#include "OrderedMap.cpp"
#include "Team.h"
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
	s.addTeam("Chargers");


	team m("Chargers", true, s);
	cout << m.getStadium().getCity() << endl;
	return 0;
}
