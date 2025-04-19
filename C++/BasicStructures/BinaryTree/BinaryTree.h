#ifndef __BINARYTREE__
#define __BINARYTREE__

#include <iostream>
#include <memory>
#include "BinaryTreeNode.h"

using std::cout;
using std::shared_ptr;

template <typename T>
class BinaryTree
{
public:
	BinaryTree();
	virtual ~BinaryTree() = default;

	BinaryTree(const BinaryTree&) = delete;
	BinaryTree(BinaryTree&&) = delete;
	BinaryTree& operator=(const BinaryTree&) = delete;
	BinaryTree& operator=(BinaryTree&) = delete;

	void inorderTreeWalker() const;
	virtual void insert(const T& value);
	virtual bool remove(const T& value);
	virtual shared_ptr<BinaryTreeNode<T>> min() const;
	virtual shared_ptr<BinaryTreeNode<T>> max() const;
	virtual shared_ptr<BinaryTreeNode<T>> predecessor(shared_ptr<BinaryTreeNode<T>> node) const;
	virtual shared_ptr<BinaryTreeNode<T>> sucessor(shared_ptr<BinaryTreeNode<T>> node) const;
	virtual shared_ptr<BinaryTreeNode<T>> search(const T& value) const = 0;
	virtual bool empty() const;
	virtual size_t size() const;
	virtual shared_ptr<BinaryTreeNode<T>> getRoot() const;
protected:
	shared_ptr<BinaryTreeNode<T>> root;
	size_t count;
private:
	shared_ptr<BinaryTreeNode<T>> min(shared_ptr<BinaryTreeNode<T>> node) const;
	shared_ptr<BinaryTreeNode<T>> max(shared_ptr<BinaryTreeNode<T>> node) const;
	void inorderTreeWalker(shared_ptr<BinaryTreeNode<T>> node) const;
	void transplant(shared_ptr<BinaryTreeNode<T>> u, shared_ptr<BinaryTreeNode<T>> v);
};

template <typename T>
BinaryTree<T>::BinaryTree() : count(0)
{

}

template <typename T>
void BinaryTree<T>::insert(const T& value)
{
	auto x = root;
	auto z = make_shared<BinaryTreeNode<T>>();
	z->setData(value);
	shared_ptr<BinaryTreeNode<T>> y;

	while (x != nullptr) {
		y = x;
		
		if (value < x->getData()) {
			x = x->getLeft();
		} else {
			x = x->getRight();
		}
	}

	z->setParent(y);

	if (y == nullptr) {
		root = z;
	} else if (value < y->getData()) {
		y->setLeft(z);
	} else {
		y->setRight(z);
	}

	++count;
}

template <typename T>
bool BinaryTree<T>::remove(const T& value)
{
	auto z = search(value);

	if (z == nullptr) return false;

	if (z->getLeft() == nullptr) {
		transplant(z, z->getRight());
	} else if (z->getRight() == nullptr) {
		transplant(z, z->getLeft());
	} else {
		auto y = min(z->getRight());
		if (y != z->getRight()) {
			transplant(y, y->getRight());
			y->setRight(z->getRight());
			y->getRight()->setParent(y);
		}

		transplant(z, y);
		y->setLeft(z->getLeft());
		y->getLeft()->setParent(y);
	}

	--count;
	return true;
}

template <typename T>
bool BinaryTree<T>::empty() const
{
	return root == nullptr;
}

template <typename T>
size_t BinaryTree<T>::size() const
{
	return count;
}

template <typename T>
shared_ptr<BinaryTreeNode<T>> BinaryTree<T>::min() const
{
	return min(this->root);
}

template <typename T>
shared_ptr<BinaryTreeNode<T>> BinaryTree<T>::min(shared_ptr<BinaryTreeNode<T>> node) const
{
	while (node != nullptr && node->getLeft() != nullptr) {
		node = node->getLeft();
	}

	return node;
}

template <typename T>
shared_ptr<BinaryTreeNode<T>> BinaryTree<T>::max() const
{
	return max(this->root);
}

template <typename T>
shared_ptr<BinaryTreeNode<T>> BinaryTree<T>::max(shared_ptr<BinaryTreeNode<T>> node) const
{
	while (node != nullptr && node->getRight() != nullptr) {
		node = node->getRight();
	}

	return node;
}

template <typename T>
shared_ptr<BinaryTreeNode<T>> BinaryTree<T>::predecessor(shared_ptr<BinaryTreeNode<T>> node) const
{
	if (node->getLeft() != nullptr) {
		return max(node->getLeft());
	} else {
		auto y = node->getParent();
		while (y != nullptr && node == y->getLeft()) {
			node = y;
			y = y->getParent();
		}

		return y;
	}
}

template <typename T>
shared_ptr<BinaryTreeNode<T>> BinaryTree<T>::sucessor(shared_ptr<BinaryTreeNode<T>> node) const
{
	if (node->getRight() != nullptr) {
		return min(node->getRight());
	} else {
		// find the lowest ancestor of x whose left child is an ancestor of x
		auto y = node->getParent();
		while (y != nullptr && node == y->getRight()) {
			node = y;
			y = y->getParent();
		}

		return y;
	}
}

template <typename T>
void BinaryTree<T>::inorderTreeWalker() const
{
	inorderTreeWalker(this->root);
}

template <typename T>
void BinaryTree<T>::inorderTreeWalker(shared_ptr<BinaryTreeNode<T>> node) const
{
	if (node != nullptr) {
		inorderTreeWalker(node->getLeft());
		cout << node->getData() << ' ';
		inorderTreeWalker(node->getRight());
	}
}

template <typename T>
void BinaryTree<T>::transplant(shared_ptr<BinaryTreeNode<T>> u, shared_ptr<BinaryTreeNode<T>> v)
{
	if (u->getParent() == nullptr) {
		root = v;
	} else if (u->getParent() != nullptr && u == u->getParent()->getLeft()) {
		u->getParent()->setLeft(v);
	} else if (u->getParent() != nullptr) {
		u->getParent()->setRight(v);
	}

	if (v != nullptr) {
		v->setParent(u->getParent());
	}
}

template <typename T>
shared_ptr<BinaryTreeNode<T>> BinaryTree<T>::getRoot() const
{
	return root;
}
#endif
