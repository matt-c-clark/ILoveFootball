
#include <queue>
#include <stack>
#include <vector>
#include "RBNode.cpp"

using namespace std;

//class that represents a red black tree
//Binary search tree with the benefit of auto balancing
//uses rbNode class as its nodes. Nodes are either red or black
//the black height for all external nodes should be the same
template <class T, class C>
class redBlackTree
{
public:
	redBlackTree();
		//default constructor
		//root is set to NULL

	bool isEmpty();
		//determined if the tree is empty
		//returns true if the tree is empty
		//else return false;

	rbNode<T, C>* accessNode(T key);
		//uses private method accessNode
		//searches the tree for the passed key
		//if found, returns pointer to the node
		//if not found, returns pointer to NULL

	void insertNode(T key, C value);
		//inserts the node in the tree using binary search tree logic
		//if there us a double red, uses appropriate algorithm to
		// re-balance the red black tree
		//calls private method insertNode

	void deleteNode(T key);
		//searches for the key in the tree;
		//if not found delets nothing
		//if found, deletes the node using binary search tree techniques
		//then re-balances the red black tree
		//calls private method deletNode

	void breadthFirstTraversal();
		//performs a  breadth first traversal on the tree
		//used for testing purposes
		//a "~" in front of a node means its colored red
		//output 'n' for null nodes

	bool blackHeightTraversal();
		//checks the "black height" of all external nodes
		//meaning the number of black ancestors
		//in red black trees, all external nodes should have the same black
		// height. If all black heights the same, output message saying the
		// black height and confirming its a red black tree
		// else outputs message saying its not a red black tree
		//for testing purposes

	vector<rbNode<T, C>*> inOrderTraversal();
		//performs a pre-order traversal on the tree
		//each time a node is visited the node is added to
		// vector, vector is returned at the end
		//calls private method inOrderTraversal

private:
	rbNode<T, C>* root;	//pointer to a rbNode representing the root

	rbNode<T, C>* accessNode(rbNode<T, C> *root, T key);

	void insertNode(rbNode<T, C> *root, T key, C value);

	void deleteNode(rbNode<T, C> *root, T key);

	void inOrderTraversal(rbNode<T, C> *root, vector<rbNode<T, C>*> & vector);
		//similar method as public method inOrderTraversal()
		//treats the passed pointer as the root
		//pushes nodes onto the passed vector

	void solveDoubleRedProblem(rbNode<T, C> *root);

	void leftRotate(rbNode<T, C> *root);

	void rightRotate(rbNode<T, C> *root);

	void restoreReducedHeight(rbNode<T, C> *root);

	void firstLRotate(rbNode<T, C> *root);

	void secondLRotate(rbNode<T, C> *root);

	void thirdLRotate(rbNode<T, C> *root);

	void forthLRotate(rbNode<T, C> *root);

	void firstRRotate(rbNode<T, C> *root);

	void secondRRotate(rbNode<T, C> *root);

	void thirdRRotate(rbNode<T, C> *root);

	void forthRRotate(rbNode<T, C> *root);
};

/*****************************************************************************
 ************** ************** IMPLEMENTATION  **************  **************
 ****************************************************************************/

//default constructor
//root is set to NULL
template <class T, class C>
redBlackTree<T, C>::redBlackTree()
{
	this->root = NULL;	//root points to NULL
}

//determined if the tree is empty
//returns true if the tree is empty
//else return false;
template <class T, class C>
bool redBlackTree<T, C>::isEmpty()
{
	//if root is equal to NULL, returns true
	//else  false
	return root == NULL;
}

//uses private method accessNode
//searches the tree for the passed key
//if found, returns pointer to the node
//if not found, returns pointer to NULL
template <class T, class C>
rbNode<T, C>* redBlackTree<T, C>::accessNode(T key)
{
	//if tree is empty, returns NULL
	if (this->isEmpty())
	{
		return NULL;	//return NULL;
	}
	//else calls private method insertNode using current node as root
	else
	{
	return this->accessNode(root, key);	//return method call
	}
}

//inserts the node in the tree using binary search tree logic
//if there us a double red, uses appropriate algorithm to
// re-balance the red black tree
//calls private method insertNode
template <class T, class C>
void redBlackTree<T, C>::insertNode(T key, C value)
{
	//if tree is empty, sets node as the root
	if (this->isEmpty())
	{
		//dynamically create rbNode using passed data
		this->root = new rbNode<T, C>(key, value);

		//recolors the node to black since root is always black
		this->root->recolor();
	}
	//else calls private method insertNode using current node as root
	else
	{
	this->insertNode(this->root, key, value);	//return method call
	}
}

