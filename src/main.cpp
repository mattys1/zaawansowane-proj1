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

	return 0;
}
