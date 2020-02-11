#include "Node.h"


Node::Node() : Node(Node::HEAD) {
}

Node::Node(N_TYPE t) {
	m_type = t;
	m_pPrev = nullptr;
	m_pNext = nullptr;
}

Node::Node(const Node& value) : m_Data(value.m_Data) {
	m_type = value.m_type;
}

Node::Node(const Node&& value) : m_Data(value.m_Data) {
	m_type = value.m_type;
}

Node::Node(const Circle *c) : m_Data(*c) {
	this->m_type = NODE;
}

Node::~Node() {

	m_pPrev = nullptr;
	m_pNext = nullptr;
}


bool Node::isHead() const {
	return m_type == HEAD;
}

bool Node::isTail() const {
	return m_type == TAIL;
}

Node *Node::GetNext() const {
	return m_pNext;
}

Node *Node::GetPrev() const {
	return m_pPrev;
}

Node& Node::operator=(const Node& c) {
	m_pPrev = c.m_pPrev;
	m_pNext = c.m_pNext;
	m_Data = c.m_Data;
	return *this;
}


std::ostream& operator<< (std::ostream& stream, const Node& n) {
	stream << n.m_Data << std::endl;
	return stream;
}

bool operator< (const Node& a, const Node& b) {
	return a.m_Data.GetSquare() < b.m_Data.GetSquare();
}

bool operator> (const Node& a, const Node& b) {
	return a.m_Data.GetSquare() > b.m_Data.GetSquare();
}