template <class T, class C>
void redBlackTree<T, C>::deleteNode(T key)
{	//if tree is empty, return without any deletions
	if (this->isEmpty())
	{
	return;	//returns without deletion
	}
	//else calls private method deleteNode using current node as root
	else
	{
	this->deleteNode(root, key);	//return method call
	}
}

//performs a  breadth first traversal on the tree
//used for testing purposes
//a "~" in front of a node means its colored red
//output 'n' for null nodes
template <class T, class C>
void redBlackTree<T, C>::breadthFirstTraversal()
{
	//returns without traversing if tree is empty
	if (this->isEmpty()) {return;}

	//queue used for traversal
	//pushes visited node onto the queue along with its children
	queue<rbNode<T, C>*> traversalQ;

	//boolean to determine when to stop traversing the tree
	bool done = false;

	//output root, push root on queue followed
	cout << this->root->getKey() << endl;
	traversalQ.push(this->root);

	//push NULL signifying a entering a new level in the tree
	traversalQ.push(NULL);

	//loops until done: all nodes have been visited
	while (!done)
	{
		//checks to see if NULL: entering new level
		if (traversalQ.front() == NULL)
		{
			//newline becauser of new level
			cout << "\n";

			//push NULL to back to signify when the level is to end
			traversalQ.push(NULL);
		}
		//level not complete
		else
		{
			//if has left child
			if (traversalQ.front()->getLeft() != NULL)
			{
				//red node, display with "~"
				if (traversalQ.front()->getLeft()->isColoredRed())
				{
					//output red node
					cout << "~"<< traversalQ.front()->getLeft()->getKey();
				}
				//its a black node
				else
				{
					//output black node
					cout << traversalQ.front()->getLeft()->getKey();
				}
				//push the left child onto the queue to visit its children in
				// the future
				traversalQ.push(traversalQ.front()->getLeft());
			}
			//no left child, output 'n' signifying its null
			else {cout << "n";}

			//output space for next node
			cout << " ";

			//if has right child
			if (traversalQ.front()->getRight() != NULL)
			{
				//red node, display with "~"
				if (traversalQ.front()->getRight()->isColoredRed())
				{
					//output red node
					cout << "~"<<traversalQ.front()->getRight()->getKey();
				}
				//its a black node
				else
				{
					//output black node
					cout << traversalQ.front()->getRight()->getKey();
				}
				//push the right child onto the queue to visit its children
				// in the future
				traversalQ.push(traversalQ.front()->getRight());
			}
			//no right child, output 'n' signifying its null
			else {cout << "n";}

			//output space for next node
			cout << "  ";
		}

		//pop the visited node from the queue
		traversalQ.pop();

		//checks to see if the queue only contains NULL
		//meaning, all nodes have been visited
		if (traversalQ.back() == NULL && traversalQ.front() == NULL)
		{
			done = true;	//set done to true ending the loop
		}
	}

	//output new lines
	cout << "\n\n";
}

