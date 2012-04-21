
#ifndef LIST_H
#define LIST_H

#include <iostream>

template<class Type>
class List {    
private:
    class Element {
    public:
        Type value;
        Element *previousElement, *nextElement;
    };
    
	int size;
    Element *beforeFirst, *pastRear;
    
public:    
    class Iterator {
    private:
        Element *element;
    public:
        Iterator();
        
        Iterator &operator++();
        Iterator &operator--();
        const Iterator operator++(int);
        const Iterator operator--(int);
		int operator==(Iterator&);
		int operator!=(Iterator&);
        Type operator*();
        Element* GetElementPointer();
        void SetElementPointer(Element*);
    };
    //List:
    List();
	List(List<Type> &);
    ~List();

    List<Type> &operator=(List<Type> &);
    int Empty();
    int GetSize();
    Type GetFrontElement(); 
    Type GetBackElement(); 
	Type GetElementByIndex(int);
    void Swap(List<Type>);  
    void InsertAtIndex(int, const Type &);
    void PushFront(const Type &);
    void PushBack(const Type &);
    void PopFront();
    void PopBack();
    void Clear(); 
    void Print(); 
    //Iterator:
    void Insert(Iterator, const Type &);
    void Erase(Iterator);
    Iterator MoveAtIndex(int);
    Iterator Begin();
    Iterator End(); 
	int IsBeforeFirst(Iterator);
    int IsPastRear(Iterator);
    int IsDereferencable(Iterator);
};
////////////////////class Iterator
//Constructor
template<class Type>
List<Type>::Iterator::Iterator() {
    element = new Element;
}
///////////////////////////Inc\Dec
template<class Type>
typename List<Type>::Iterator &List<Type>::Iterator::operator++() {
    element = element->nextElement;
    return *this;
}

template<class Type>
typename const List<Type>::Iterator List<Type>::Iterator::operator++(int) {
    Iterator old(*this);
	element = element->nextElement;
    return old;
}

template<class Type>
typename List<Type>::Iterator &List<Type>::Iterator::operator--() {
    element = element->previousElement;
    return *this;
}

