
#ifndef LIST_H
#define LIST_H

#include <iostream>

class BasicElement {
public:
	BasicElement *previousElement, *nextElement;
	BasicElement(): previousElement(NULL), nextElement(NULL) {};
};

class BasicIterator {
public:
	BasicElement *element;
	BasicIterator();
	BasicIterator(const BasicIterator &);
        
	BasicIterator &operator++();
	BasicIterator &operator--();
	const BasicIterator operator++(int);
	const BasicIterator operator--(int);
	int operator==(BasicIterator &);
	int operator!=(BasicIterator &);
};

class BasicList {
public: 
	int size;
    BasicElement *beforeFirst, *pastRear;
    BasicList();
	BasicList(BasicList &);
    ~BasicList();

	BasicList operator=(BasicList &);
    int Empty();
    int GetSize();
    void Clear(); 
    void Insert(BasicIterator &, BasicElement *);
    void Erase(BasicIterator &);
    BasicIterator MoveAtIndex(int);
    BasicIterator Begin();
    BasicIterator End(); 
	int IsBeforeFirst(BasicIterator &);
    int IsPastRear(BasicIterator &);
    int IsDereferencable(BasicIterator &);
};

template<class Type>
class Element: public BasicElement {
public:
	Type value;
	//Element<Type> *previousElement, *nextElement;
	Element(const Type &v): value(v) {}
};

template<class Type>
class Iterator: public BasicIterator {
public:
	//Element<Type> *element;
	Iterator() {}
	//Iterator(const Iterator &iter): element(iter.element) {}
        
	Type operator*() { return ((Element<Type>*)element)->value; }
};

template<class Type>
class List: public BasicList {
public:    
	//Element<Type> *beforeFirst, *pastRear;
	/*List() {
		size = 0;
		beforeFirst = new Element<Type>;
		pastRear = new Element<Type>;
		beforeFirst->nextElement = pastRear;
		pastRear->previousElement = beforeFirst;
		pastRear->nextElement = NULL;
		beforeFirst->previousElement = NULL;
	}
	List(const List &list): BasicList(list) {}*/

	void PushFront(Type &value) {
		Iterator<Type> iterator = Begin();
		Insert(iterator, value);
	}
    void PushBack(Type &value) {
		BasicIterator iterator = BasicList::End();
		Insert(iterator, value);
	}
	void PopFront() {
		BasicIterator iterator = Begin();
		Erase(iterator);
	}
	void PopBack() {
		BasicIterator iterator = End();
		iterator--;
		Erase(iterator);
	}
	void Print() {
		for(Iterator<Type> iterator = Begin(); iterator != End(); iterator++)
			std::cout << *iterator << std::endl;
	}
	Iterator<Type> Begin() {
		Iterator<Type> iterator;
		iterator.element = beforeFirst->nextElement;
		return iterator;
	}
	Iterator<Type> End() {
		Iterator<Type> iterator;
		iterator.element = pastRear;
		return iterator;
	}
	void Insert(BasicIterator &iterator, Type value) {
		BasicList::Insert(iterator, new Element<Type>(value));
	}
};

#endif 