//checks the "black height" of all external nodes
//meaning the number of black ancestors
//in red black trees, all external nodes should have the same black
// height. If all black heights the same, output message saying the
// black height and confirming its a red black tree
// else outputs message saying its not a red black tree
//for testing purposes
template <class T, class C>
bool redBlackTree<T, C>::blackHeightTraversal()
{
	//returns without traversing if tree is empty
	if (this->isEmpty()) {return true;}

	//stack used for traversal
	//pushes visited node onto the stack
	stack<rbNode<T, C>*> traversalS;

	//boolean to determine when to stop traversing the tree
	bool done = false;

	//black height that other external nodes will be compared too
	int trueBlackHeight = 0;

	//black height for a specific external node being tested
	int blackHeight = 0;

	//if root is not null increment black height: root always black
	if (root != NULL){

		//increment black height
		blackHeight++;

		//push root onto stack
		traversalS.push(this->root);
	}

	//continues to loop until the stack is empty and not done
	while (!done && !traversalS.empty())
	{
		//dynamically create pointer to the top of the stack
		rbNode<T, C>* root = traversalS.top();

		//pops the stack since its been visited
		traversalS.pop();

		//if has left child
		if (root->getLeft() != NULL)
		{
			//pushes the left child onto the stack
			traversalS.push(root->getLeft());
		}
		//left child is null: external node
		else
		{
			//if  black height is 0
			//set it to black height
			if (trueBlackHeight == 0)
			{
				//set true black height to black height
				trueBlackHeight = blackHeight;
			}
			//if black height is not equal to true black height
			//it is not a red black tree, we are done
			else if (trueBlackHeight != blackHeight)
				{
					done = true;	//done set to true
				}
		}
		//if has right child
		if (root->getRight() != NULL)
		{
			//pushes the right child onto the stack
			traversalS.push(root->getRight());
		}
		else
		{
			if (trueBlackHeight == 0) trueBlackHeight = blackHeight;
			else if (trueBlackHeight != blackHeight) break;
		}

		if (root->getLeft() == NULL && root->getRight() == NULL)
		{
			//calculate black height of next start
			if (traversalS.size() > 0)
			{
				if (traversalS.top()->isColoredRed()) blackHeight = 0;
				else blackHeight = 1;
				rbNode<T, C>* parent = traversalS.top()->getParent();
				while (parent != NULL)
				{
					if (!parent->isColoredRed()) blackHeight++;
					parent = parent->getParent();
				}
			}
		}
		else
		{
			if (!traversalS.top()->isColoredRed()) blackHeight++;
		}
	}
	if (blackHeight == trueBlackHeight)
	{
		cout << "Tree is a red-black tree with black height " << trueBlackHeight << ".\n\n";
		return true;
	}
	else
	{
		cout << "Tree is not a red-black tree.\n\n";
		return false;
	}

}

//performs a pre-order traversal on the tree
//each time a node is visited the node is added to
// vector, vector is returned at the end
template <class T, class C>
vector<rbNode<T, C>*> redBlackTree<T, C>::inOrderTraversal()
{
	//creates the vector that will be returned
	vector<rbNode<T, C>*> returnVector;

	//checks to see if tree is empty
	//if its is, return empty vector
    if (root == NULL)
    {
        return returnVector;	//return empty vector
    }

    //call private inOrderTraversal
	inOrderTraversal(root, returnVector);

	return returnVector;	//return vector

}

template <class T, class C>
rbNode<T, C>* redBlackTree<T, C>::accessNode(rbNode<T, C> *root, T key)
	{
		if(root->getKey() == key)
		{
			return root;
		}
		else if(root->getKey() > key)
		{
			if(root->getLeft() == NULL)
			{
				return NULL;
			}
			else
			{
				return this->accessNode(root->getLeft(), key);
			}
		}
		else
		{
			if(root->getRight() == NULL)
			{
				return NULL;
			}
			else
			{
				return this->accessNode(root->getRight(), key);
			}
		}
	}

template <class T, class C>
void redBlackTree<T, C>::insertNode(rbNode<T, C> *root, T key, C value)
{
	//regular BST insert
	rbNode<T, C>* insertedNode = NULL;
	if(root->getKey() == key)
	{
		//skip
	}
	else if(root->getKey() > key)
	{
		if(root->getLeft() == NULL)
		{
			insertedNode = new rbNode<T, C>(key, value);
			root->setLeft(insertedNode);
		}
		else
		{
			this->insertNode(root->getLeft(), key, value);
		}
	}
	else
	{
		if(root->getRight() == NULL)
		{
			insertedNode = new rbNode<T, C>(key, value);
			root->setRight(insertedNode);
		}
		else
		{
			this->insertNode(root->getRight(), key, value);
		}
	}
	//restore uniform black height
	if (insertedNode == NULL) return;
	this->solveDoubleRedProblem(root);
	insertedNode = NULL;
}

