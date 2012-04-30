
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template<class Type>
class Vector {
private:
	Type *data;
	int size, psize;
public:
	class Iterator {
	private:
		int index;
		Type *data;
		//Vector *parent;
	public:
		friend class Vector;
		Iterator();
		Iterator(int);
		Iterator(const Iterator &);
        
		int operator!=(const Iterator &);
		Iterator operator++();
		Iterator operator--();
		Iterator operator++(int);
		Iterator operator--(int);
		Type operator*();
	};

	Vector();
	Vector(int size);
	Vector(Vector<Type> &);
	~Vector();
	
	Vector operator=(Vector<Type> &);
    int Empty();
    int GetSize();
    Type GetFrontElement(); 
    Type GetBackElement();
	Type operator[](int index);
    void InsertAtIndex(int, const Type &);
    void PushFront(const Type &);
    void PushBack(const Type &);
    void PopFront();
    void PopBack();
    void Clear(); 
    void Print(); 
    //Iterator:
    int IsBeforeFirst(Iterator &);
    int IsPastRear(Iterator &);
    int IsDereferencable(Iterator &);
    void Insert(Iterator &, const Type &);
    void Erase(Iterator &);
    Iterator MoveAtIndex(int);
    Iterator Begin();
    Iterator End(); 
};

//Iterator
//Constructor
template<class Type>
Vector<Type>::Iterator::Iterator(): index(0), data(NULL) {}
//Constructor on index
template<class Type>
Vector<Type>::Iterator::Iterator(int i): index(i), data(NULL) {}
//Constructor copy
template<class Type>
Vector<Type>::Iterator::Iterator(const Iterator &iterator):	index(iterator.index), data(iterator.data) {}
// operator !=
template<class Type>
int Vector<Type>::Iterator::operator!=(const Iterator &iterator) {
	return &iterator != this;
}
// ++inc
template<class Type>
typename Vector<Type>::Iterator Vector<Type>::Iterator::operator++() {
	index++;
	return *this;
}
// --dec
template<class Type>
typename Vector<Type>::Iterator Vector<Type>::Iterator::operator--() {
	index--;
	return *this;
}
// inc++
template<class Type>
typename Vector<Type>::Iterator Vector<Type>::Iterator::operator++(int) {
	Iterator old = *this;
	index++;
	return old;
}
// dec--
template<class Type>
typename Vector<Type>::Iterator Vector<Type>::Iterator::operator--(int) {
	Iterator old = *this;
	index--;
	return old;
}
//Dereferencable iterator
template<class Type>
Type Vector<Type>::Iterator::operator*() {
	return *(data + index);
}
//Vector
//Constructor
template<class Type>
Vector<Type>::Vector() {
	size = 0;
	psize = 0;
	data = NULL;
}
//Constructor (size)
template<class Type>
Vector<Type>::Vector(int count) {
	size = 0;
	psize = count;
	data = (Type*)malloc(sizeof(Type) * psize);
}
//Constructor Copy
template<class Type>
Vector<Type>::Vector(Vector<Type> &vector) {
	Iterator iterator, iter;
	size = 0;
	psize = vector.size;
	if(data == NULL) free(data);
	data = (Type*)malloc(sizeof(Type) * psize);
	for(iterator = vector.Begin(), iter = Begin(); !vector.IsPastRear(iterator); iterator++, iter++) 
		Insert(iter, *iterator);
}
//Destructor
template<class Type>
Vector<Type>::~Vector() {
	if(!Empty()) free(data);
}
//Vector. Operations With Iterator
//Before first
template<class Type>
int Vector<Type>::IsBeforeFirst(typename Vector<Type>::Iterator &iterator) {
	return iterator.index < 0;
}
//Past rear
template<class Type>
int Vector<Type>::IsPastRear(typename Vector<Type>::Iterator &iterator) {
	return iterator.index >= size; 
}
//Is Dereferencable
template<class Type>
int Vector<Type>::IsDereferencable(typename Vector<Type>::Iterator &iterator) {
	return !IsBeforeFirst(iterator) && !IsPastRear(iterator);
}
//Insert
template<class Type>
void Vector<Type>::Insert(typename Vector<Type>::Iterator &iterator, const Type &element) {
	if(Empty()) {
		if(size == psize) {
			psize++;
			data = (Type*)malloc(sizeof(Type) * psize);
		}
		*data = element;
	}
	else {
		Type *pointer = data + iterator.index;

		if(size == psize) {
			psize++;
			data = (Type*)realloc(data, sizeof(Type) * psize);
		}
		memmove(pointer + 1, pointer, sizeof(Type) * (size - iterator.index));
		*pointer = element;
	}
	size++;
}
//Erase
template<class Type>
void Vector<Type>::Erase(typename Vector<Type>::Iterator &iterator) {
	if(Empty()) return;
	Type *pointer = data + iterator.index;
	memmove(pointer, pointer + 1, sizeof(Type) * (size - iterator.index));
	size--;
}
//Move at Index
template<class Type>
typename Vector<Type>::Iterator Vector<Type>::MoveAtIndex(int index) {
	Iterator iterator;
	iterator.index = index;
	iterator.data = data;
	return iterator;
}
//Begin
template<class Type>
typename Vector<Type>::Iterator Vector<Type>::Begin() {
	Iterator iterator;
	iterator.index = 0;
	iterator.data = data;
	return iterator;
}
//End
template<class Type>
typename Vector<Type>::Iterator Vector<Type>::End() {
	Iterator iterator;
	iterator.data = data;
	if(!Empty())
		iterator.index = size;
	return iterator;
} 
//Vector
// =
template<class Type>
Vector<Type> Vector<Type>::operator=(Vector &vector) {
	Iterator iterator, iter;
	size = 0;
	psize = vector.size;
	if(data == NULL) free(data);
	data = NULL;
	data = (Type*)malloc(sizeof(Type) * psize);
	for(iterator = vector.Begin(), iter = Begin(); !vector.IsPastRear(iterator); iterator++, iter++) 
		Insert(iter, *iterator);
	return *this;
}
//Empty
template<class Type>
int Vector<Type>::Empty() {
	return size == 0 ? 1 : 0;
}
//Get size
template<class Type>
int Vector<Type>::GetSize() {
	return size;
}
//operator []
template<class Type>
Type Vector<Type>::operator[](int index) {
	Iterator iterator = MoveAtIndex(index);
	return *iterator;
}
//Get front element
template<class Type>
Type Vector<Type>::GetFrontElement() {
	return *data;
} 
//Get back element
template<class Type>
Type Vector<Type>::GetBackElement() {
	return *(data + size - 1);
} 
//Insert at element
template<class Type>
void Vector<Type>::InsertAtIndex(int index, const Type &element) {
	Iterator iterator = MoveAtIndex(index);
	Insert(iterator);
}
//Push front
template<class Type>
void Vector<Type>::PushFront(const Type &element) {
	Iterator iterator = Begin();
	Insert(iterator);
}
//Push back
template<class Type>
void Vector<Type>::PushBack(const Type &element) {
	Iterator iterator = End();
	Insert(iterator, element);
}
//Pop front
template<class Type>
void Vector<Type>::PopFront() {
	Iterator iterator = Begin();
	Erase(iterator);
}
//Pop back
template<class Type>
void Vector<Type>::PopBack() {
	Iterator iterator = End();
	iterator--;
	Erase(iterator);
}
//Clear
template<class Type>
void Vector<Type>::Clear() {
	free(data);
	size = 0;
} 
//Print
template<class Type>
void Vector<Type>::Print() {
	Iterator iterator;
	for(iterator = Begin(); !IsPastRear(iterator); iterator++)
		std::cout << *iterator << std::endl;
} 

#endif
