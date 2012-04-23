#include "vector.h"
#include <vector>

void test(int expression) {
	if(expression) std::cout << "Test completed" << std::endl;
	else std::cout << "Test error" << std::endl;
}	

void compare(Vector<int> &myvector, std::vector<int> &vector) {
	for(int i = 0; i < 50; i++) 
		if(myvector[i] != vector[i]) {
			std::cout << "Compare error" << std::endl;
			return;
		}
	std::cout << "Full compare" << std::endl;
}

int main() {
	Vector<int> myvector, tvector(100);
	//Vector<int>::Iterator iterator;
	std::vector<int> svector;
	
	for(int i = 0; i < 100; i++) myvector.PushBack(i);
	for(int i = 0; i < 100; i++) svector.push_back(i);
	compare(myvector, svector);

	//myvector.PopBack();
	//svector.pop_back();
	//compare(myvector, svector);
	
	test(svector.back() == myvector.GetBackElement());
	test(svector.front() == myvector.GetFrontElement());
	test(svector.size() == myvector.GetSize());
	//test(svector[55] == myvector[55]);
		
		
		//svector.insert();
		/*svector.clear();
		svector.erase();
		;*/

	

	//Vector<int> mvector = myvector;
	//tvector = myvector;

	//vector.PopBack();
	//vector.PopFront();

	//myvector.Print();
	//mvector.Print();
	//tvector.Print();
	 
	system("PAUSE");
	return 0;
}
