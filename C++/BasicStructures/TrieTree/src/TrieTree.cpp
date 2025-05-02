#include "TrieTree.h"

using std::string;
using std::string_view;
using std::make_shared;
using std::shared_ptr;
using std::vector;
using std::views::take;
using std::views::transform;
using std::min;

TrieTree::TrieTree()
{
	root = make_shared<Node>();
}

void TrieTree::insert(string_view key)
{
	shared_ptr<Node> node;
	shared_ptr<Node> parent = root;
	string curr;

	for (char ch : key) {
		curr += ch;
		node = searchByKey(curr, parent);
		
		if (node == nullptr) {
			node = make_shared<Node>(curr);
			parent->getChildren().insert({curr, node});
			++_size;
		}

		if (curr == key) {
			node->increment();
			node->setValid(true);
		}

		parent = node;
	}
}

shared_ptr<Node> TrieTree::searchByKey(string_view key) const
{
	shared_ptr<Node> node = root;
	string curr;

	for (char ch : key) {
		curr += ch;
		node = searchByKey(curr, node);
		if (node == nullptr) {
			break;
		}
	}

	return node;
}

shared_ptr<Node> TrieTree::searchByKey(string_view key, shared_ptr<Node> node) const
{
	auto children = node->getChildren();
	auto it = children.find(string{key});

	if (it != children.end()) {
		return it->second;
	}

	return nullptr;
}

size_t TrieTree::size() const
{
	return _size;
}

const vector<std::string> TrieTree::typeahead(std::string_view prefix, std::size_t max) const
{
	auto node = searchByKey(prefix);
	if (node == nullptr) return {};

	return collectKeysFromNode(node, max);	
}

const vector<string> TrieTree::collectKeysFromNode(shared_ptr<Node> node, size_t max) const
{
	vector<shared_ptr<Node>> nodes{};
	collectKeysFromNode(nodes, root);
	sort(nodes.begin(), nodes.end(), [](const shared_ptr<Node>& a, const shared_ptr<Node>& b) {
		return a->getFrequency() > b->getFrequency();
	});
	size_t count = min(max, nodes.size());

	auto view = nodes | take(count) | transform([](shared_ptr<Node> n) { return n->getKey(); });
	return vector(view.begin(), view.end());
}

void TrieTree::collectKeysFromNode(vector<shared_ptr<Node>>& validNodes, shared_ptr<Node> node) const
{
	auto children = node->getChildren();
	if (children.empty()) return;

	for (const auto& [key, nodePtr] : children) {
  	if (nodePtr && nodePtr->isValid()) {
    	validNodes.push_back(nodePtr);
    }

		collectKeysFromNode(validNodes, nodePtr);
	}
}
