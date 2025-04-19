#ifndef __ITERATIVEBINARYTREE__
#define __ITERATIVEBINARYTREE__

#include <memory>
#include "BinaryTree.h"
#include "BinaryTreeNode.h"

using std::shared_ptr;

template <typename T>
class IterativeBinaryTree : public BinaryTree<T>
{
public:
	IterativeBinaryTree() = default;
	virtual ~IterativeBinaryTree() = default;

	IterativeBinaryTree(const IterativeBinaryTree&) = delete;
	IterativeBinaryTree(IterativeBinaryTree&&) = delete;
	IterativeBinaryTree& operator=(const IterativeBinaryTree&) = delete;
	IterativeBinaryTree& operator=(IterativeBinaryTree&) = delete;

	shared_ptr<BinaryTreeNode<T>> search(const T& value) const override;

private:
	shared_ptr<BinaryTreeNode<T>> search(shared_ptr<BinaryTreeNode<T>> node, const T& value) const;
};

template <typename T>
shared_ptr<BinaryTreeNode<T>> IterativeBinaryTree<T>::search(const T& value) const
{
	return search(this->root, value);
}

template <typename T>
shared_ptr<BinaryTreeNode<T>> IterativeBinaryTree<T>::search(shared_ptr<BinaryTreeNode<T>> node, const T& value) const
{
	while (node != nullptr && node->getData() != value) {
		if (value < node->getData()) {
			node = node->getLeft();
		} else {
			node = node->getRight();
		}
	}

	return node;
}
#endif
