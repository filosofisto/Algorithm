#ifndef __NODE__
#define __NODE__

#include <string>
#include <string_view>
#include <unordered_map>
#include <memory>

class Node
{
	public:
		Node();
		Node(std::string_view key);
		virtual ~Node() = default;

		std::string getKey() const;
		std::unordered_map<std::string, std::shared_ptr<Node>>& getChildren();
		void increment();
		std::size_t getFrequency() const;
		bool isValid() const;
		void setValid(bool valid);
	private:
		std::string key;
		std::size_t frequency{0};
		std::unordered_map<std::string, std::shared_ptr<Node>> children{};
		bool valid{false};
};

#endif
