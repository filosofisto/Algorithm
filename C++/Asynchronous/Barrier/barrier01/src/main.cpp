#include <iostream>
#include <barrier>
#include <latch>
#include <print>
#include <vector>
#include <numeric>
#include <thread>

void multiply_add_latch()
{
	const int NUM_THREADS{3};
	
	std::latch map_latch{NUM_THREADS};
	std::latch reduce_latch{1};

	std::vector<int> numbers(3000);
	int sum{};
	std::iota(numbers.begin(), numbers.end(), 0);

	auto map_thread = [&](std::vector<int>& numbers, int start, int end)
	{
		std::println("map_thread {} processing data from {} to {}", std::this_thread::get_id(), start, end);

		for (int i{start}; i < end; ++i) {
			numbers[i] *= 2;
		}

		map_latch.count_down();
	};

	auto reduce_thread = [&](const std::vector<int>& numbers, int& sum) 
	{
		map_latch.wait();
		sum = std::accumulate(numbers.begin(), numbers.end(), 0);

		reduce_latch.count_down();
	};

	for (int i{0}; i < NUM_THREADS; ++i) {
		std::jthread t(map_thread, std::ref(numbers), 1000*i, 1000*(i+1));
	}

	std::jthread t(reduce_thread, numbers, std::ref(sum));
	reduce_latch.wait();
	std::println("All threads finished. The total sum is: {}", sum);
}

void multiply_add_barrier()
{
	const int NUM_THREADS{3};
	std::vector<int> sum(3, 0);
	std::vector<int> numbers(3000);
	std::iota(numbers.begin(), numbers.end(), 0);

	std::barrier map_barrier{NUM_THREADS};

	auto worker_thread = [&](std::vector<int>& numbers, int start, int end, int id)
	{
		std::println("Thread {} is starting...", id);

		for (int i{start}; i < end; ++i) {
			numbers[i] *= 2;
		}

		map_barrier.arrive_and_wait();

		for (int i{start}; i < end; ++i) {
			sum[id] += numbers[i];
		}

		map_barrier.arrive();
	};

	std::vector<std::jthread> workers;
	for (int i{0}; i < NUM_THREADS; ++i) {
		workers.emplace_back(worker_thread, std::ref(numbers), 1000*i, 1000*(i+1), i);
	}

	for (auto& t : workers) {
		t.join();
	}

	std::println("All threads finished. The total sum is: {}", std::accumulate(sum.begin(), sum.end(), 0));
}	

int main()
{
	std::cout << "Multiplying and reduce vector using latches...\n";
	multiply_add_latch();

	std::cout << "Multiplying and reduce vector using barrier...\n";
	multiply_add_barrier();

	return EXIT_SUCCESS;
}
