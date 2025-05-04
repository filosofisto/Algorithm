#include <iostream>

using namespace std;

string caesarCypherEncryptor(string str, int key) 
{
  string result{str};
	char newChar;

	for (auto& ch : result) {
		newChar = ch + key;
		if (newChar > 122) {
			newChar = 96 + newChar % 122;
		}

		ch = newChar;
	}

  return result;
}

int main()
{
	cout << caesarCypherEncryptor("z", 1) << endl;

	return EXIT_SUCCESS;
}
