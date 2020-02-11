#include "List.h"

List::List() : Head(Node::HEAD), Tail(Node::TAIL) {						//конструктор по-умолчанию
	m_size = 0;
	Head.m_pNext = &Tail;
	Tail.m_pPrev = &Head;
}

List::List(const List& value) : Head(Node::HEAD), Tail(Node::TAIL) {	//конструктор копирования
	m_size = 0;
	Head.m_pNext = &Tail;
	Tail.m_pPrev = &Head;
	this->Copy(value);
}

List::List(List&& copy) {												//move конструктор
	this->Clear();
	this->Head = copy.Head;
	this->Tail = copy.Tail;

	copy.Head.m_pNext = &copy.Tail;
	copy.Tail.m_pPrev = &copy.Head;
}

List::~List() {
	this->Clear();
}

void List::AddToHead(Circle* c) {
	Node *pNewNode = new Node(c);
	Node *pTmpNext = this->Head.m_pNext;
	this->Head.m_pNext = pNewNode;
	pNewNode->m_pPrev = &this->Head;

	pNewNode->m_pNext = pTmpNext;
	pTmpNext->m_pPrev = pNewNode;

	this->m_size++;
}

void List::AddToTail(Circle* c) {
	Node *pNewNode = new Node(c);
	Node *pTmpPrev = this->Tail.m_pPrev;
	this->Tail.m_pPrev = pNewNode;
	pNewNode->m_pNext = &this->Tail;

	pNewNode->m_pPrev = pTmpPrev;
	pTmpPrev->m_pNext = pNewNode;

	this->m_size++;
}


bool List::Remove(const Circle* c) {
	return RemoveAll(c, 1);
}

int List::RemoveAll(const Circle* c) {
	return RemoveAll(c, this->m_size);
}

int List::RemoveAll(const Circle* c, int limit) {
	int count = 0;
	Node *pNode = this->Head.m_pNext;
	while (limit > 0 && pNode && !pNode->isTail()) {
		if (*c == pNode->m_Data) {
			Node *pTmpNext = pNode->m_pNext;
			Node *pTmpPrev = pNode->m_pPrev;
			pTmpNext->m_pPrev = pTmpPrev;
			pTmpPrev->m_pNext = pTmpNext;
			delete pNode;
			pNode = pTmpPrev;
			this->m_size--;
			count++;
			limit--;
		}
		pNode = pNode->m_pNext;
	}
	return count;
}

void List::Clear() {
	Node * pNode = &this->Head;
	//while ((pNode = pNode->m_pNext) && (!pNode->isTail())) {
	while ((pNode = pNode->m_pNext) && (!pNode->isTail())) {
		delete pNode;
	}
	this->m_size = 0;
	Head.m_pNext = &Tail;
	Tail.m_pPrev = &Head;
}


void List::Swap(Node* a, Node* b) {

	if (a->isHead() || a->isTail() || b->isHead() || b->isTail()) {
		return;
	}

	if (a->m_pNext == b) {					//если а и b соседи
		Node *tmpAPrev = a->m_pPrev;
		a->m_pNext = b->m_pNext;
		a->m_pPrev = b;
		b->m_pNext = a;
		b->m_pPrev = tmpAPrev;

		tmpAPrev->m_pNext = b;
		a->m_pNext->m_pPrev = a;

	}
	else if (b->m_pNext == a) {				//если а и b соседи

		Node *tmpBPrev = b->m_pPrev;
		b->m_pNext = a->m_pNext;
		b->m_pPrev = a;
		a->m_pNext = b;
		a->m_pPrev = tmpBPrev;

		tmpBPrev->m_pNext = a;
		b->m_pNext->m_pPrev = b;
	}
	else {
		Node *tmpAPrev = a->m_pPrev;
		Node *tmpANext = a->m_pNext;
		Node *tmpBPrev = b->m_pPrev;
		Node *tmpBNext = b->m_pNext;

		b->m_pNext = tmpANext;
		b->m_pPrev = tmpAPrev;
		a->m_pNext = tmpBNext;
		a->m_pPrev = tmpBPrev;

		tmpANext->m_pPrev = b;
		tmpAPrev->m_pNext = b;
		tmpBNext->m_pPrev = a;
		tmpBPrev->m_pNext = a;
	}
}

void List::SortBySquare() {
	Node *pNode = this->Head.m_pNext;
	Node *pNodeNext;

	while (!pNode->isTail() && !(pNodeNext = pNode->m_pNext)->isTail()) {

		if (*pNodeNext < *pNode) {
			this->Swap(pNodeNext, pNode);

			if (pNodeNext->m_pPrev && !pNodeNext->m_pPrev->isHead()) {
				pNode = pNodeNext->m_pPrev;
				continue;
			}
		}
		pNode = pNodeNext;
	}
}


List& List::operator=(const List& copy) {
	this->Copy(copy);
	return *this;
}

List& List::operator=(List&& copy) {
	this->Clear();
	this->Head = copy.Head;
	this->Tail = copy.Tail;
	copy.Head.m_pNext = &copy.Tail;
	copy.Tail.m_pPrev = &copy.Head;
	return *this;
}


std::ostream& operator<< (std::ostream& stream, const List& l) {
	stream << "radius, x, y\n";
	const Node *pNode = l.Head.GetNext();
	while (pNode && !pNode->isTail()) {
		stream << *pNode;
		pNode = pNode->GetNext();
	}
	return stream;
}


void operator<<(List& l, std::istream& s) {
	const int n = 128;
	int r, x, y = 0;

	char *line = new char[n];
	s.getline(line, n);//skip header
	while (!s.eof()) {
		s.getline(line, n);
		if (sscanf_s(line, "%d,%d,%d\n", &r, &x, &y) >= 0) {
			Circle c(x, y, r);
			l.AddToTail(&c);
		}
	}
	delete[] line;
}


void List::Copy(const List& copy) {
	this->m_size = copy.m_size;

	Node *pNode = &this->Head;
	const Node *pCopy = copy.Head.m_pNext;

	while ((pNode = pNode->m_pNext) && !pNode->isTail()) {
		if (!pCopy || pCopy->isTail()) {
			Node *tmp = pNode->m_pPrev;
			this->Remove(&pNode->m_Data);
			pNode = tmp;
		}
		else {  //copy
			pNode->m_Data = pCopy->m_Data;
			pCopy = pCopy->m_pNext;
		}
	}
	while (pCopy && !pCopy->isTail()) {
		Circle* c = new Circle(pCopy->m_Data);
		this->AddToTail(c);
		pCopy = pCopy->m_pNext;
		delete c;
	}
}