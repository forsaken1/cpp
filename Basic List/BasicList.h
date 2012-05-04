
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
       
	Type &operator*() { return ((Element<Type>*)element)->value; }
};

template<class Type>
class List: protected BasicList {
public:
	List(): BasicList() {}

	List(List<Type> &rlist): BasicList() {
		for(Iterator<Type> iterator = rlist.Begin(); iterator != rlist.End(); iterator++) 
			PushBack(*iterator);
	}

	List<Type> operator=(List<Type> &rlist) {
		Clear();
		pastRear->previousElement = beforeFirst;
		beforeFirst->nextElement = pastRear;

		for(Iterator<Type> iterator = rlist.Begin(); iterator != rlist.End(); iterator++) 
			PushBack(*iterator);

		return *this;
	}

	void Clear() { BasicList::Clear(); }

	int Empty() { return BasicList::Empty(); }

	int GetSize() { return BasicList::GetSize(); }

	void InserAtIndex(int index, Type &value) {
		BasicIterator iterator = MoveAtIndex(index);
		Insert(iterator, value);
	}

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
		Erase(iterator);
	}

	void PopBack() {
		BasicIterator iterator = BasicList::End();
		iterator--;
		Erase(iterator);
	}

	void Print() {
		for(Iterator<Type> iterator = Begin(); iterator != End(); iterator++)
			std::cout << *iterator << std::endl;
	}

	Iterator<Type> MoveAtIndex(int index) {
		Iterator<Type> iterator = Begin();
		for(int i = 0; i < index; i++) iterator++;
		return iterator;
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

	Type &GetFirstElement() {
		Iterator<Type> iterator = Begin();
		return *iterator;
	}

	Type &GetLastElement() {
		Iterator<Type> iterator = End();
		iterator--;
		return *iterator;
	}

	Type &GetElementByIndex(int index) {
		Iterator<Type> iterator = MoveAtIndex(index);
		return *iterator;
	}
};

#endif 
