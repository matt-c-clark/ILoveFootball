#include "RBNode.cpp"
#include <iterator>
template<class T, class C>
class redBlackTree
{
public:

//	class rbTree_iterator
//	{
//	public:
//		rbTree_iterator();
//
//		rbTree_iterator(const rbTree_iterator & i);
//			//copy constructor
//
//		void operator=(const rbTree_iterator & i);
//		void operator=(const rbNode<T, C> & node);
//		void operator++();
//		rbNode<T, C> operator*();
//
//		rbNode<T, C> *ptr;
//
//	private:
//
//	};

	//EXCPETIONS

	//thrown when a null node is attempted to be accessed
	class keyNotFound{};

	redBlackTree();
		//default constructor
		//sets the root to NULL

//	rbTree_iterator & begin();
//	rbTree_iterator & end();

	redBlackTree(const redBlackTree<T, C> & otherTree);
		//copy constructor

	~redBlackTree();
		//destructor

	void insert(pair<T, C> newNode);
		//adds pair to the tree like a regular binary search tree
		//then determines whether any balances are needed

	void insert(const T key, const C value);
		//adds key value pair to the tree like a regular binary search tree
		//then determines whether any balances are needed

	rbNode<T, C>* find(const int & key);
		//finds the key in the tree
	    //if it is not found, throws exception
		//if found, returns a pointer to the found node

	void erase(const int & key);
		//erases the key from the tree using binary search tree techniques
		//rearrange the red black tree to preserve balance

	void clear();

	//rbTree_iterator find(const T key);

	//testing
	rbNode<T, C>*  getRoot();
	void print();

private:
	rbNode<T, C>* binarySearchTreeInsert(pair<T, C> newNode);
		//inserts the pair into the tree as a binary search tree
		// does not do any of the balancing that a red black tree
		// does
		//returns a pointer to the node that was added

	rbNode<T, C>* binarySearchTreeInsert(const T key, const C value);
		//inserts the key value pair into the tree as a binary search tree
		//does not do any of the balancing that a red black tree
		// does
		//returns a pointer to the node that was added

	rbNode<T, C>* binarySearchTreeErase(const int & key);
		//removes the key from the tree using binaryTree algorithms

	rbNode<T, C> *root;	//pointer to the node that is the root of the tree
	int size;			//number of nodes in tree
};

/*****************************************************************************
 ********************************IMPLEMENTATION*******************************
 ****************************************************************************/

//default constructor
//sets the root to NULL
template <class T, class C>
redBlackTree<T, C>::redBlackTree()
{
	//sets the root to a NULL node
	root = new rbNode<T, C>();

	//size set to 0
	size = 0;
}

//destructor
template <class T, class C>
redBlackTree<T, C>::~redBlackTree()
{
	cout << "(TREE DESTRUCTOR CALLED)\n";

	//calls the destructor of the root that will delete all the descendants
	delete root;
}

//adds pair to the tree like a regular binary search tree
//then determines whether any balances are needed
template <class T, class C>
void redBlackTree<T, C>::insert(pair<T, C> newNode)
{
	//create pointer that will point to the added node
	rbNode<T, C> *addedNode;

	//adds pair to the tree using binaryTree algorithm
	//set addedNode ptr to the node added to the tree
	addedNode = binarySearchTreeInsert(newNode);
}

//adds key value pair to the tree like a regular binary search tree
//then determines whether any balances are needed
template<class T, class C>
void redBlackTree<T, C>::insert(const T key, const C value)
{
	//creates a pair with the passed data
	pair<T, C> tempPair(key, value);

	//create pointer that will point to the added node
	rbNode<T, C> *addedNode;

	//adds pair to the tree using binaryTree algorithm
	//set addedNode ptr to the node added to the tree
	addedNode = binarySearchTreeInsert(tempPair);
}

//finds the key in the tree
//if it is not found, throws exception
//if found, returns a pointer to the found node
template <class T, class C>
rbNode<T, C>* redBlackTree<T, C>::find(const int & key)
{
	//pointer to the node that is currently being tested
	rbNode<T, C> *currentNode = root;

	//boolean to determine if key has been found or if it is not in the tree
	bool done = false;

	//continues to loop until done
	while(!done)
	{
		//checks if the key is the same as the current node
		if(key == currentNode->getKey())
		{
			//key has been found
			done = true;
		}
		//checks if nodes key is too large
		else if(key < currentNode->getKey())
		{
			//checks if has a left child
			if(currentNode->getLeftChild()->getData() != NULL)
			{
				//current node is now the left child
				currentNode = currentNode->addLeftChild();
			}
			else
			{
				//throws exception when key not found
				throw keyNotFound();
			}
		}
		//checks if nodes key is too small
		else if(key > currentNode->getKey())
		{
			//checks if has a right child
			if(currentNode->getRightChild()->getData() != NULL)
			{
				//current node is now the left child
				currentNode = currentNode->addRightChild();
			}
			else
			{
				//throws exception when key not found
				throw keyNotFound();
			}
		}
	}
	return currentNode;
}

template <class T, class C>
rbNode<T, C>* redBlackTree<T, C>::getRoot()
{
	return root;
}

