#include <iostream>
#include <latch>
#include <vector>
#include <numeric>
#include <thread>

int main()
{
	int sum{0};

	std::latch map_latch{3};

	auto map_function = [&](std::vector<int>& numbers, int start, int end) {
		for (int i{start}; i < end; ++i) {
			numbers[i] *= 2;
		}

		map_latch.count_down();
	};

	std::latch reduce_latch{1};

	auto reduce_function = [&](const std::vector<int>& numbers, int& sum) {
		map_latch.wait();
		sum = std::accumulate(numbers.begin(), numbers.end(), 0);
		reduce_latch.count_down();		
	};

	std::vector<int> data{1,2,3,4,5,6,7,8,9,10,11,12};
	
	std::jthread sum_thread1{map_function, std::ref(data), 0, 4};
	std::jthread sum_thread2{map_function, std::ref(data), 4, 8};
	std::jthread sum_thread3{map_function, std::ref(data), 8, 12};
	std::jthread reduce_thread{reduce_function, std::ref(data), std::ref(sum)}; 
	
	reduce_latch.wait();
	std::cout << "Sum: " << sum << std::endl;

	return EXIT_SUCCESS;
}
