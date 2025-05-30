#include <iostream>

using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
 public:
  int value;
  LinkedList* next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList* middleNode(LinkedList* linkedList) {
  LinkedList* current = linkedList;
	int size{0};

	// calculate the size
	while (current != nullptr) {
		++size;
		current = current->next;
	}

	// calculate the middle element
	current = linkedList;
	int middle{size/2};

	// move to the middle element
	int pos = 1;
	while (current != nullptr && pos++ <= middle) {
		current = current->next;
	}

	return current;
}

void print(LinkedList* linkedList)
{
	LinkedList* current = linkedList;

	while (current != nullptr) {
		cout << current->value << "->"; 
		current = current->next;	
	}

	cout << "nullptr\n";
}

int main()
{
	LinkedList* _1 = new LinkedList{2};
	LinkedList* _2 = new LinkedList{7};
	LinkedList* _3 = new LinkedList{3};
	LinkedList* _4 = new LinkedList{5};
	LinkedList* _5 = new LinkedList{7};
	
	_1->next = _2;
	_2->next = _3;
	_3->next = _4;
	_4->next = _5;

	print(_1);

	print(middleNode(_1));

	return EXIT_SUCCESS;
}

