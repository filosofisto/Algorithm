#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, size_t> frequency(string text)
{
	unordered_map<char, size_t> result{};

	for (char c : text) {
		result[c]++;
	}

	return result;
}

bool generateDocument(string characters, string document) 
{
	unordered_map<char, size_t> frequencyCharsInDocument = frequency(document);
	unordered_map<char, size_t> frequencyChars = frequency(characters);
	
	for (const auto& pair : frequencyCharsInDocument) {
		auto it = frequencyChars.find(pair.first);

		if (it == frequencyChars.end() 
				|| pair.second > it->second) {
			return false;
		}
	}

  return true;
}

int main()
{
	//string characters = "Bste!hetsi ogEAxperlrt x ";
	//string document   = "AlgoExpert is the Best!";
	string characters = "abcabc";
	//string document   = "aabbccc";

	string document = "";

	cout << boolalpha << generateDocument(characters, document) << endl;

	return EXIT_SUCCESS;
}
