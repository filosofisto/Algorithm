#include <iostream>

using namespace std;

class LinkedList
{
	public:
		LinkedList(int value) : value{value} { }

		int value;
		LinkedList* next = nullptr;
};

LinkedList* removeDuplicatesFromLinkedList(LinkedList* linkedList)
{
	LinkedList* before = linkedList;
	LinkedList* current = linkedList->next;

	while (current != nullptr) {
		if (before->value == current->value) {
			before->next = current->next;
		} else {
			before = current;
		}

		current = before->next;
	}

	return linkedList;	
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
	LinkedList* _1 = new LinkedList(1);
	LinkedList* _2 = new LinkedList(2);
	LinkedList* _3 = new LinkedList(3);
	LinkedList* _4 = new LinkedList(4);
	LinkedList* _5 = new LinkedList(4);
	LinkedList* _6 = new LinkedList(4);
	LinkedList* _7 = new LinkedList(5);
	LinkedList* _8 = new LinkedList(6);
	LinkedList* _9 = new LinkedList(6);

	_1->next = _2;
	_2->next = _3;
	_3->next = _4;
	_4->next = _5;
	_5->next = _6;
	_6->next = _7;
	_7->next = _8;
	_8->next = _9;

	cout << "ORIGINAL:\n";
	print(_1);

	cout << "\nAfter remove duplicates:\n";
	LinkedList *result = removeDuplicatesFromLinkedList(_1);
	print(result);
	
	return EXIT_SUCCESS;
}
