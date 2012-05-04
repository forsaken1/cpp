
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
	Element(const Type &v): value(v) {}
};

template<class Type>
class Iterator: public BasicIterator {
public:
	Iterator() {}
       
	Type operator*() { return ((Element<Type>*)element)->value; }
};

template<class Type>
class List: protected BasicList {
public:
	List(): BasicList() {}
	List(List<Type> &list) {
		BasicList((BasicList)list);
	}
	List<Type> operator=(List<Type> &list) {
		BasicList::operator=(list);
		return *this;
	}
	void Clear() { BasicList::Clear(); }

	int Empty() { return BasicList::Empty(); }

	int GetSize() { return BasicList::GetSize(); }

	void PushFront(Type &value) {
		BasicIterator iterator = BasicList::Begin();
		Insert(iterator, value);
	}
    void PushBack(Type &value) {
		BasicIterator iterator = BasicList::End();
		Insert(iterator, value);
	}
	void PopFront() {
		BasicIterator iterator = BasicList::Begin();
		BasicList::Erase(iterator);
	}
	void PopBack() {
		BasicIterator iterator = BasicList::End();
		iterator--;
		BasicList::Erase(iterator);
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
	void Insert(BasicIterator &iterator, const Type &value) {
		BasicList::Insert(iterator, new Element<Type>(value));
	}
};

#endif 
