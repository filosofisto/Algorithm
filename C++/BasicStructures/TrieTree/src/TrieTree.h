#ifndef __TRIETREE__
#define __TRIETREE__

#include <string>
#include <string_view>
#include <vector>
#include <memory>
#include <ranges>
#include <algorithm>

#include "Node.h"

class TrieTree
{
	public:
		TrieTree();
		virtual ~TrieTree() = default;

		void insert(std::string_view key);
		std::shared_ptr<Node> searchByKey(std::string_view key) const;
		size_t size() const;
		const std::vector<std::string> typeahead(std::string_view prefix, std::size_t max) const;
	private:
		std::shared_ptr<Node> searchByKey(std::string_view key, std::shared_ptr<Node> node) const;
		const std::vector<std::string> collectKeysFromNode(std::shared_ptr<Node> node, std::size_t max) const;
		void collectKeysFromNode(std::vector<std::shared_ptr<Node>>& validNodes, std::shared_ptr<Node> node) const;

		std::shared_ptr<Node> root;
		std::size_t _size{0};
};

#endif
