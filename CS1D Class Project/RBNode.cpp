
#include <iostream>
using namespace std;

//node class that will be used specifically in a red black tree
//stores a T,C: key, value pair
//uses key to determine if a node is greater or larger than another node
//T object expected to have comparison operators overloaded
template <class T, class C>
class rbNode
{
public:
	rbNode(T key, C value);
		//default constructor
		//keys is set to the passed key
		//value is set to the passed value
		//is red set to true signifying its a red node
		//parent, left, right is NULL

	void recolor();
		//toggles the isRed boolean
		//if its true, turns it false
		//if it is false, turns it true

	bool isColoredRed();
		//used to determine the color of the node
		//returns true if the node is red
		//returns false if the node is black

	T getKey();
		//returns a copy of the key in the node

	C getValue();
		//returns a copy of the value in the node

	rbNode<T, C>* getLeft();
		//returns a pointer to the left child

	rbNode<T, C>* getRight();
		//returns a pointer to the right child

	rbNode<T, C>* getParent();
		//returns a pointer to the parent node

	void clearParent();
		//removes the pointer to the parent
		//node will no longer have a parent

	void setLeft(rbNode* left);
		//adds the pointer as the left child of the node

	void setRight(rbNode* right);
		//adds the pointer as the right child of the node

private:
	bool isRed;				//boolean to determine the color of the node, true
							// if red
	T key;					//key of the node, used as the comparator
	C value;				//value of the node
	rbNode<T, C> *left;		//pointer to the left child node
	rbNode<T, C> *right;	//pointer to the right child node
	rbNode<T, C> *parent;	//pointer to the parent of the node
};

/*****************************************************************************
 ************** ************** IMPLEMENTATION  **************  **************
 ****************************************************************************/

//default constructor
//keys is set to the passed key
//value is set to the passed value
//is red set to true signifying its a red node
//parent, left, right is NULL
template <class T, class C>
rbNode<T, C>::rbNode(T key, C value)
{
	//makes the node red
	this->isRed = true;

	//stores the passed key, value in the respective data fields
	this->key = key;
	this->value = value;

	//pointers to nodes are set to NULL
	left = NULL;
	right = NULL;
	parent = NULL;
}

//toggles the isRed boolean
//if its true, turns it false
//if it is false, turns it true
template <class T, class C>
void rbNode<T, C>::recolor()
{
	//toggles the isRed boolean
	if (this->isRed)
	{
		//if true, turns it to false
		this->isRed = false;
	}
	else
	{
		//if false, turns it true
		this->isRed = true;
	}
}

//used to determine the color of the node
//returns true if the node is red
//returns false if the node is black
template <class T, class C>
bool rbNode<T, C>::isColoredRed()
{
	return isRed;	//returns the boolean
}

//returns a copy of the key in the node
template <class T, class C>
T rbNode<T, C>::getKey()
{
	return this->key;  //return key by value
}

//returns a copy of the value in the node
template <class T, class C>
C rbNode<T, C>::getValue()
{
	return this->value; //return the value by value
}

//returns a pointer to the left child
template <class T, class C>
rbNode<T, C>* rbNode<T, C>::getLeft()
{
	return this->left;	//returns the pointer to the left
}

//returns a pointer to the right child
template <class T, class C>
rbNode<T, C>* rbNode<T, C>::getRight()
{
	return this->right;	//returns the pointer to the right
}

//returns a pointer to the parent node
template <class T, class C>
rbNode<T, C>* rbNode<T, C>::getParent()
{
	return this->parent;	//returns the pointer to the parent
}

//removes the pointer to the parent
//node will no longer have a parent
template <class T, class C>
void rbNode<T, C>::clearParent()
{
	this->parent = NULL;	//pointer is set to null
}

//adds the pointer as the left child of the node
template <class T, class C>
void rbNode<T, C>::setLeft(rbNode* left)
{
	//sets the left child using the passed pointer
	this->left = left;

	//checks to makes sure the child is not NULL
	//if not, the new left child has its parent set to the current node
	if(left != NULL) left->parent = this;
}

//adds the pointer as the right child of the node
template <class T, class C>
void rbNode<T, C>::setRight(rbNode* right)
{
	//sets the right child using the passed pointer
	this->right = right;

	//checks to makes sure the child is not NULL
	//if not, the new right child has its parent set to the current node
	if(right != NULL) right->parent = this;
}
