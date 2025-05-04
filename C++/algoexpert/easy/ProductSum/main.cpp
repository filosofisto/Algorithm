#include <iostream>
#include <any>
#include <vector>
#include <typeinfo>

using namespace std;

int productSum(vector<any> array, int depth)
{
	int sum = 0;

	for (const auto& item : array) {
		if (item.type() == typeid(int)) {
			sum += any_cast<int>(item);
		}	else if (item.type() == typeid(vector<any>)) {
			sum += productSum(any_cast<vector<any>>(item), depth+1);
		}
	}

	return depth * sum;
}

int productSum(vector<any> array)
{
	return productSum(array, 1);
}

int main()
{
	vector<any> array{5, 2, vector<any>{7, -1}, 3, vector<any>{6, vector<any>{-13, 8}, 4}};
	cout << productSum(array);

	return EXIT_SUCCESS;
}
