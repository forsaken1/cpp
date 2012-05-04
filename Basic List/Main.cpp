#include "BasicList.h"
#include <list>

void test(int expression) {
	if(expression) std::cout << "Test completed" << std::endl;
	else std::cout << "Test error" << std::endl;
}	

void compareWithStlList(List<int> &mylist, std::list<int> &slist) {
	Iterator<int> iterator = mylist.Begin();
	std::list<int>::iterator iter = slist.begin();

	for(; iter != slist.end(); iterator++, iter++) 
		if(*iterator != *iter) {
			std::cout << "Test error: Compare error" << std::endl;
			return;
		}
	std::cout << "Test completed: Full compare" << std::endl;
}

void compareWithMyList(List<int> &mylist, List<int> &flist) {
	Iterator<int> iterator = mylist.Begin();
	Iterator<int> iter = flist.Begin();

	for(; iter != mylist.End(); iterator++, iter++) 
		if(*iterator != *iter) {
			std::cout << "Test error: Compare error" << std::endl;
			return;
		}
	std::cout << "Test completed: Full compare" << std::endl;
}

int main() {
	List<int> mylist, flist;
	std::list<int> slist;

	for(int i = 0; i < 100; i++) {
		mylist.PushBack(i);
		slist.push_back(i);
	}
	compareWithStlList(mylist, slist);

	for(int i = 0; i < 100; i++) {
		mylist.PushFront(i);
		slist.push_front(i);
	}
	compareWithStlList(mylist, slist);

	for(int i = 0; i < 10; i++) {
		mylist.PopBack();
		slist.pop_back();
	}
	compareWithStlList(mylist, slist);

	for(int i = 0; i < 10; i++) {
		mylist.PopFront();
		slist.pop_front();
	}
	compareWithStlList(mylist, slist);

	List<int> hlist = mylist;
	flist = mylist;

	//hlist.Print();
	//flist.Print();

	compareWithMyList(mylist, hlist);
	compareWithMyList(mylist, flist);

	test(mylist.GetSize() == 180);
	
	mylist.Clear();
	test(mylist.Empty());

	system("PAUSE");
	return 0;
}