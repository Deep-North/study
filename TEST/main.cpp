#include <iostream>
#define	  stop

class List {
public:

	class Node {
	public:
		int m_Data;
		Node*pNext;


		Node(int m_Data) {
			this->m_Data = m_Data;
			this->pNext = 0;
		}
		~Node() {
			this->pNext = nullptr;
		};
	};

	Node * head;


	List() {
		head = 0;
	};

	void add(int m_Data) {
		if (!head) {
			head = new Node(m_Data);
		}
		else {
			Node* tmp = head;
			head = new Node(m_Data);
			head->pNext = tmp;
		}
	};
};




int main() {

	std::cout << "Test" << std::endl;

	List list1;
	list1.add(10);
	list1.add(20);
	list1.add(30);
	list1.add(40);

	List list2;
	list2.add(10);
	list2.add(15);
	list2.add(20);
	list2.add(25);

	//merge
	List merg;
	List::Node *tmp;
	tmp = list1.head;
	while (tmp) {
		//std::cout << tmp->m_Data << std::endl;
		List::Node *tmp2 = merg.head;
		bool isset = false;

		while (tmp2) {
			if (tmp2->m_Data == tmp->m_Data) {
				//isset
				isset = true;
				break;
			}
			tmp2 = tmp2->pNext;
		}
		if (!isset) {
			merg.add(tmp->m_Data);
		}
		tmp = tmp->pNext;
	}

	tmp = list2.head;
	while (tmp) {
		//std::cout << tmp->m_Data << std::endl;
		List::Node *tmp2 = merg.head;
		bool isset = false;

		while (tmp2) {
			if (tmp2->m_Data == tmp->m_Data) {
				//isset
				isset = true;
				break;
			}
			tmp2 = tmp2->pNext;
		}
		if (!isset) {
			merg.add(tmp->m_Data);
		}
		tmp = tmp->pNext;
	}

	//print set
	tmp = merg.head;
	while (tmp) {
		std::cout << tmp->m_Data << std::endl;
		tmp = tmp->pNext;
	}
	stop
	return 0;
}