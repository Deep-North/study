#pragma once
#include <iostream>

class List1 {
public:

	class Node {
	public:
		int data;
		Node*next;


		Node(int data) {
			this->data = data;
			this->next = 0;
		}

	};

	Node * head;


	List1() {
		head = 0;
	};

	void add(int data) {
		if (!head) {
			head = new Node(data);
		}
		else {
			Node* tmp = head;
			head = new Node(data);
			head->next = tmp;
		}
	};


};