template <class T, class C>
void redBlackTree<T, C>::deleteNode(rbNode<T, C> *root, T key)
	{
		if(root->getKey() == key)
		{
			rbNode<T, C> *leftmostFromRight;
			if (root->getLeft() == NULL) leftmostFromRight = root->getRight();
			else if (root->getRight() == NULL) leftmostFromRight = root->getLeft();
			else if (root->getLeft()->getRight() == NULL) leftmostFromRight = root->getLeft();
			else if (root->getRight()->getLeft() == NULL) leftmostFromRight = root->getRight();
			//symmetrical after the four exceptional cases above - left implemented
			else
			{
				leftmostFromRight = root->getRight()->getLeft();
				while (leftmostFromRight->getLeft() != NULL)
				{
					leftmostFromRight = leftmostFromRight->getLeft();
				}
			}
			if (leftmostFromRight == NULL)
			{
				//reballance by checking for red-black tree deletion preliminaries in both cases
				if (root->getLeft() != NULL) root->getLeft()->recolor();
				else if (root->getRight() != NULL) root->getRight()->recolor();
				//this case is possible only if (leftmostFromRight != root->getLeft() && root->getLeft() != NULL)
				else if (!root->isColoredRed()) restoreReducedHeight(root);
			}
			else
			{
				//leftmostFromRight is always black and its single child is always red - first condition is possible bacause of the four exceptional cases
				if (leftmostFromRight->getLeft() != NULL) leftmostFromRight->getLeft()->recolor();
				else if (leftmostFromRight->getRight() != NULL) leftmostFromRight->getRight()->recolor();
				//this case is possible only if (leftmostFromRight != root->getLeft() && root->getLeft() != NULL)
				else if (!leftmostFromRight->isColoredRed()) restoreReducedHeight(leftmostFromRight);
				if (leftmostFromRight != root->getLeft() && leftmostFromRight != root->getRight()) leftmostFromRight->getParent()->setLeft(leftmostFromRight->getRight());

				//replace with originally removed node
				//include the above cases where leftmost is child of the root
				if (leftmostFromRight != root->getLeft() && root->getLeft() != NULL) leftmostFromRight->setLeft(root->getLeft());
				if (leftmostFromRight != root->getRight() && root->getRight() != NULL) leftmostFromRight->setRight(root->getRight());
				//recolor if necessary
				if (root->isColoredRed() && !leftmostFromRight->isColoredRed()) leftmostFromRight->recolor();
				if (!root->isColoredRed() && leftmostFromRight->isColoredRed()) leftmostFromRight->recolor();
			}
			if (root->getParent() != NULL)
			{
				if (root->getParent()->getLeft() == root) root->getParent()->setLeft(leftmostFromRight);
				else root->getParent()->setRight(leftmostFromRight);
			}
			else
			{
				this->root = leftmostFromRight;
				if (this->root != NULL) this->root->clearParent();
			}
			delete root;
		}
		else if(root->getKey() > key)
		{
			if(root->getLeft() == NULL)
			{
				//skip
			}
			else
			{
				this->deleteNode(root->getLeft(), key);
			}
		}
		else
		{
			if(root->getRight() == NULL)
			{
				//skip
			}
			else
			{
				this->deleteNode(root->getRight(), key);
			}
		}
	}

//similar method as public method inOrderTraversal()
//treats the passed pointer as the root
//pushes nodes onto the passed vector
template <class T, class C>
void redBlackTree<T, C>::inOrderTraversal(rbNode<T, C> *root, vector<rbNode<T, C>*> & vector)
{
	//checks to see if the passed node is null
    if (root != NULL)
    {
    	//visits left subtree first
    	inOrderTraversal(root->getLeft(), vector);

    	//pushes the node into the vector
        vector.push_back(root);

        //visits right subtree last
        inOrderTraversal(root->getRight(), vector);
    }
}

template <class T, class C>
void redBlackTree<T, C>::solveDoubleRedProblem(rbNode<T, C> *root)
	{
		//exception black child
		//if (root->getLeft() != NULL && !root->getLeft()->isColoredRed()
		//	&& root->getRight() != NULL && !root->getRight()->isColoredRed()) return;
		//if no double red problem
		if (root->isColoredRed() == false) return;
		//right rotate
		if (root == root->getParent()->getLeft())
		{
			if (root->getParent()->getRight() == NULL || !root->getParent()->getRight()->isColoredRed()) this->rightRotate(root);
			else
			{
				root->recolor();
				root->getParent()->getRight()->recolor();
				root->getParent()->recolor();
				//case real root is reached
				if (root->getParent()->getParent() == NULL)
				{
					root->getParent()->recolor();
					return;
				}
				//root is now black so check one level up
				solveDoubleRedProblem(root->getParent()->getParent());
			}
		}
		//left rotate
		else
		{
			if (root->getParent()->getLeft() == NULL || !root->getParent()->getLeft()->isColoredRed()) this->leftRotate(root);
			else
			{
				root->recolor();
				root->getParent()->getLeft()->recolor();
				root->getParent()->recolor();
				//case real root is reached
				if (root->getParent()->getParent() == NULL)
				{
					root->getParent()->recolor();
					return;
				}
				//root is now black so check one level up
				solveDoubleRedProblem(root->getParent()->getParent());
			}
		}
	}

