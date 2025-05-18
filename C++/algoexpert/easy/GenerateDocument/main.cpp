#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <iterator>

using namespace std;

bool generateDocument(string characters, string document) 
{
	unordered_map<char, size_t> frequencyCharsInDocument{};
	for (char c : document) {
		frequencyCharsInDocument[c]++;
	}

	unordered_map<char, size_t> frequencyChars{};
	for (char c : characters) {
		frequencyChars[c]++;
	}
	
	for (const auto& pair : frequencyChars) {
		auto it = frequencyCharsInDocument.find(pair.first);

		if (it == frequencyCharsInDocument.end() 
				|| pair.second < it->second) {
			return false;
		}
	}

  return true;
}

int main()
{

	return EXIT_SUCCESS;
}
