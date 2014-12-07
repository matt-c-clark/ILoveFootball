#include "RedBlackTree.cpp"
using namespace std;

int main()
{
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

	return 0;
}
