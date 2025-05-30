#include <iostream>

using namespace std;

string caesarCypherEncryptor(string str, int key) 
{
  string result{str};

	for (auto& ch : result) {
		ch = (ch - 'a' + key) % 26 + 'a';
	}

  return result;
}

int main()
{

	cout << caesarCypherEncryptor("xyz", 2) << endl;
	cout << caesarCypherEncryptor("abc", 0) << endl;
	cout << caesarCypherEncryptor("abc", 26) << endl;
	cout << caesarCypherEncryptor("abc", 52) << endl;
	cout << caesarCypherEncryptor("abc", 57) << endl;
	cout << caesarCypherEncryptor("xyz", 25) << endl;

	return EXIT_SUCCESS;
}
