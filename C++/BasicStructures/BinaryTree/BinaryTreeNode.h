#ifndef __BINARYTREENODE__
#define __BINARYTREENODE__

#include <memory>

using std::shared_ptr;
using std::make_shared;

template <typename T>
class BinaryTreeNode
{
public:
	BinaryTreeNode() = default;
	BinaryTreeNode(const T& data, shared_ptr<BinaryTreeNode<T>> parent, shared_ptr<BinaryTreeNode<T>> left, shared_ptr<BinaryTreeNode<T>> right);
	virtual ~BinaryTreeNode() = default;

	T getData() const;	
	shared_ptr<BinaryTreeNode<T>> getParent() const;
	shared_ptr<BinaryTreeNode<T>> getLeft() const;
	shared_ptr<BinaryTreeNode<T>> getRight() const;
	void setData(const T& data);
	void setParent(shared_ptr<BinaryTreeNode<T>> parent);
	void setLeft(shared_ptr<BinaryTreeNode<T>> left);
	void setRight(shared_ptr<BinaryTreeNode<T>> right);
private:
	T data;
	shared_ptr<BinaryTreeNode<T>> parent;
	shared_ptr<BinaryTreeNode<T>> left;
	shared_ptr<BinaryTreeNode<T>> right;	
};

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(
	const T& data,
	shared_ptr<BinaryTreeNode<T>> parent,
	shared_ptr<BinaryTreeNode<T>> left,
	shared_ptr<BinaryTreeNode<T>> right
) : data(data), parent(parent), left(left), right(right)
{

}

template <typename T>
T BinaryTreeNode<T>::getData() const
{
	return data;
}

template <typename T>
void BinaryTreeNode<T>::setData(const T& data)
{
	this->data = data;
}

template <typename T>
shared_ptr<BinaryTreeNode<T>> BinaryTreeNode<T>::getParent() const
{
	return parent;
}

template <typename T>
shared_ptr<BinaryTreeNode<T>> BinaryTreeNode<T>::getLeft() const
{
	return left;
}

template <typename T>
shared_ptr<BinaryTreeNode<T>> BinaryTreeNode<T>::getRight() const
{
	return right;
}

template <typename T>
void BinaryTreeNode<T>::setParent(shared_ptr<BinaryTreeNode<T>> parent)
{
	this->parent = parent;
}

template <typename T>
void BinaryTreeNode<T>::setLeft(shared_ptr<BinaryTreeNode<T>> left)
{
	this->left = left;
}

template <typename T>
void BinaryTreeNode<T>::setRight(shared_ptr<BinaryTreeNode<T>> right)
{
	this->right = right;
}
#endif

