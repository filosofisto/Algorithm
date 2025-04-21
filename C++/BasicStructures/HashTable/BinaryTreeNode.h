#ifndef __BINARYTREENODE__
#define __BINARYTREENODE__

#include <memory>

using std::shared_ptr;
using std::make_shared;

template <typename K, typename T>
class BinaryTreeNode
{
public:
	BinaryTreeNode() = default;
	BinaryTreeNode(const K& key, const T& data, shared_ptr<BinaryTreeNode<K,T>> parent, shared_ptr<BinaryTreeNode<K,T>> left, shared_ptr<BinaryTreeNode<K,T>> right);
	virtual ~BinaryTreeNode() = default;

	K getKey() const;
	T getData() const;	
	shared_ptr<BinaryTreeNode<K,T>> getParent() const;
	shared_ptr<BinaryTreeNode<K,T>> getLeft() const;
	shared_ptr<BinaryTreeNode<K,T>> getRight() const;
	void setKey(const K& key);
	void setData(const T& data);
	void setParent(shared_ptr<BinaryTreeNode<K,T>> parent);
	void setLeft(shared_ptr<BinaryTreeNode<K,T>> left);
	void setRight(shared_ptr<BinaryTreeNode<K,T>> right);
private:
	K key;
	T data;
	shared_ptr<BinaryTreeNode<K,T>> parent;
	shared_ptr<BinaryTreeNode<K,T>> left;
	shared_ptr<BinaryTreeNode<K,T>> right;	
};

template <typename K, typename T>
BinaryTreeNode<K,T>::BinaryTreeNode(
	const K& key,
	const T& data,
	shared_ptr<BinaryTreeNode<K,T>> parent,
	shared_ptr<BinaryTreeNode<K,T>> left,
	shared_ptr<BinaryTreeNode<K,T>> right
) : key(key), data(data), parent(parent), left(left), right(right)
{

}

template <typename K, typename T>
K BinaryTreeNode<K,T>::getKey() const
{
	return key;
}

template <typename K, typename T>
void BinaryTreeNode<K,T>::setKey(const K& key)
{
	this->key = key;
}

template <typename K, typename T>
T BinaryTreeNode<K,T>::getData() const
{
	return data;
}

template <typename K, typename T>
void BinaryTreeNode<K,T>::setData(const T& data)
{
	this->data = move(data);
}

template <typename K, typename T>
shared_ptr<BinaryTreeNode<K,T>> BinaryTreeNode<K,T>::getParent() const
{
	return parent;
}

template <typename K, typename T>
shared_ptr<BinaryTreeNode<K,T>> BinaryTreeNode<K,T>::getLeft() const
{
	return left;
}

template <typename K, typename T>
shared_ptr<BinaryTreeNode<K,T>> BinaryTreeNode<K,T>::getRight() const
{
	return right;
}

template <typename K, typename T>
void BinaryTreeNode<K,T>::setParent(shared_ptr<BinaryTreeNode<K,T>> parent)
{
	this->parent = parent;
}

template <typename K, typename T>
void BinaryTreeNode<K,T>::setLeft(shared_ptr<BinaryTreeNode<K,T>> left)
{
	this->left = left;
}

template <typename K, typename T>
void BinaryTreeNode<K,T>::setRight(shared_ptr<BinaryTreeNode<K,T>> right)
{
	this->right = right;
}
#endif

