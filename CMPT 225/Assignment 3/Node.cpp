/*
 * Node.cpp
 *
 * Class Definition: Node of a singly linked list
 *
 * Created on: July 01, 2017
 * Author: Kevin Chen, Alan Ou
 */

#include <cstdio>  // Needed for NULL
#include "Node.h"

// Constructors

// Default Constructor
template<class ElementType>
Node<ElementType>::Node()
{
	next = NULL;
}

template<class ElementType>
Node<ElementType>::Node(ElementType theData)
{
	data = theData;
	next = NULL;
}

template<class ElementType>
Node<ElementType>::Node(ElementType theData, Node<ElementType>* theNextNode)
{
	data = theData;
	next = theNextNode;
}

// Description: Sets the next node
// Method idea from P.137 of Data Abstractions & Problem Solving with C++, Walls and Mirrors(6th edition), Frank M.Carrano and Timothy Henry
template<class ElementType>
void Node<ElementType>::setNext(Node<ElementType>* nextNodePtr) {
	next = nextNodePtr;
}

// Description: Returns the data in the node
// Method idea from P.137 of Data Abstractions & Problem Solving with C++, Walls and Mirrors(6th edition), Frank M.Carrano and Timothy Henry
template<class ElementType>
ElementType Node<ElementType>::getData() const {
	return data;
}

// Description: Returns the pointer of the next node
// Method idea from P.137 of Data Abstractions & Problem Solving with C++, Walls and Mirrors(6th edition), Frank M.Carrano and Timothy Henry
template<class ElementType>
Node<ElementType>* Node<ElementType>::getNext() const {
	return next;
}

// end Node.cpp