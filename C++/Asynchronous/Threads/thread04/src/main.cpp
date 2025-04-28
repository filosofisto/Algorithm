#include <iostream>
#include <thread>
#include <syncstream>
#include <functional>
#include <vector>

using namespace std;

#define sync_cout osyncstream(cout)

void funcByValue(const string& str, int val)
{
	sync_cout << "str: " << str << ", val: " << val << endl;		
}

void modifyValues(string& str, int& val)
{
	str += "(Thread)";
	val++;
}

void printVector(const vector<int>& v)
{
	sync_cout << "Vector: ";
	for (auto& item : v) {
		sync_cout << item << " ";
	}
	sync_cout << endl;
}

int main()
{
	string str{"Passing by value"};
	thread t1{funcByValue, str, 1};

	string strRef{"Passing by reference"};
	int val = 1;
	thread t2{modifyValues, ref(strRef), ref(val)};

	vector<int> v{1,2,3,4,5};
	thread t3{printVector, cref(v)};

	string lambda_capture{"Lambda capture parameter"};
	thread t4{[&](){
		sync_cout << lambda_capture << endl;
	}};

	t1.join();
	t2.join();	
	t3.join();
	t4.join();

	cout << strRef << ", val: " << val << endl;

	return EXIT_SUCCESS;
}

