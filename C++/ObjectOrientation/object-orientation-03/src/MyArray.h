#ifndef __MYARRAY__
#define __MYARRAY__

#include <iostream>
#include <initializer_list>
#include <string>
#include <memory>

class MyArray final
{
	friend std::istream& operator>>(std::istream& in, MyArray& a);
	friend void swap(MyArray& a, MyArray& b) noexcept;

	public:
		explicit MyArray(std::size_t size);
		explicit MyArray(std::initializer_list<int> list);
		MyArray(const MyArray& original);
		MyArray& operator=(const MyArray& right);
		MyArray(MyArray&& original) noexcept;
		MyArray& operator=(MyArray&& right) noexcept;
		~MyArray() = default;

		std::size_t size() const noexcept;
		std::string toString() const;

		bool operator==(const MyArray& right) const noexcept;
		int& operator[](std::size_t index);
		const int& operator[](std::size_t index) const;
		explicit operator bool() const noexcept 
		{
			return size() != 0;
		}
		MyArray& operator++(); 		// pre-increment
		MyArray operator++(int); 	// pos-increment
		MyArray operator+=(int value);

	private:
		std::size_t _size{0};
		std::unique_ptr<int[]> ptr;
};

std::ostream& operator<<(std::ostream& out, const MyArray& a);

#endif
