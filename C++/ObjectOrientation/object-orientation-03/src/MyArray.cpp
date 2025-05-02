#include <algorithm>
#include <format>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <span>
#include <sstream>
#include <stdexcept>
#include <utility>

#include "MyArray.h"

using std::string;
using std::stringstream;
using std::unique_ptr;
using std::make_unique;
using std::initializer_list;
using std::copy;
using std::begin;
using std::end;
using std::span;
using std::exchange;
using std::move;
using std::size_t;
using std::ostringstream;
using std::equal;
using std::out_of_range;
using std::for_each;
using std::istream;
using std::ostream;

MyArray::MyArray(std::size_t size) : 
	_size{size}, 
	ptr{make_unique<int[]>(size)}
{

}

MyArray::MyArray(initializer_list<int> list) :
	_size{list.size()},
	ptr{make_unique<int[]>(list.size())}
{
	copy(begin(list), end(list), ptr.get());	
}

MyArray::MyArray(const MyArray& original) :
	_size{original.size()},
	ptr{make_unique<int[]>(original.size())}
{
	const span<const int> source{original.ptr.get(), original.size()};
	copy(begin(source), end(source), ptr.get());
}

MyArray& MyArray::operator=(const MyArray& right)
{
	MyArray temp{right};
	swap(*this, temp);

	return *this;
}

MyArray::MyArray(MyArray&& original) noexcept :
	_size{exchange(original._size, 0)},
	ptr{move(original.ptr)}
{
	
}

MyArray& MyArray::operator=(MyArray&& right) noexcept
{
	if (this != &right) {
		_size = exchange(right._size, 0);
		ptr = move(right.ptr);
	}

	return *this;
}

size_t MyArray::size() const noexcept
{
	return _size;
}
		
string MyArray::toString() const
{
	const span<const int> items{ptr.get(), _size};
	stringstream out;
	out << "{";

	for (size_t count{0}; const auto& item : items) {
		++count;
		out << item << (count < _size ? ", " : "");
	}

	out << "}";

	return out.str();
}

bool MyArray::operator==(const MyArray& right) const noexcept
{	
	const span<const int> lhs{ptr.get(), _size};
	const span<const int> rhs{right.ptr.get(), right.size()};

	return equal(begin(lhs), end(lhs), begin(rhs), end(rhs));
}

int& MyArray::operator[](std::size_t index)
{
	if (index >= _size) {
		throw out_of_range{"Index out of range"};
	}

	return ptr[index];
}
		
const int& MyArray::operator[](std::size_t index) const
{
	if (index >= _size) {
		throw out_of_range{"Index out of range"};
	}

	return ptr[index];
}

MyArray& MyArray::operator++() // pre-increment
{
	const span<int> items{ptr.get(), _size};
	for_each(begin(items), end(items), [](auto& item) { ++item; });
	return *this;
}

MyArray MyArray::operator++(int) // pos-increment
{
	MyArray temp{*this};
	++(*this);
	return temp;
}

MyArray MyArray::operator+=(int value)
{
	const span<int> items{ptr.get(), _size};
	for_each(begin(items), end(items), [value](auto& item) { item += value; });
	return *this;
}

istream& operator>>(istream& in, MyArray& a)
{
	span<int> items{a.ptr.get(), a._size};

	for (auto& item : items) {
		in >> item;
	}

	return in;
}

ostream& operator<<(ostream& out, const MyArray& a)
{
	out << a.toString();
	return out;
}

void swap(MyArray& a, MyArray& b) noexcept
{
	std::swap(a._size, b._size);
	std::swap(a.ptr, b.ptr);
}
