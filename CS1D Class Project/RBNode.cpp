#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//node class that will be used specifically in a red black tree
//stores a T,C: key, value pair
//uses key to determine if a node is greater or larger than another node
//T object expected to have comparison operators overloaded
template <class T, class C>
class rbNode
{
public:

	enum color
	{
		BLACK,
		RED,
		BLANK
	};
		//enum type to determine the "color" of the nodes
		//used for red black tree

	//EXCPETIONS
	class nullNode{};	//thrown when a null node is attempted to be accessed

	//OVERLOADED OPERATORS
	bool operator==(const rbNode<T, C> & otherNode);
		//checks the key stored in the data pair and compares the two
		// if they are equal, returns true, else false

	bool operator>=(const rbNode<T, C> & otherNode);
		//checks the key stored in the data pair and compares the two
		//if the current nodes key is greater than the passed nodes key,
		// returns true, else false

	bool operator<=(const rbNode<T, C> & otherNode);
		//checks the key stored in the data pair and compares the two
		//if the current nodes key is less than the passed nodes key,
		// returns true, else false

	//CONSTRUCTORS
	rbNode();
		//default constructor
		//Color = BLANK
		//data, parent, leftChild, rightChild = NULL

	rbNode(pair<T, C>  & data);
		//non-default constructor
		//data will equal the passed pair
		//parent, leftChild, rightChild = NULL
		//performs deep copy on passed data

	rbNode(const T & key, const C & object);
		//non-default constructor
		//T object stored in first element in data
		//C object stored in second element in data
		//performs deep copy on passed data

	rbNode(const rbNode<T, C> & otherNode);
		//copy constructor
		//calls overloaded assignment operator
		//does not copy the parent the node is pointing to

	~rbNode();
		//destructor
		//does not delete parent

	//METHODS
	void copyRBNode(const rbNode<T, C> & otherNode);
		//is passed a  node
		//stores the data in the node
		//also stores the data of all its descendants
		//if current node already has descendants, they are deleted first

	pair<T, C>* getData();
		//returns the data stored in node as a pair

	T getKey();
		//returns the key stored in the data pair

	C getValue();
		//returns the object stored in the data pair

	rbNode<T, C>*  getLeftChild();
		//return node of the leftChild of the node
		//throws nullLeftChild if no leftChild

	rbNode<T, C>*  getRightChild();
		//return node of the rightChild of the node
		//throws nullRightChild if no rightChild

	rbNode<T, C>* getParent();
		//return node of the parent of the node
		//throws nullParent if no parent

	void setData(pair<T, C> & newPair);
		//is passed a pair in the key,value format
		//deep copies the data into the node as the data pair

	void setData(const T & key, const C & vlaue);
		//is passed a key and a value
		//stores those values in the pair data in the node

	void addLeftChild(rbNode<T, C> & newLeftChild);
		//is passed a node
		//node is deep copied then set as the left child of current node
		//if node already has a left child, it deletes the current left child

	void addRightChild(rbNode<T, C> & newRightChild);
		//is passed a node
		//node is deep copied then set as the right child of current node

	bool isLeftChild();
		//returns true if the node is a left child of its parent if it has
		// a parent, else returns false

	bool isRightChild();
		//returns true if the node is a right child of its parent if it has
		// a parent, else returns false

	string toString();
		// returns the data stored in a node as a string
		//format: (key, value)
private:
	pair<T, C> *data;			//pointer to a pair that stores the data of
								// the node: key, value pair
	rbNode<T, C> *parent;		//pointer to a node that is this nodes parent
	rbNode<T, C> *leftChild;	//pointer to a node that is this nodes left
								// child
	rbNode<T, C> *rightChild;	//pointer to a node that is this nodes right
								// child
	color color;				//stores the color of the node in the form of
								// of the enumerated type color
};

/*****************************************************************************
 ********************************IMPLEMENTATION*******************************
 ****************************************************************************/

//checks the key stored in the data pair and compares the two
// if they are equal, returns true, else false
template <class T, class C>
bool rbNode<T, C>::operator==(const rbNode<T, C> & otherNode)
{
	//if either nodes data is null, throw exception
	if(data == NULL || otherNode.data == NULL){throw nullNode();}

	//checks if the two keys are equivalent, if they are, return true
	if(data->first == otherNode.data->first)
	{
		return true;
	}

	//else return false
	return false;
}

