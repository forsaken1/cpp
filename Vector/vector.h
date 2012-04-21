
#ifndef VECTOR
#define VECTOR
#define INITIAL_VECTOR_SIZE 10

#include <iostream>

template<class Type>
class Vector {
private:
	Type *data;
	int size;
public:
	class Iterator {
    private:
		int index;
    public:
        Iterator();
		Iterator(int);
        
        Iterator operator++();
        Iterator operator--();
        Iterator operator++(int);
        Iterator operator--(int);
        Type operator*();
		friend Vector;
    };

	Vector();
	Vector(int size);
	Vector(const Vector<Type> &);
	~Vector();
	
	Vector operator=(const Vector &);
    int Empty();
    int GetSize();
    Type GetFrontElement(); 
    Type GetBackElement();
    void InsertAtIndex(int, const Type &);
    void PushFront(const Type &);
    void PushBack(const Type &);
    void PopFront();
    void PopBack();
    void Clear(); 
    void Print(); 
    //Iterator:
    int IsBeforeFirst(Iterator);
    int IsPastRear(Iterator);
    int IsDereferencable(Iterator);
    void Insert(Iterator, Type);
    void Erase(Iterator);
    Iterator MoveAtIndex(int);
    Iterator Begin();
    Iterator End(); 
};

//Iterator
//Constructor
template<class Type>
Vector<Type>::Iterator::Iterator(): index(0) {};
//Constructor on index
template<class Type>
Vector<Type>::Iterator::Iterator(int i): index(i) {};
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
}
//Constructor (size)
template<class Type>
Vector<Type>::Vector(int count) {
	data = (int*)malloc(sizeof(Type) * count);
	size = count;
}
//Constructor Copy
template<class Type>
Vector<Type>::Vector(const Vector<Type> &vector) {
	Iterator iterator, iter;
	size = vector.size;
	data = (int*)malloc(sizeof(Type) * size);
	for(iterator = vector.Begin(), iter = Begin(); !IsPastRear(iterator); iterator++, iter++) 
		*iterator = *iter;
}
//Destructor
template<class Type>
Vector<Type>::~Vector() {
	if(!Empty()) free(data);
}
//Vector. Operations With Iterator
//Before first
template<class Type>
int Vector<Type>::IsBeforeFirst(typename Vector<Type>::Iterator iterator) {
	return iterator == NULL ? 0 : iterator->index < 0;
}
//Past rear
template<class Type>
int Vector<Type>::IsPastRear(typename Vector<Type>::Iterator iterator) {
	return iterator == NULL ? 0 : iterator->index >= size; 
}
//Is Dereferencable
template<class Type>
int Vector<Type>::IsDereferencable(typename Vector<Type>::Iterator iterator) {
	return !IsBeforeFirst(iterator) && !IsPastRear(iterator);
}
//Insert
template<class Type>
void Vector<Type>::Insert(typename Vector<Type>::Iterator iterator, Type element) {
	if(!Empty())
		memmove(data + iterator.index + 1, data + iterator.index, size - iterator.index - 1);
	Type *pointer = data + iterator.index;
	*pointer = element;
}
//Erase
template<class Type>
void Vector<Type>::Erase(typename Vector<Type>::Iterator iterator) {
	memmove(data + iterator.index, data + iterator.index + 1, size - iterator.index - 1);
}
//Move at Index
template<class Type>
typename Vector<Type>::Iterator Vector<Type>::MoveAtIndex(int index) {
	Iterator iterator;
	iterator.index = index;
	return iterator;
}
//Begin
template<class Type>
typename Vector<Type>::Iterator Vector<Type>::Begin() {
	Iterator iterator;
	iterator.index = 0;
	return iterator;
}
//End
template<class Type>
typename Vector<Type>::Iterator Vector<Type>::End() {
	Iterator iterator;
	if(!Empty())
		iterator.index = size - 1;
	return iterator;
} 
//Vector
// =
template<class Type>
Vector<Type> Vector<Type>::operator=(const Vector &vector) {
	Iterator iterator, iter;
	size = vector.size;
	data = malloc(sizeof(Type) * size);
	for(iterator = vector.Begin(), iter = Begin(); !IsPastRear(iterator); iterator++, iter++) 
		*iterator = *iter;
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
	Iterator iteator;
	for(iterator = Begin(); !IsPastRear(iterator); iterator++)
		cout << *iterator << endl;
} 

#endif
