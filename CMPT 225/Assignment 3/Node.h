/*
 * Node.h
 *
 * Class Definition: Node of a singly linked list
 *
 * Created on: July 01, 2017
 * Author: Kevin Chen, Alan Ou
 */

#pragma once

template<class ElementType>

class Node {
private:
    ElementType data;           // The data in the node
    Node<ElementType> *next;    // Pointer to next node
public:

    // Constructors

    // Default Constructor
    Node();

    Node(ElementType theData);

    Node(ElementType theData, Node<ElementType> *theNextNode);

    // Description: Sets the next node
    // Method idea from P.137 of Data Abstractions & Problem Solving with C++, Walls and Mirrors(6th edition), Frank M.Carrano and Timothy Henry
    void setNext(Node<ElementType> *nodePtr);

    // Description: Returns the data in the node
    // Method idea from P.137 of Data Abstractions & Problem Solving with C++, Walls and Mirrors(6th edition), Frank M.Carrano and Timothy Henry
    ElementType getData() const;

    // Description: Returns the pointer of the next node
    // Method idea from P.137 of Data Abstractions & Problem Solving with C++, Walls and Mirrors(6th edition), Frank M.Carrano and Timothy Henry
    Node<ElementType> *getNext() const;

}; // end Node