//checks the key stored in the data pair and compares the two
//if the current nodes key is greater than the passed nodes key,
// returns true, else false
template <class T, class C>
bool rbNode<T, C>::operator>=(const rbNode<T, C> & otherNode)
{
	//if either nodes data is null, throw exception
	if(data == NULL || otherNode.data == NULL){throw nullNode();}

	//checks if the first key is greater than or equal to,
	//if they are, return true
	if(data->first >= otherNode.data->first)
	{
		return true;
	}

	//else return false
	return false;
}

//checks the key stored in the data pair and compares the two
//if the current nodes key is less than the passed nodes key,
// returns true, else false
template <class T, class C>
bool rbNode<T, C>::operator<=(const rbNode<T, C> & otherNode)
{
	//if either nodes data is null, throw exception
	if(data == NULL || otherNode.data == NULL){throw nullNode();}

	//checks if the first key is less than or equal to,
	//if they are, return true
	if(data->first <= otherNode.data->first)
	{
		return true;
	}

	//else return false
	return false;
}

//default constructor
//Color = BLANK
//data, parent, leftChild, rightChild = NULL
template <class T, class C>
rbNode<T, C>::rbNode()
{
	//initializes all pointers to NULL
	data = NULL;
	parent = NULL;
	leftChild = NULL;
	rightChild = NULL;

	//initial color will be blank
	color = BLANK;
}

//non-default constructor
//data will equal the passed pair
//parent, leftChild, rightChild = NULL
//performs deep copy on passed data
template <class T, class C>
rbNode<T, C>::rbNode(pair<T, C> & data)
{
	//dynamically create a pair for data to point to
	this->data = new pair<T, C>;

	//store passed data into dynamic data
	*this->data = data;

	//rest of the pointers set to null
	parent = NULL;
	leftChild = NULL;
	rightChild = NULL;

	//initial color will be blank
	this->color = BLANK;
}

//non-default constructor
//T object stored in first element in data
//C object stored in second element in data
//performs deep copy on passed data
template <class T, class C>
rbNode<T, C>::rbNode(const T & key, C  const & value)
{
	//dynamically create a pair for data to point to
	this->data = new pair<T, C>;

	//store passed data into dynamic data
	data->first = key;
	data->second = value;

	//rest of the pointers set to null
	parent = NULL;
	leftChild = NULL;
	rightChild = NULL;

	//initial color will be blank
	this->color = BLANK;
}

//copy constructor
//calls overloaded assignment operator
//does not copy the parent the node is pointing to
template<class T, class C>
rbNode<T, C>::rbNode(const rbNode<T, C>& other)
{
	//initialize node to null first
	data = NULL;
	parent = NULL;
	leftChild = NULL;
	rightChild = NULL;
	color = BLANK;
	cout << "(COPY CONSTRUCTOR CALLED)\n";

	//calls copy method
	copyRBNode(other);
}

//destructor
//does not delete parent
template <class T, class C>
rbNode<T, C>::~rbNode()
{
	cout << "(DESTRUCTOR CALLED)\n";

	//delete all pointers except parent if not pointing to NULL
	if(data != NULL){delete data;}
	if(leftChild != NULL){delete leftChild;}
	if(rightChild != NULL){delete rightChild;}
}

//is passed a  node
//stores the data in the node
//also stores the data of all its descendants
//if current node already has descendants, they are deleted first
template <class T, class C>
void rbNode<T, C>::copyRBNode(const rbNode<T, C> & otherNode)
{
	cout << "(COPY RB NODE CALLED)\n";

	//delete data and descendants if necessary
	if(data != NULL){delete data;}
	if(leftChild != NULL){delete leftChild;}
	if(rightChild != NULL){delete rightChild;}

	//assign appropriate color
	color = otherNode.color;

	//copy the data if necessary
	if(otherNode.data != NULL)
	{
		//store passed nodes data into dynamic data
		data = new pair<T, C>;
		*data = *otherNode.data;
	}

	//copy the left child if necessary
	if(otherNode.leftChild != NULL)
	{
		//stores passed nodes leftChild into current leftChild
		leftChild = new rbNode<T, C>();
		leftChild->copyRBNode(*otherNode.leftChild); //recursion

		//set as the parent of new Node
		leftChild->parent = this;
	}

	//copy the right child if necessary
	if(otherNode.rightChild != NULL)
	{
		//stores passed nodes rightChild into current rightChild
		rightChild = new rbNode<T, C>();
		rightChild->copyRBNode(*otherNode.rightChild); //recursion

		//set as the parent of new Node
		rightChild->parent = this;
	}
}