template<class T, class C>
void redBlackTree<T, C>::leftRotate(rbNode<T, C> *root)
{
	rbNode<T, C> *parent = root->getParent();
	//avl similar case 2 for left rotation - double rotation
	if (root->getLeft() != NULL && root->getLeft()->isColoredRed())
	{
		rbNode<T, C> *badChild = root->getLeft();
		root->setLeft(badChild->getRight());
		badChild->setRight(root);
		parent->setRight(badChild);
		root = badChild;
	}
	root->recolor();
	parent->recolor();
	//parent's right -> root's left
	parent->setRight(root->getLeft());
	//root -> parent
	if (parent->getParent() != NULL)
	{
		//bind root to rest of the tree
		if (parent->getParent()->getLeft() == parent) parent->getParent()->setLeft(root);
		else parent->getParent()->setRight(root);
	}
	else
	{
		//root is real root
		this->root = root;
		this->root->clearParent();
		root = this->root;
	}
	//root's left -> parent
	root->setLeft(parent);
}

template<class T, class C>
void redBlackTree<T, C>::rightRotate(rbNode<T, C> *root)
{
	rbNode<T, C> *parent = root->getParent();
	//avl similar case 2 for right rotation - double rotation
	if (root->getRight() != NULL && root->getRight()->isColoredRed())
	{
		rbNode<T, C> *badChild = root->getRight();
		root->setRight(badChild->getLeft());
		badChild->setLeft(root);
		parent->setLeft(badChild);
		root = badChild;
	}
	root->recolor();
	parent->recolor();
	//parent's left -> root's right
	parent->setLeft(root->getRight());
	//root -> parent
	if (parent->getParent() != NULL)
	{
		//bind root to rest of the tree
		if (parent->getParent()->getLeft() == parent) parent->getParent()->setLeft(root);
		else parent->getParent()->setRight(root);
	}
	else
	{
		//root is real root
		this->root = root;
		this->root->clearParent();
		root = this->root;
	}
	//root's right -> parent
	root->setRight(parent);
}

template<class T, class C>
void redBlackTree<T, C>::restoreReducedHeight(rbNode<T, C> *root)
	{
		rbNode<T, C>* parent = root->getParent();
		if (parent == NULL) return;
		//double cases because of symmetries
		if (root == parent->getLeft())
		{
			if (parent->isColoredRed())
			{
				//first two cases
				if ((parent->getRight()->getLeft() != NULL && parent->getRight()->getLeft()->isColoredRed())
					|| (parent->getRight()->getRight() != NULL && parent->getRight()->getRight()->isColoredRed()))
				{
					//case 1.1L
					firstLRotate(parent->getRight());
				}
				else
				{
					//case 1.2L
					parent->getRight()->recolor();
					parent->recolor();
				}
			}
			else
			{
				if (parent->getRight()->isColoredRed())
				{
					//middle two cases
					if ((parent->getRight()->getLeft()->getRight() != NULL && parent->getRight()->getLeft()->getRight()->isColoredRed())
						|| (parent->getRight()->getLeft()->getLeft() != NULL && parent->getRight()->getLeft()->getLeft()->isColoredRed()))
					{
						//case 2.1.1L
						secondLRotate(parent->getRight());
					}
					else
					{
						//case 2.1.2L
						thirdLRotate(parent->getRight());
					}
				}
				else
				{
					//last two cases
					if ((parent->getRight()->getLeft() != NULL && parent->getRight()->getLeft()->isColoredRed())
						|| (parent->getRight()->getRight() != NULL && parent->getRight()->getRight()->isColoredRed()))
					{
						//case 2.2.1L
						forthLRotate(parent->getRight());
					}
					else
					{
						//case 2.2.2L
						parent->getRight()->recolor();
						if (parent->getParent() != NULL) restoreReducedHeight(parent);
						//otherwise overall black height reduced by 1
					}
				}
			}
		}
		else
		{
			if (parent->isColoredRed())
			{
				//first two cases
				if ((parent->getLeft()->getLeft() != NULL && parent->getLeft()->getLeft()->isColoredRed())
					|| (parent->getLeft()->getRight() != NULL && parent->getLeft()->getRight()->isColoredRed()))
				{
					//case 1.1R
					firstRRotate(parent->getLeft());
				}
				else
				{
					//case 1.2R
					parent->getLeft()->recolor();
					parent->recolor();
				}
			}
			else
			{
				if (parent->getLeft()->isColoredRed())
				{
					//middle two cases
					if ((parent->getLeft()->getRight()->getRight() != NULL && parent->getLeft()->getRight()->getRight()->isColoredRed())
						|| (parent->getLeft()->getRight()->getLeft() != NULL && parent->getLeft()->getRight()->getLeft()->isColoredRed()))
					{
						//case 2.1.1R
						secondRRotate(parent->getLeft());
					}
					else
					{
						//case 2.1.2R
						thirdRRotate(parent->getLeft());
					}
				}
				else
				{
					//last two cases
					if ((parent->getLeft()->getLeft() != NULL && parent->getLeft()->getLeft()->isColoredRed())
						|| (parent->getLeft()->getRight() != NULL && parent->getLeft()->getRight()->isColoredRed()))
					{
						//case 2.2.1R
						forthRRotate(parent->getLeft());
					}
					else
					{
						//case 2.2.2R
						parent->getLeft()->recolor();
						if (parent->getParent() != NULL) restoreReducedHeight(parent);
						//otherwise overall black height reduced by 1
					}
				}
			}
		}
	}

