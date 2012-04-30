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

int main() {
	List<int> mylist;
	std::list<int> slist;
	for(int i = 0; i < 10; i++) {
		mylist.PushBack(i);
		slist.push_back(i);
	}
	compareWithStlList(mylist, slist);
	
	system("PAUSE");
	return 0;
}