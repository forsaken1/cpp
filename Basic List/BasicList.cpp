#include "BasicList.h"

////////Basic Iterator
//Constructor
BasicIterator::BasicIterator() {
	element = new BasicElement;
}
//Constructor Copy
BasicIterator::BasicIterator(const BasicIterator &iterator) {
	element = iterator.element;
}
// ++inc
BasicIterator &BasicIterator::operator++() {
    element = element->nextElement;
    return *this;
}
// inc++
const BasicIterator BasicIterator::operator++(int) {
    BasicIterator old(*this);
	element = element->nextElement;
    return old;
}
// --dec
BasicIterator &BasicIterator::operator--() {
    element = element->previousElement;
    return *this;
}
// dec--
const BasicIterator BasicIterator::operator--(int) {
    BasicIterator old(*this);
	element = element->previousElement;
    return old;
}
//operator ==
int BasicIterator::operator==(BasicIterator &iter) {
	return element == iter.element;
}
//operator !=
int BasicIterator::operator!=(BasicIterator &iter) {
    return element != iter.element;
}

////////Basic List
//Constructor
BasicList::BasicList() {
	size = 0;
    beforeFirst = new BasicElement;
    pastRear = new BasicElement;
    
    beforeFirst->previousElement = NULL;
    beforeFirst->nextElement = pastRear;

    pastRear->previousElement = beforeFirst;
    pastRear->nextElement = NULL;
}
//Constructor Copy
BasicList::BasicList(BasicList &rlist) {
    beforeFirst = new BasicElement;
    pastRear = new BasicElement;
    
    beforeFirst->previousElement = NULL;
    pastRear->nextElement = NULL;

    size = rlist.size;

	BasicIterator iterator;
	BasicElement *element, *next;
	element = beforeFirst;

	for(iterator = rlist.Begin(); iterator != rlist.End(); iterator++) {
		next = new BasicElement;
		element->nextElement = next;
		next->previousElement = element;
		element = next;
	}
	pastRear->previousElement = element;
	element->nextElement = pastRear;
}
//Destructor
BasicList::~BasicList() {
    Clear();
    delete beforeFirst;
    delete pastRear;
}
//operator=
BasicList BasicList::operator=(BasicList &rlist) {
	Clear();
    size = rlist.size;

	BasicIterator iterator;
	BasicElement *element, *next;
	element = beforeFirst;

	for(iterator = rlist.Begin(); iterator != rlist.End(); iterator++) {
		next = new BasicElement;
		element->nextElement = next;
		next->previousElement = element;
		element = next;
	}
	pastRear->previousElement = element;
	element->nextElement = pastRear;
    return *this;
}
//Clear
void BasicList::Clear() {
	if(Empty()) return;
    size = 0;
    for(BasicIterator iterator = Begin(); iterator != End(); iterator++) 
        Erase(iterator);
}

int BasicList::Empty() {
	return size == 0 ? 1 : 0;
}

int BasicList::GetSize() {
	return size;
}

void BasicList::Insert(BasicIterator &iterator, BasicElement *newElement) {
	BasicElement *element;  
    element = iterator.element;
    newElement->previousElement = element->previousElement;
    newElement->nextElement = element;
    element->previousElement->nextElement = newElement;
    element->previousElement = newElement;
    iterator.element = newElement;
    size++;
}

void BasicList::Erase(BasicIterator &iterator) {
	if(Empty()) return;
    BasicElement *element;
    element = iterator.element;
	iterator++;
    element->previousElement->nextElement = element->nextElement;
    element->nextElement->previousElement = element->previousElement;
    delete element;
    size--;
}

BasicIterator BasicList::MoveAtIndex(int index) {
	BasicIterator iterator = Begin();
    for(int i = 0; i < index; i++) iterator++;
    return iterator;
}

BasicIterator BasicList::Begin() {
	BasicIterator iterator;
	iterator.element = beforeFirst->nextElement;
    return iterator;
}

BasicIterator BasicList::End() {
	BasicIterator iterator;
	iterator.element = pastRear;
    return iterator;
}
