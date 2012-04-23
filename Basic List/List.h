
#ifndef LIST_H
#define LIST_H

#include <iostream>

class BasicElement {
public:
	BasicElement *previousElement, *nextElement;

	BasicElement();
};

class BasicIterator {
private:
	BasicElement *element;
public:
	BasicIterator();
        
	BasicIterator &operator++();
	BasicIterator &operator--();
	const BasicIterator operator++(int);
	const BasicIterator operator--(int);
	int operator==(BasicIterator&);
	int operator!=(BasicIterator&);
	BasicElement* GetElementPointer();
	void SetElementPointer(BasicElement*);
};

class BasicList {    
private:
	int size;
    BasicElement *beforeFirst, *pastRear;
public:    
    BasicList();
    ~BasicList();

    //Iterator:
    void Insert(BasicIterator &, BasicElement &);
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

	Element(const Value &v): value(v) {}
}

template<class Type>
class List: public BasicList {
public:    
	List<Type> &operator=(List<Type> &);
    int Empty();
    int GetSize();
    void InsertAtIndex(int, Type &);
    void PushFront(Type &);
    void PushBack(Type &);
    void PopFront();
    void PopBack();
    void Clear(); 
    void Print(); 
};


#endif 
