#pragma once

#include <print>

/// Implementation of a double linked list using the heap
///
/// As this is a template, the class can't be split into a header and implementation file.

template<typename T>
class DoubleLinkedList {
private:
	struct Node {
		Node* previous;
		Node* next;
		T contents;

		Node(Node* oPrevious, Node* oNext, T oContents): 
			previous { oPrevious },
			next { oNext },
			contents { oContents } {}

		~Node(void) {
			delete next;
		}
	};

	Node* head;
	Node* tail;

	Node* get_node_at(size_t index) {
		Node* currentNode { head };
		for(size_t i {}; i < index; i++) {
			currentNode = currentNode->next;
		}

		return currentNode;
	}

public:
	/// Default Constructor
	DoubleLinkedList(void): head { nullptr }, tail { nullptr } {}
	~DoubleLinkedList(void) {
		delete head;
	}

	/// Print the entire list
	void display(void) {
		Node* currentElement { head };
		std::print("{{");

		while(true) {
			if(currentElement == nullptr) {
				std::print("}}");
				return;
			}

			std::print("{}, ", currentElement->contents);

			currentElement = currentElement->next;
		}
	}

	/// Print the entire list in reverse order
	void rdisplay(void) {
		Node* currentElement { tail };
		std::print("{{");

		while(true) {
			if(currentElement == nullptr) {
				std::print("}}");
				return;
			}

			std::print("{}, ", currentElement->contents);

			currentElement = currentElement->previous;
		}
	}

	/// Append an item to the end of the list
	void append(const T& item) {
		if(head == nullptr) {
			head = new Node { nullptr, nullptr, item };	
			tail = head;
			return;
		}

		tail = new Node { tail, nullptr, item };
		tail->previous->next = tail;
	}

	/// Prepend an item to the beggining of the list
	void prepend(const T& item) {
		if(head == nullptr) {
			head = new Node { nullptr, nullptr, item };	
			tail = head;
			return;
		}

		head = new Node { nullptr, head, item };
		head->next->previous = head;
	}

	/// Insert an item at a certain index
	void insert(const T& item, size_t index) {
		Node* atInsertion { get_node_at(index) };
		Node* beforeInsertion { atInsertion->previous };

		if(beforeInsertion == nullptr) {
			prepend(item);
			return;
		} 

		beforeInsertion->next = atInsertion->previous = new Node(beforeInsertion, atInsertion, item);
	}

	/// Remove an element from the tail of the list
	void pop(void) {
		Node* newTail { tail->previous };
		delete tail;

		tail = newTail;
	}

	/// Remove an element from the head of the list
	void rpop(void) {
		Node* newHead { head->next };
		head->next = nullptr;
		delete head;

		head = newHead;
		head->previous = nullptr;
	}

	/// Remove an element at a given index
	void pop_at(size_t index) {
		Node* toPop { get_node_at(index) };
		if(toPop == head) {
			rpop();
			return;
		} else if(toPop == tail) {
			pop();
			return;
		}

		toPop->previous->next = toPop->next;
		toPop->next->previous = toPop->previous;
		toPop->next = nullptr;

		delete toPop;
	}

	/// Returns the address of the contents at a specific index
	T& operator[](size_t index) {
		return get_node_at(index)->contents;
	}

	/// Display an element at `index`, index can be offset by `offset`
	void display_at(size_t index, size_t offset = 0) {
		std::print("{}", get_node_at(index + offset)->contents);
	}

	/// Clear the memory allocated by the list.
	void clear() {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
};