template<class T, class C>
void redBlackTree<T, C>::firstLRotate(rbNode<T, C> *root)
{
	rbNode<T, C> *parent = root->getParent();
	//avl similar case 2 for left rotation - double rotation
	if (root->getLeft() != NULL && root->getLeft()->isColoredRed())
	{
		rbNode<T, C> *badChild = root->getLeft();
		root->setLeft(badChild->getRight());
		badChild->setRight(root);
		parent->setRight(badChild);
		root = badChild;
		parent->recolor();
	}
	else
	{
		root->getRight()->recolor();
		root->recolor();
		parent->recolor();
	}
	parent->setRight(root->getLeft());
	if (parent->getParent() != NULL)
	{
		//bind root to rest of the tree
		if (parent->getParent()->getLeft() == parent) parent->getParent()->setLeft(root);
		else parent->getParent()->setRight(root);
	}
	else
	{
		//root is real root
		this->root = root;
		this->root->clearParent();
		root = this->root;
	}
	root->setLeft(parent);
}

template<class T, class C>
void redBlackTree<T, C>::secondLRotate(rbNode<T, C> *root)
{
	rbNode<T, C>* parent = root->getParent();
	rbNode<T, C>* grandParent = parent->getParent();
	//make red child always on the right
	if (root->getLeft()->getLeft() != NULL && root->getLeft()->getLeft()->isColoredRed())
	{
		rbNode<T, C> *badChild = root->getLeft()->getLeft();
		root->getLeft()->setLeft(badChild->getRight());
		badChild->setRight(root->getLeft());
		root->setLeft(badChild);
		badChild->getRight()->recolor();
		badChild->recolor();
	}
	parent->setRight(root->getLeft()->getLeft());
	root->getLeft()->setLeft(parent);
	root->setLeft(root->getLeft()->getRight());
	root->getLeft()->recolor();
	parent->getParent()->setRight(root);
	if (grandParent != NULL)
	{
		//bind root to rest of the tree
		if (grandParent->getLeft() == parent) grandParent->setLeft(parent->getParent());
		else grandParent->setRight(parent->getParent());
	}
	else
	{
		//parent is real root
		this->root = parent->getParent();
		this->root->clearParent();
	}
}

template<class T, class C>
void redBlackTree<T, C>::thirdLRotate(rbNode<T, C> *root)
{
	rbNode<T, C>* parent = root->getParent();
	root->getLeft()->recolor();
	parent->setRight(root->getLeft());
	root->recolor();
	if (parent->getParent() != NULL)
	{
		//bind root to rest of the tree
		if (parent->getParent()->getLeft() == parent) parent->getParent()->setLeft(root);
		else parent->getParent()->setRight(root);
	}
	else
	{
		//parent is real root
		this->root = root;
		this->root->clearParent();
	}
	root->setLeft(parent);
}

