#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds, bool fastest)
{
	sort(redShirtSpeeds.begin(), redShirtSpeeds.end(), greater<>()); 	// descendent	
	sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());							// ascendent
	auto length = redShirtSpeeds.size();
	auto sum = 0;

	for (int i = 0; i < length; ++i) {
		sum += max(redShirtSpeeds[i], blueShirtSpeeds[i]);
	}

	return sum;
}

int main()
{
	vector<int> red{5,5,3,9,2};
	vector<int> blue{3,6,7,2,1};
	auto fastest = true;
 
	cout << tandemBicycle(red, blue, fastest);

	return EXIT_SUCCESS;
}