//inserts the pair into the tree as a binary search tree
//does not do any of the balancing that a red black tree
// does
//returns a pointer to the node that was added
template <class T, class C>
rbNode<T, C>* redBlackTree<T, C>::binarySearchTreeInsert(pair<T, C> newNode)
{
	rbNode<T, C> *temp;
	rbNode<T,C> *nullLeftChild = new rbNode<T, C>();
	rbNode<T,C> *nullRightChild = new rbNode<T, C>();
	if(root->getData() == NULL)
	{
		root->setData(newNode);
		root->addLeftChild(*nullLeftChild);
		root->addRightChild(*nullRightChild);
		root->setColor(RED);
		temp = root;
	}
	else
	{
		temp  = new rbNode<T, C>(newNode);
		rbNode<T, C> *current = root;
		bool inserted = false;
		while(!inserted)
		{
			if(*current >= *temp)
			{
				//cout << "IN LEFT LOOP\n" << flush;
				if(current->getLeftChild()->getData() == NULL)
				{
					current->getLeftChild()->setData(newNode);
					current->getLeftChild()->addLeftChild(*nullLeftChild);
					current->getLeftChild()->addRightChild(*nullRightChild);
					size++;
					inserted = true;
					//cout << "Inserted Left Child\n";
				}
				else
				{
					current = current->getLeftChild();
				}
			}
			else
			{
				//cout << "IN RIGHT LOOP\n" << flush;
				if(current->getRightChild()->getData() == NULL)
				{
					//cout << "apple\n" << flush;
					current->getRightChild()->setData(newNode);
					current->getRightChild()->addLeftChild(*nullLeftChild);
					current->getRightChild()->addRightChild(*nullRightChild);
					size++;
					inserted = true;
					//cout << "Inserted Right Child\n";
				}
				else
				{
					current = current->getRightChild();
				}
			}
		}
	}
	return temp;
}

//erases the key from the tree using binary search tree techniques
//rearrange the red black tree to preserve balance
template <class T, class C>
void redBlackTree<T, C>::erase(const int & key)
{
	//pointer to node to be deleted
	rbNode<T, C> *temp;

	//finds the key, returns pointer to the node
	//throws exception if not found
	temp = find(key);

	if(temp->getLeftChild()->isExternalNode())
	{
		cout << "apple\n";
	}
}


//inserts the key value pair into the tree as a binary search tree
//does not do any of the balancing that a red black tree
// does
//returns a pointer to the node that was added
template<class T, class C>
rbNode<T, C>* redBlackTree<T, C>::binarySearchTreeInsert(const T key, const C value)
{
	//create pair with given data
	pair<T, C> tempPair(key, value);

	//create pointer that will be returned
	rbNode<T, C> *temp;

	//adds pair to the tree
	//pointer set to the node that was added
	temp = binarySearchTreeInsert(tempPair);

	return temp;	//return temp pointer
}

//template <class T, class C>
//redBlackTree<T, C>::rbTree_iterator::rbTree_iterator()
//{
//	ptr = NULL;
//}
//
//
//template <class T, class C>
//redBlackTree<T, C>::rbTree_iterator::rbTree_iterator(const rbTree_iterator & i)
//{
//	ptr = i.ptr;
//}
//
//template <class T, class C>
//void redBlackTree<T, C>::rbTree_iterator::operator=(const rbTree_iterator &  i)
//{
//	ptr = i.ptr;
//}
//
//template <class T, class C>
//void redBlackTree<T, C>::rbTree_iterator::operator++()
//{
//	//if NULL Node
//	if(ptr->getData() == NULL)
//	{
//		//if begin()
//		if(*ptr <= *root)
//		{
//			ptr = ptr->getParent();
//		}
//		//if end()
//		else
//		{
//			cout << "Out of Scope\n";
//		}
//	}
//	//if an internal node
//	else if(ptr->getRightChild()->getData() != NULL)
//	{
//		ptr = ptr->getRightChild();
//		while(ptr->getLeftChild()->getData() != NULL)
//		{
//			ptr = ptr->getLeftChild();
//		}
//	}
//	//external nodes
//	//if left child
//	else if(ptr->isleftChild())
//	{
//		ptr = ptr->getParent();
//	}
//	//right child
//	else if(ptr->isRightChild())
//	{
//		//node before end()
//		if(ptr->getRightChild() == end())
//		{
//			ptr = ptr->getRightChild();
//		}
//		else
//		{
//			//look for ancestor that is larger then current node
//			rbNode<T, C> *temp = ptr->getParent()->getParent();
//			while(*temp <= *ptr)
//			{
//				temp = temp->getParent();
//			}
//			ptr = temp;
//		}
//	}
//	//tree with only a root
//	else
//	{
//		ptr = end().ptr;
//	}
//}
//
//template <class T, class C>
//rbNode<T, C> redBlackTree<T, C>::rbTree_iterator::operator*()
//{
//	return *ptr;
//}
//
//template <class T, class C>
//typename redBlackTree<T, C>::rbTree_iterator & redBlackTree<T, C>::begin()
//{
//	rbNode<T, C> *temp = root;
//	rbTree_iterator i;
//
//	while(temp->getLeftChild() != NULL)
//	{
//		temp = temp->getLeftChild();
//	}
//	i.ptr = temp;
//
//	return i;
//}
//
//template <class T, class C>
//typename redBlackTree<T, C>::rbTree_iterator & redBlackTree<T, C>::end()
//{
//	rbNode<T, C> *temp = root;
//	rbTree_iterator i;
//
//	while(temp->getRightChild() != NULL)
//	{
//		temp = temp->getRightChild();
//	}
//	i.ptr = temp;
//
//	return i;
//}
