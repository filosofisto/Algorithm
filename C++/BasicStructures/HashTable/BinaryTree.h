#ifndef __BINARYTREE__
#define __BINARYTREE__

#include <iostream>
#include <memory>
#include "BinaryTreeNode.h"

using std::cout;
using std::shared_ptr;

template <typename K, typename T>
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
	virtual void insert(const K& key, const T& value);
	virtual bool remove(const K& key);
	virtual shared_ptr<BinaryTreeNode<K,T>> min() const;
	virtual shared_ptr<BinaryTreeNode<K,T>> max() const;
	virtual shared_ptr<BinaryTreeNode<K,T>> predecessor(shared_ptr<BinaryTreeNode<K,T>> node) const;
	virtual shared_ptr<BinaryTreeNode<K,T>> sucessor(shared_ptr<BinaryTreeNode<K,T>> node) const;
	virtual shared_ptr<BinaryTreeNode<K,T>> search(const K& key) const;
	virtual bool empty() const;
	virtual size_t size() const;
	virtual shared_ptr<BinaryTreeNode<K,T>> getRoot() const;
protected:
	shared_ptr<BinaryTreeNode<K,T>> root;
	size_t count;
private:
	shared_ptr<BinaryTreeNode<K,T>> min(shared_ptr<BinaryTreeNode<K,T>> node) const;
	shared_ptr<BinaryTreeNode<K,T>> max(shared_ptr<BinaryTreeNode<K,T>> node) const;
	void inorderTreeWalker(shared_ptr<BinaryTreeNode<K,T>> node) const;
	void transplant(shared_ptr<BinaryTreeNode<K,T>> u, shared_ptr<BinaryTreeNode<K,T>> v);
	shared_ptr<BinaryTreeNode<K,T>> search(shared_ptr<BinaryTreeNode<K,T>> node, const K& key) const;
};

template <typename K, typename T>
BinaryTree<K,T>::BinaryTree() : count(0)
{

}

template <typename K, typename T>
void BinaryTree<K,T>::insert(const K& key, const T& value)
{
	auto x = root;
	auto z = make_shared<BinaryTreeNode<K,T>>();
	z->setKey(key);
	z->setData(value);
	shared_ptr<BinaryTreeNode<K,T>> y;

	while (x != nullptr) {
		y = x;
		
		if (key < x->getKey()) {
			x = x->getLeft();
		} else {
			x = x->getRight();
		}
	}

	z->setParent(y);

	if (y == nullptr) {
		root = z;
	} else if (key < y->getKey()) {
		y->setLeft(z);
	} else {
		y->setRight(z);
	}

	++count;
}

template <typename K, typename T>
bool BinaryTree<K,T>::remove(const K& key)
{
	auto z = search(key);

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

template <typename K, typename T>
bool BinaryTree<K,T>::empty() const
{
	return root == nullptr;
}

template <typename K, typename T>
size_t BinaryTree<K,T>::size() const
{
	return count;
}

template <typename K, typename T>
shared_ptr<BinaryTreeNode<K,T>> BinaryTree<K,T>::min() const
{
	return min(this->root);
}

template <typename K, typename T>
shared_ptr<BinaryTreeNode<K,T>> BinaryTree<K,T>::min(shared_ptr<BinaryTreeNode<K,T>> node) const
{
	while (node != nullptr && node->getLeft() != nullptr) {
		node = node->getLeft();
	}

	return node;
}

template <typename K, typename T>
shared_ptr<BinaryTreeNode<K,T>> BinaryTree<K,T>::max() const
{
	return max(this->root);
}

template <typename K, typename T>
shared_ptr<BinaryTreeNode<K,T>> BinaryTree<K,T>::max(shared_ptr<BinaryTreeNode<K,T>> node) const
{
	while (node != nullptr && node->getRight() != nullptr) {
		node = node->getRight();
	}

	return node;
}

template <typename K, typename T>
shared_ptr<BinaryTreeNode<K,T>> BinaryTree<K,T>::predecessor(shared_ptr<BinaryTreeNode<K,T>> node) const
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

template <typename K, typename T>
shared_ptr<BinaryTreeNode<K,T>> BinaryTree<K,T>::sucessor(shared_ptr<BinaryTreeNode<K,T>> node) const
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

template <typename K, typename T>
void BinaryTree<K,T>::inorderTreeWalker() const
{
	inorderTreeWalker(this->root);
}

template <typename K, typename T>
void BinaryTree<K,T>::inorderTreeWalker(shared_ptr<BinaryTreeNode<K,T>> node) const
{
	if (node != nullptr) {
		inorderTreeWalker(node->getLeft());
		cout << node->getData() << ' ';
		inorderTreeWalker(node->getRight());
	}
}

template <typename K, typename T>
void BinaryTree<K,T>::transplant(shared_ptr<BinaryTreeNode<K,T>> u, shared_ptr<BinaryTreeNode<K,T>> v)
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

template <typename K, typename T>
shared_ptr<BinaryTreeNode<K,T>> BinaryTree<K,T>::getRoot() const
{
	return root;
}

template <typename K, typename T>
shared_ptr<BinaryTreeNode<K,T>> BinaryTree<K,T>::search(const K& key) const
{
	return search(this->root, key);
}

template <typename K, typename T>
shared_ptr<BinaryTreeNode<K,T>> BinaryTree<K,T>::search(shared_ptr<BinaryTreeNode<K,T>> node, const K& key) const
{
	while (node != nullptr && node->getKey() != key) {
		if (key < node->getKey()) {
			node = node->getLeft();
		} else {
			node = node->getRight();
		}
	}

	return node;
}
#endif