//returns the data stored in node as a pair
template <class T, class C>
pair<T, C>* rbNode<T, C>::getData()
{
	return data;	//return data pair
}

//returns the key stored in the data pair
template <class T, class C>
T rbNode<T, C>::getKey()
{
	//throws returnNull if data is NULL
	if(data == NULL){throw nullNode();}

	return data->first;	//return key in data pair
}

//returns the object stored in the data pair
template <class T, class C>
C rbNode<T, C>::getValue()
{
	//throws returnNull if data is NULL
	if(data == NULL){throw nullNode();}

	return data->second;	//return key in data pair
}

//return node of the leftChild of the node
//throws nullLeftChild if no leftChild
template<class T, class C>
rbNode<T, C>* rbNode<T, C>::getLeftChild()
{
	return leftChild;	//return leftChild Node
}

//return node of the rightChild of the node
//throws nullRightChild if no rightChild
template<class T, class C>
rbNode<T, C>* rbNode<T, C>::getRightChild()
{
	return rightChild;	//return rightChild Node
}

//return node of the parent of the node
//throws nullNode if no parent
template <class T, class C>
rbNode<T, C>* rbNode<T, C>::getParent()
{
	return parent;	//return rightChild Node
}

//is passed a pair in the key,value format
//deep copies the data into the node as the data pair
template <class T, class C>
void rbNode<T, C>::setData(pair<T, C> & newPair)
{
	//checks to see if data is NULL
	//if its is, dynamically create pair
	if(data == NULL){data = new pair<T, C>;}

	//store passed pair into data
	*data = newPair;
}

//is passed a key and a value
//stores those values in the pair data in the node
template <class T, class C>
void rbNode<T, C>::setData(const T & key, const C & value)
{
	//checks to see if data is NULL
	//if its is, dynamically create pair
	if(data == NULL){data = new pair<T, C>;}

	//store passed key, value pair into data
	data->first = key;
	data->second = value;
}

//is passed a node
//node is deep copied then set as the left child of current node
template <class T, class C>
void rbNode<T, C>::addLeftChild(rbNode<T, C> & newLeftChild)
{
	//checks to see if node is NULL, if not, deletes it first
	if(leftChild != NULL){delete leftChild;}

	//dynamically create new node
	leftChild = new rbNode<T, C>();

	//check to see if passed data is NULL
	if(newLeftChild.data != NULL)
	{
		//dynamically create data for node
		leftChild->data = new pair<T, C>;

		//stores data in leftChild from newLeftData
		*leftChild->data = *newLeftChild.data;
	}

	//setParent respectfully
	leftChild->parent = this;
}

//is passed a node
//node is deep copied then set as the right child of current node
template <class T, class C>
void rbNode<T, C>::addRightChild(rbNode<T, C> & newRightChild)
{
	//checks to see if node is NULL, if not, deletes it first
	if(rightChild != NULL){delete rightChild;}

	//dynamically create new node
	rightChild = new rbNode<T, C>();

	if(newRightChild.data != NULL)
	{
		//dynamically create data for node
		rightChild->data = new pair<T, C>;

		//stores data in rightChild from newRightData
		*rightChild->data = *newRightChild.data;
	}

	//setParent respectfully
	rightChild->parent = this;
}

//returns true if the node is a left child of its parent if it has
// a parent, else returns false
template <class T, class C>
bool rbNode<T, C>::isLeftChild()
{
	//check if has parent and if it has a leftChild
	//if not, return false
	if(parent == NULL || parent->leftChild == NULL)
	{
		return false;
	}

	//return true if is leftChild of parent
	if(parent->leftChild == this)
	{
		return true;
	}

	//return true if not
	return false;
}

//returns true if the node is a right child of its parent if it has
// a parent, else returns false
template <class T, class C>
bool rbNode<T, C>::isRightChild()
{
	//check if has parent and if it has a rightChild
	//if not, return false
	if(parent == NULL || parent->rightChild == NULL)
	{
		return false;
	}

	//return true if is rightChild of parent
	if(parent->rightChild == this)
	{
		return true;
	}

	//return true if not
	return false;
}

// returns the data stored in a node as a string
//format: (key, value)
template <class T, class C>
string rbNode<T, C>::toString()
{
	//store the key value pair as a string
	stringstream a;
	a << "(" << data->first << ", " << data->second << ")";

	return a.str();	//returns string
}