template <class T, class C>
void redBlackTree<T, C>::forthLRotate(rbNode<T, C> *root)
{
	rbNode<T, C> *parent = root->getParent();
	//avl similar case 2 for left rotation - double rotation
	if (root->getLeft() != NULL && root->getLeft()->isColoredRed())
	{
		rbNode<T, C> *badChild = root->getLeft();
		root->setLeft(badChild->getRight());
		badChild->setRight(root);
		parent->setRight(badChild);
		root = badChild;
		root->recolor();
	}
	else
	{
		root->getRight()->recolor();
	}
	parent->setRight(root->getLeft());
	if (parent->getParent() != NULL)
	{
		//bind root to rest of the tree
		if (parent->getParent()->getLeft() == parent) parent->getParent()->setLeft(root);
		else parent->getParent()->setRight(root);
	}
	else
	{
		//root is real root
		this->root = root;
		this->root->clearParent();
		root = this->root;
	}
	root->setLeft(parent);
}

template <class T, class C>
void redBlackTree<T, C>::firstRRotate(rbNode<T, C> *root)
{
	rbNode<T, C> *parent = root->getParent();
	//avl similar case 2 for left rotation - double rotation
	if (root->getRight() != NULL && root->getRight()->isColoredRed())
	{
		rbNode<T, C> *badChild = root->getRight();
		root->setRight(badChild->getLeft());
		badChild->setLeft(root);
		parent->setLeft(badChild);
		root = badChild;
		parent->recolor();
	}
	else
	{
		root->getLeft()->recolor();
		root->recolor();
		parent->recolor();
	}
	parent->setLeft(root->getRight());
	if (parent->getParent() != NULL)
	{
		//bind root to rest of the tree
		if (parent->getParent()->getLeft() == parent) parent->getParent()->setLeft(root);
		else parent->getParent()->setRight(root);
	}
	else
	{
		//root is real root
		this->root = root;
		this->root->clearParent();
		root = this->root;
	}
	root->setRight(parent);
}

template <class T, class C>
void redBlackTree<T, C>::secondRRotate(rbNode<T, C> *root)
{
	rbNode<T, C>* parent = root->getParent();
	rbNode<T, C>* grandParent = parent->getParent();
	//make red child always on the right
	if (root->getRight()->getRight() != NULL && root->getRight()->getRight()->isColoredRed())
	{
		rbNode<T, C> *badChild = root->getRight()->getRight();
		root->getRight()->setRight(badChild->getLeft());
		badChild->setLeft(root->getRight());
		root->setRight(badChild);
		badChild->getLeft()->recolor();
		badChild->recolor();
	}
	parent->setLeft(root->getRight()->getRight());
	root->getRight()->setRight(parent);
	root->setRight(root->getRight()->getLeft());
	root->getRight()->recolor();
	parent->getParent()->setLeft(root);
	if (grandParent != NULL)
	{
		//bind root to rest of the tree
		if (grandParent->getLeft() == parent) grandParent->setLeft(parent->getParent());
		else grandParent->setRight(parent->getParent());
	}
	else
	{
		//parent is real root
		this->root = parent->getParent();
		this->root->clearParent();
	}
}

template <class T, class C>
void redBlackTree<T, C>::thirdRRotate(rbNode<T, C> *root)
{
	rbNode<T, C>* parent = root->getParent();
	root->getRight()->recolor();
	parent->setLeft(root->getRight());
	root->recolor();
	if (parent->getParent() != NULL)
	{
		//bind root to rest of the tree
		if (parent->getParent()->getLeft() == parent) parent->getParent()->setLeft(root);
		else parent->getParent()->setRight(root);
	}
	else
	{
		//parent is real root
		this->root = root;
		this->root->clearParent();
	}
	root->setRight(parent);
}

template <class T, class C>
void redBlackTree<T, C>::forthRRotate(rbNode<T, C> *root)
{
	rbNode<T, C> *parent = root->getParent();
	//avl similar case 2 for left rotation - double rotation
	if (root->getRight() != NULL && root->getRight()->isColoredRed())
	{
		rbNode<T, C> *badChild = root->getRight();
		root->setRight(badChild->getLeft());
		badChild->setLeft(root);
		parent->setLeft(badChild);
		root = badChild;
		root->recolor();
	}
	else
	{
		root->getLeft()->recolor();
	}
	parent->setLeft(root->getRight());
	if (parent->getParent() != NULL)
	{
		//bind root to rest of the tree
		if (parent->getParent()->getLeft() == parent) parent->getParent()->setLeft(root);
		else parent->getParent()->setRight(root);
	}
	else
	{
		//root is real root
		this->root = root;
		this->root->clearParent();
		root = this->root;
	}
	root->setRight(parent);
}
