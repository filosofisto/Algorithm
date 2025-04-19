#ifndef __RECURSIVEBINARYTREE__
#define __RECURSIVEBINARYTREE__

#include <memory>
#include "BinaryTree.h"
#include "BinaryTreeNode.h"

using std::shared_ptr;

template <typename T>
class RecursiveBinaryTree : public BinaryTree<T>
{
public:
	RecursiveBinaryTree() = default;
	virtual ~RecursiveBinaryTree() = default;

	RecursiveBinaryTree(const RecursiveBinaryTree&) = delete;
	RecursiveBinaryTree(RecursiveBinaryTree&&) = delete;
	RecursiveBinaryTree& operator=(const RecursiveBinaryTree&) = delete;
	RecursiveBinaryTree& operator=(RecursiveBinaryTree&) = delete;

	shared_ptr<BinaryTreeNode<T>> search(const T& value) const override;

private:
	shared_ptr<BinaryTreeNode<T>> search(shared_ptr<BinaryTreeNode<T>> node, const T& value) const;
};

template <typename T>
shared_ptr<BinaryTreeNode<T>> RecursiveBinaryTree<T>::search(const T& value) const
{
	return search(this->root, value);
}

template <typename T>
shared_ptr<BinaryTreeNode<T>> RecursiveBinaryTree<T>::search(shared_ptr<BinaryTreeNode<T>> node, const T& value) const
{
	if (node == nullptr || node->getData() == value) return node;
	
	if (value < node->getData()) {
		return search(node->getLeft(), value);
	} else {
		return search(node->getRight(), value);
	}
}
#endif
