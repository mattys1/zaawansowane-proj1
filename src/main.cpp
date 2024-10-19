#include <print>

#include "doublelinkedlist.hpp"

int main (int argc, char *argv[]) {
	DoubleLinkedList<int> list;

	list.display();
	std::println();

	list.append(1);
	list.append(2);
	list.append(3);

	list.display();
	std::println();

	list.prepend(-1);
	list.prepend(-2);
	list.prepend(-3);

	list.display();
	std::println();

	list.insert(111, 0);
	list.insert(222, 3);
	list.insert(333, 4);
	list.insert(999, 8);

	list.display();
	std::println();

	list.pop_at(0);
	list.pop_at(3);
	list.pop_at(2);
	list.pop_at(5);

	list.display();
	std::println();

	list.rdisplay();
	std::println();

	std::println("element at index 3: {}", list[3]);
	list[3] = 13131;
	std::println("element at index 3 after change: {}", list[3]);

	list.clear();
	list.display();
	std::println();

	list.append(22);
	list.display();
	std::println();

	return 0;
}
