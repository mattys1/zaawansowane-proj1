#pragma once

#include <print>

/// Implementation of a double linked list using the heap
///
/// Bottom Text

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

	template<typename F>
	Node* traverse_forward_if(F predicate) {
		if(head == nullptr) {
			return nullptr;	
		}

		Node* currentElement { head };

		while(predicate(currentElement->next)) {
			currentElement = currentElement->next;		
		}

		return currentElement;
	}

public:
	/// Default Constructor
	DoubleLinkedList(void): head {nullptr} {}
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

	/// Append an item to the end of the list
	void append(const T& item) {
		if(head == nullptr) {
			head = new Node { nullptr, nullptr, item };	
			return;
		}

		Node* lastElem = traverse_forward_if([](const Node* elem) { return elem != nullptr; });
		lastElem->next = new Node { lastElem, nullptr, item };
	}
};
