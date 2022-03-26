#include <iostream>
#include "TreeNode.h"
using namespace std;

int alternating_sum(int n)
{
	if (n < 1)
		return 0;
	int sum = 0;
	if (n % 2 == 1) sum += n;
	else sum -= n;
	return sum + alternating_sum(n - 1);
}

template <typename T>
void print(TreeNode<T>* tree) {
	if (tree->item != NULL)
		cout << tree->item << " ";
	if (tree->leftTree != NULL)
		print(tree->leftTree);
	if (tree->rightTree != NULL)
		print(tree->rightTree);
}

template<typename T>
TreeNode<T>* search(T key, TreeNode<T>* tree)
{
	if (tree == NULL) // key not in tree, insert
		tree = new TreeNode<T>(key);
	else if (key < tree->item)
		tree->leftTree = search(key, tree->leftTree);
	else if (key > tree->item)
		tree->rightTree = search(key, tree->rightTree);
	return tree;
}


int main() {
	//leaf nodes
	//TreeNode<int>* i3 = new TreeNode<int>(3);
	//TreeNode<int>* i7 = new TreeNode<int>(7);
	//TreeNode<int>* i12 = new TreeNode<int>(12);
	//TreeNode<int>* i19 = new TreeNode<int>(19);
	//TreeNode<int>* i28 = new TreeNode<int>(28);
	//TreeNode<int>* i37 = new TreeNode<int>(37);
	//TreeNode<int>* i50 = new TreeNode<int>(50);
	//TreeNode<int>* i67 = new TreeNode<int>(67);
	////nodes on level 2
	//TreeNode<int>* i4 = new TreeNode<int>(4, i3, i7);
	//TreeNode<int>* i18 = new TreeNode<int>(18, i12, i19);
	//TreeNode<int>* i31 = new TreeNode<int>(31, i28, i37);
	//TreeNode<int>* i59 = new TreeNode<int>(59, i50, i67);
	////nodes on level 1
	//TreeNode<int>* i10 = new TreeNode<int>(10, i4, i18);
	//TreeNode<int>* i40 = new TreeNode<int>(40, i31, i59);
	////root node
	//TreeNode<int>* i25 = new TreeNode<int>(25, i10, i40);
	//print(i25);
	
	//leaf nodes
	TreeNode<int>* i20 = new TreeNode<int>(20);
	TreeNode<int>* i150 = new TreeNode<int>(150);
	TreeNode<int>* i412 = new TreeNode<int>(412);
	TreeNode<int>* i718 = new TreeNode<int>(718);
	//branch nodes
	TreeNode<int>* i111 = new TreeNode<int>(111, i20, i150);
	TreeNode<int>* i531 = new TreeNode<int>(531, i412, i718);
	//root node
	TreeNode<int>* i212 = new TreeNode<int>(212, i111, i531);
	print(i212);
	cout << "The complexity of the balanced BST is O(N log N)" << endl;
	return 0;
}