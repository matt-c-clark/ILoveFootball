
#include "RedBlackTree.cpp"
using namespace std;


template<class T, class C>
class orderedMap
{
public:
	orderedMap();
		//default constructor
		//creates an empty map

	void insert(T key, C value);
		//inserts the key value pair into the map
		//wrapper for redBlackTree insertNode method

	void insert(pair<T, C> data);
		//inserts the pair into the map as a key value pair
		//wrapper for redBlackTree insertNode method

	void remove(T key);
		//removes the key from the map
		//wrapper for redBlackTree insertNode method deleteNode

	pair<T, C> find(T key);
		//finds the key in the ordered map
		//returns a pointer to a pair that have pointers to the
		// key and value

	vector< pair<T, C> > getOrderedVector();
		//returns a vector of pair pointers that is ordered according to the
		// red black tree
private:
	redBlackTree<T, C> tree;	//data structure that will store the data
								// for the ordered map
								//wrapper
};

/*****************************************************************************
 ************** ************** IMPLEMENTATION  **************  **************
 ****************************************************************************/

//default constructor
//creates an empty map
template<class T, class C>
orderedMap<T, C>::orderedMap() : tree()
{
	//calls default constructor for tree
}

//inserts the key value pair into the map
//wrapper for redBlackTree insertNode method
template <class T, class C>
void orderedMap<T, C>::insert(T key, C value)
{
	tree.insertNode(key, value);	//wrapper
}

//inserts the pair into the map as a key value pair
//wrapper for redBlackTree insertNode method
template <class T, class C>
void orderedMap<T, C>::insert(pair<T, C> data)
{
	T key;		//stores the key of the passed pair
	C value;	//stores the value of the passed pair

	//store the key and value in the variables from the passed pair
	key = data.first;
	value = data.second;

	tree.insertNode(key, value);	//wrapper
}

//removes the key from the map
//wrapper for redBlackTree insertNode method deleteNode
template <class T, class C>
void orderedMap<T, C>::remove(T key)
{
	tree.deleteNode(key);	//wrapper
}

//finds the key in the ordered map
//returns a pointer to a pair that have pointers to the
// key and value
template <class T, class C>
pair<T, C> orderedMap<T, C>::find(T key)
{
	//pointer to the node that contains the key in the tree
	rbNode<T, C> *temp;

	//pair that will be retunrs to the user
	pair<T, C> returnPair;

	//set pointer to the node in the tree
	temp = tree.accessNode(key);

	//stores the references form the node into the pair
	returnPair.first = temp->getKey();
	returnPair.second = temp->getValue();

	return returnPair;	//return pair
}

//returns a vector of pair pointers that is ordered according to the
// red black tree
template <class T, class C>
vector< pair<T, C> > orderedMap<T, C>::getOrderedVector()
{
	//vector that will returned to the user
	vector< pair<T, C> > returnVector;

	//vector that stores pointers in the nodes in inOrder traversal
	vector< rbNode<T, C>*> nodeVector;

	//pointer to node that will be used to access the nodes in nodeVector
	rbNode<T, C> *tempNode;

	//pair that will be used to fill the returnNode
	pair<T, C> tempPair;

	//get the orderd vector
	nodeVector = tree.inOrderTraversal();

	//iterate through the node vector
	for(typename vector< rbNode<T, C>* >::iterator i = nodeVector.begin(); i != nodeVector.end(); i++)
	{
		//get the node from the vector
		tempNode = *i;

		//store the data from the node into the pair
		tempPair.first = tempNode->getKey();
		tempPair.second = tempNode->getValue();

		//push the temp pair onto the vector
		returnVector.push_back(tempPair);
	}
	return returnVector;	//return vector
}




