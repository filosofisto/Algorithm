#ifndef __QUEUE__
#define __QUEUE__

#include <condition_variable>
#include <vector>
#include <mutex>

template <typename T>
class Queue
{
	public:
		Queue(std::size_t capacity) : capacity(capacity), buffer(capacity) { }

		void push(const T& item)
		{
			std::unique_lock<std::mutex> lock{mtx};
			not_full.wait(lock, [this] { return !isFull(); });

			buffer[tail] = item;
			tail = next(tail);

			lock.unlock();
			not_empty.notify_one();
		}

		bool try_push(const T& item)
		{
			std::unique_lock<std::mutex> lock{mtx, std::try_to_lock};
			if (!lock || isFull()) {
				return false;
			}

			buffer[tail] = item;
			tail = next(tail);

			lock.unlock();
			not_empty.notify_one();

			return true;
		}

		void pop(T& item)
		{
			std::unique_lock<std::mutex> lock{mtx};
			not_empty.wait(lock, [this] { return !isEmpty(); });

			item = buffer[head];
			head = next(head);

			lock.unlock();

			not_full.notify_one();
		}

		bool try_pop(T& item)
		{
			std::unique_lock<std::mutex> lock{mtx, std::try_to_lock};
			if (!lock || isEmpty()) {
				return false;
			}

			item = buffer[head];
			head = next(head);

			lock.unlock();
			not_empty.notify_one();

			return true;
		}

	private:
		[[nodiscard]] std::size_t next(std::size_t idx) const noexcept
		{
			return ((idx + 1) % capacity);
		}

		[[nodiscard]] bool isEmpty() const noexcept
		{
			return head == tail;
		}

		[[nodiscard]] bool isFull() const noexcept
		{
			return next(tail) == head;
		}

		std::mutex mtx;
		std::condition_variable not_empty;
		std::condition_variable not_full;
		std::size_t head{0};
		std::size_t tail{0};
		std::size_t capacity;
		std::vector<T> buffer;
};

#endif
