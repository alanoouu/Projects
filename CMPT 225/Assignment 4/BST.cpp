/*
 * BST.cpp
 * 
 * Description: Data collection Binary Search Tree ADT class.
 *              Link-based implementation.
 *
 * Class invariant: It is always a BST.
 * 
 * Author: Inspired from our textbook
 * Date of last modification: July 2017
 */

#include "BST.h"
#include "ElementAlreadyExistsInBSTException.h"
#include "ElementDoesNotExistInBSTException.h"

template <class ElementType>
bool BST<ElementType>::insertR(const ElementType& element, BSTNode<ElementType>* current) {
	bool okay = false;
	if(root == NULL){
		BSTNode<ElementType>* newNode = new BSTNode<ElementType>(element);
		root = newNode;
		return true;
	}else if(current->isLeaf()){
		if(element < current -> element){
			current->left = new BSTNode<ElementType>(element);
			return true;
		}else{
			current->right = new BSTNode<ElementType>(element);
			return true;

		}
	}
	else if(current->element == element){
		return false;
	}
	if(element < current->element){
		okay = insertR(element, current->left);
	}else{
		okay = insertR(element, current->right);
	}

	return okay;
}

template <class ElementType>
ElementType& BST<ElementType>::retrieveR(const ElementType& targetElement, BSTNode<ElementType>* current) const throw(ElementDoesNotExistInBSTException){
	if(current == NULL){
		throw ElementDoesNotExistInBSTException("Element does not Exist");
	}else if(current->element == targetElement){
		return current->element;
	}
	if(targetElement < current->element){
		retrieveR(targetElement, current->left);
	}else{
		retrieveR(targetElement, current->right);
	}
}

template <class ElementType>
void BST<ElementType>::traverseInOrderR(void visit(ElementType&), BSTNode<ElementType>* current) const{
	if(current != NULL){
		traverseInOrderR(visit, current->left);
		ElementType item = current->element;
		visit(item);
		traverseInOrderR(visit,current->right);
	}
}



template <class ElementType>
BST<ElementType>::BST()
:root(NULL),elementCount(0)
{}
template <class ElementType>
BST<ElementType>::BST(ElementType& element)
:root(element),elementCount(1)
{}
template <class ElementType>
BST<ElementType>::BST(const BST<ElementType>& aBST)
:root(aBST.root),elementCount(1)
{}
template <class ElementType>
BST<ElementType>::~BST(){

}

    // BST operations:

    // Time efficiency: O(1)
template <class ElementType>
int BST<ElementType>::getElementCount() const{
	return elementCount;
}

	// Time efficiency: O(log2 n)
template <class ElementType>
void BST<ElementType>::insert(const ElementType& newElement) throw(ElementAlreadyExistsInBSTException){
	bool successful = insertR(newElement, root);
	if (!successful){
		throw ElementAlreadyExistsInBSTException("Element already exists");
	}
}

	// Time efficiency: O(log2 n)
template <class ElementType>
ElementType& BST<ElementType>::retrieve(const ElementType& targetElement) const throw(ElementDoesNotExistInBSTException){
	return retrieveR(targetElement,root);
}
	// Time efficiency: O(n)
template <class ElementType>
void BST<ElementType>::traverseInOrder(void visit(ElementType&)) const{
	traverseInOrderR(visit, root);
}


// To be completed!
