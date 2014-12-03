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

	redBlackTree();
		//default constructor
		//sets the root to NULL

//	rbTree_iterator & begin();
//	rbTree_iterator & end();

	redBlackTree(const redBlackTree<T, C> & otherTree);

	~redBlackTree();

	void insert(pair<T, C> newNode);

	void insert(const T key, const C value);

	//void erase(rbTree_iterator & node);

	void clear();

	//rbTree_iterator find(const T key);

	//testing
	rbNode<T, C>*  getRoot();
	void print();
private:
	rbNode<T, C> *root;	//pointer to the node that is the root of the tree
	int size;			//number of nodes in tree
};

/*****************************************************************************
 ********************************IMPLEMENTATION*******************************
 ****************************************************************************/
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

template <class T, class C>
redBlackTree<T, C>::redBlackTree()
{
	root = new rbNode<T, C>();

	size = 0;
}

template <class T, class C>
void redBlackTree<T, C>::insert(pair<T, C> newNode)
{
	rbNode<T, C> *temp = new rbNode<T, C>(newNode);
	rbNode<T,C> *nullLeftChild = new rbNode<T, C>();
	rbNode<T,C> *nullRightChild = new rbNode<T, C>();
	if(root->getData() == NULL)
	{
		root->setData(newNode);
		root->addLeftChild(*nullLeftChild);
		root->addRightChild(*nullRightChild);
	}
	else
	{
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
}


template <class T, class C>
redBlackTree<T, C>::~redBlackTree()
{
	cout << "(TREE DESTRUCTOR CALLED)\n";
	delete root;
}

template <class T, class C>
rbNode<T, C>* redBlackTree<T, C>::getRoot()
{
	return root;
}


