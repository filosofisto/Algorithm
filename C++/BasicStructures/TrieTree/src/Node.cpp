#include "Node.h"

using std::string_view;
using std::string;
using std::shared_ptr;
using std::unordered_map;
using std::size_t;

Node::Node()
{
	// key is empty string ""
	// only root element can be empty
}

Node::Node(string_view key) : key(key)
{

}

string Node::getKey() const
{
	return key;
}

unordered_map<string, shared_ptr<Node>>& Node::getChildren()
{
	return children;
}

void Node::increment()
{
	++frequency;
}

size_t Node::getFrequency() const
{
	return frequency;
}

bool Node::isValid() const
{
	return valid;
}

void Node::setValid(bool valid)
{
	this->valid = valid;
}

