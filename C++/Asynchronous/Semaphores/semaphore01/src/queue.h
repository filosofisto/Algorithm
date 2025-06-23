#ifndef __QUEUE__
#define __QUEUE__

#include <semaphore>
#include <vector>
#include <mutex>

template <typename T>
class Queue
{
	public:
		Queue(std::size_t capacity) : capacity(capacity), buffer(capacity), sem_full(0), sem_empty(capacity) { }

		void push(const T& item)
		{
			sem_empty.acquire();

			std::unique_lock<std::mutex> lock{mtx};

			buffer[tail] = item;
			tail = next(tail);

			lock.unlock();

			sem_full.release();
		}

		bool try_push(const T& item)
		{
			if (!sem_empty.try_acquire()) {
				return false;
			}

			std::unique_lock<std::mutex> lock{mtx};

			buffer[tail] = item;
			tail = next(tail);

			lock.unlock();

			sem_full.release();

			return true;
		}

		void pop(T& item)
		{
			sem_full.acquire();

			std::unique_lock<std::mutex> lock{mtx};

			item = buffer[head];
			head = next(head);

			lock.unlock();

			sem_empty.release();
		}

		bool try_pop(T& item)
		{
			if (!sem_full.try_acquire()) {
				return false;
			}

			std::unique_lock<std::mutex> lock{mtx};

			item = buffer[head];
			head = next(head);

			lock.unlock();

			sem_empty.release();

			return true;
		}

	private:
		[[nodiscard]] std::size_t next(std::size_t idx) const noexcept
		{
			return ((idx + 1) % capacity);
		}

		std::mutex mtx;
		std::counting_semaphore<> sem_empty;
		std::counting_semaphore<> sem_full;
		std::size_t head{0};
		std::size_t tail{0};
		std::size_t capacity;
		std::vector<T> buffer;
};

#endif
