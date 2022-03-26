#ifndef TREE_NODE_H
#define TREE_NODE_H
#include <iostream>
template <typename T>
class TreeNode
{
public:
	TreeNode(T i, TreeNode<T>* left = NULL, TreeNode<T>* right = NULL);
	~TreeNode();
	T item;
	TreeNode<T>* leftTree, * rightTree;
	bool search(T key);
	int depth();
private:
};
template <typename T>
TreeNode<T>::TreeNode(T i, TreeNode<T>* left, TreeNode<T>* right)
	: item(i), leftTree(left), rightTree(right)
{
}
template <typename T>
TreeNode<T>::~TreeNode()
{
	delete leftTree;
	delete rightTree;
}
template<typename T>
bool TreeNode<T>::search(T key)
{
	if (item == key)
		return true;
	bool bl = false;
	if (leftTree)
		bl = leftTree->search(key);
	bool br = false;
	if (rightTree)
		br = rightTree->search(key);
	if (bl || br)
		return true;
	return false;
}
template<typename T>
int TreeNode<T>::depth()
{
	int dl = 0;
	if (leftTree)
		dl = leftTree->depth();
	int dr = 0;
	if (rightTree)
		dr = rightTree->depth();
	if (dl < dr)
		return dr + 1;
	else
		return dl + 1;
}
#endif 