template<class Type>
typename const List<Type>::Iterator List<Type>::Iterator::operator--(int) {
    Iterator old(*this);
	element = element->previousElement;
    return old;
}
//operator ==
template<class Type>
int List<Type>::Iterator::operator==(Iterator &iter) {
	return GetElementPointer() == iter.GetElementPointer();
}
//operator !=
template<class Type>
int List<Type>::Iterator::operator!=(Iterator &iter) {
    return GetElementPointer() != iter.GetElementPointer();
}
//Dereference iterator
template<class Type>
Type List<Type>::Iterator::operator*() {
    return element->value;   
}
//Get pointer of element
template<class Type>
typename List<Type>::Element* List<Type>::Iterator::GetElementPointer() {
    return element;   
}
//Set pointer of element
template<class Type>
void List<Type>::Iterator::SetElementPointer(Element *elem) {
    element = elem;
}
/////////////////////////////class List
//Constructor
template<class Type>
List<Type>::List() {
    size = 0;
    beforeFirst = new Element;
    pastRear = new Element;
    
    beforeFirst->previousElement = NULL;
    beforeFirst->nextElement = pastRear;
	beforeFirst->value = NULL;

    pastRear->previousElement = beforeFirst;
    pastRear->nextElement = NULL;
	pastRear->value = NULL;
}
//Copy constructor 
template<class Type>
List<Type>::List(List<Type> &rlist) {
    beforeFirst = new Element;
    pastRear = new Element;
    
    beforeFirst->previousElement = NULL;
	beforeFirst->value = NULL;

    pastRear->nextElement = NULL;
	pastRear->value = NULL;

    size = rlist.size;

	List<Type>::Iterator iterator;
	Element *element, *next;
	element = beforeFirst;

	for(iterator = rlist.Begin(); iterator != rlist.End(); iterator++) {
		next = new Element;
		element->nextElement = next;
		next->previousElement = element;
		element = next;
		element->value = *iterator;
	}
	pastRear->previousElement = element;
	element->nextElement = pastRear;
}
//Destructor
template<class Type>
List<Type>::~List() {
    Clear();
    delete beforeFirst;
    delete pastRear;
}
// = 
template<class Type>
typename List<Type> &List<Type>::operator=(List<Type> &rlist) {
    Clear();

    size = rlist.size;

	List<Type>::Iterator iterator;
	Element *element, *next;
	element = beforeFirst;

	for(iterator = rlist.Begin(); iterator != rlist.End(); iterator++) {
		next = new Element;
		element->nextElement = next;
		next->previousElement = element;
		element = next;
		element->value = *iterator;
	}
	pastRear->previousElement = element;
	element->nextElement = pastRear;
    return *this;
}
//Swap
template<class Type>
void List<Type>::Swap(List<Type> list) {
    List<Type> temp;
    temp = list;
    list = *this;
    *this = temp;
}
//Insert at index
template<class Type>
void List<Type>::InsertAtIndex(int index, const Type &value) {
    Iterator iterator = MoveAtIndex(index);
    Insert(iterator, value);
}
//Push front element
template<class Type>
void List<Type>::PushFront(const Type &value) {
    Iterator iterator = Begin();
    Insert(iterator, value);
}
//Push back element
template<class Type>
void List<Type>::PushBack(const Type &value) {
    Iterator iterator = End();
    ++iterator;
    Insert(iterator, value);
}
//Pop front element
template<class Type>
void List<Type>::PopFront() {
	if(Empty()) return;
    Iterator iterator = Begin();
    Erase(iterator);
}
//Pop back element
template<class Type>
void List<Type>::PopBack() {
	if(Empty()) return;
    Iterator iterator = End();
    Erase(iterator);
}
//List is empty?
template<class Type>
int List<Type>::Empty() {
    return size == 0 ? 1 : 0;
}
//Clear
template<class Type>
void List<Type>::Clear() {
	if(Empty()) return;
    size = 0;
    for(Iterator iterator = Begin(); !IsPastRear(iterator); iterator++) 
        Erase(iterator);
}
//Print
template<class Type>
void List<Type>::Print() {
    if(Empty()) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    Iterator iterator = Begin();
    
    while(!IsPastRear(iterator)) {
        std::cout << *iterator << " "; 
		++iterator;
    }
    std::cout << std::endl;
}
//Get size
template<class Type>
int List<Type>::GetSize() {
    return size;   
}
//Get front element (by stl:list::front)
template<class Type>
Type List<Type>::GetFrontElement() {
    return Empty() ? NULL : beforeFirst->nextElement->value;
}
//Get back element (by stl::list::back)
template<class Type>  
Type List<Type>::GetBackElement() {
    return Empty() ? NULL : pastRear->previousElement->value;
}
//Get element by index
template<class Type>  
Type List<Type>::GetElementByIndex(int index) {
	List<Type>::Iterator iterator = Begin();

	if(Empty()) 
		return NULL;
	else 
		for(int i = 0; i < index; i++)
			if(IsDereferencable(iterator)) iterator++;
			else return NULL;

	return *iterator;
}
//////////////////////Operations with iterator
//Insert
template<class Type>
void List<Type>::Insert(Iterator iterator, const Type &value) {
    Element *newElement, *element;    
    newElement = new Element;
    newElement->value = value;
    element = iterator.GetElementPointer();
    newElement->previousElement = element->previousElement;
    newElement->nextElement = element;
    element->previousElement->nextElement = newElement;
    element->previousElement = newElement;
    element = newElement;
    size++;
}
//Move at index
template<class Type>
typename List<Type>::Iterator List<Type>::MoveAtIndex(int index) {
    Iterator iterator = Begin();
    for(int i = 0; i < index; i++) iterator++;
    return iterator;
}
//Erase
template<class Type>
void List<Type>::Erase(Iterator iterator) {
    if(Empty()) return;
    Element *element;
    element = iterator.GetElementPointer();
	iterator++;
    element->previousElement->nextElement = element->nextElement;
    element->nextElement->previousElement = element->previousElement;
    delete element;
    size--;
}
//Begin
template<class Type>
typename List<Type>::Iterator List<Type>::Begin() {
    Iterator iterator;
    iterator.SetElementPointer(beforeFirst->nextElement);
    return iterator;
}
//End
template<class Type>
typename List<Type>::Iterator List<Type>::End() {
    Iterator iterator;
    iterator.SetElementPointer(pastRear->previousElement);
    return iterator;
}
/////////////////////////////////Check iterator
//Is dereferencable
template<class Type>
int List<Type>::IsDereferencable(Iterator iterator) {
    return !IsBeforeFirst(iterator) && !IsPastRear(iterator);
}
//Is first
template<class Type>
int List<Type>::IsBeforeFirst(Iterator iterator) {
    return iterator.GetElementPointer() == beforeFirst ? 1 : 0;
}
//Is past
template<class Type>
int List<Type>::IsPastRear(Iterator iterator) {
    return iterator.GetElementPointer() == pastRear ? 1 : 0;
}

#endif 
