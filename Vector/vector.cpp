#include "vector.h"
#include <vector>
#define VECTOR_SIZE 100

void test(int expression) {
	if(expression) std::cout << "Test completed" << std::endl;
	else std::cout << "Test error" << std::endl;
}	

void compareWithStlVector(Vector<int> &myvector, std::vector<int> &vector) {
	for(int i = 0; i < (int)vector.size(); i++) 
		if(myvector[i] != vector[i]) {
			std::cout << "Test error: Compare error" << std::endl;
			return;
		}
	std::cout << "Test completed: Full compare" << std::endl;
}

void compareWithMyVector(Vector<int> &myvector, Vector<int> &vector) {
	for(int i = 0; i < vector.GetSize(); i++) 
		if(myvector[i] != vector[i]) {
			std::cout << "Test error: Compare error" << std::endl;
			return;
		}
		std::cout << "Test completed: Full compare" << std::endl;
}

int main() {
	Vector<int> myvector, tvector(100);
	Vector<int>::Iterator iterator;
	std::vector<int> svector;
	std::vector<int>::iterator iter;

	//Test push back
	for(int i = 0; i < VECTOR_SIZE; i++) myvector.PushBack(i);
	for(int i = 0; i < VECTOR_SIZE; i++) svector.push_back(i);
	compareWithStlVector(myvector, svector);
	
	//Test pop back
	myvector.PopBack();
	svector.pop_back();
	compareWithStlVector(myvector, svector);
	
	//Test constructor copy, operator=
	Vector<int> mvector = myvector;
	tvector = myvector;
	compareWithMyVector(myvector, mvector);
	compareWithMyVector(myvector, tvector);
	
	//any tests (Back, Front, GetSize, operator[])
	test(svector.back() == myvector.GetBackElement());
	test(svector.front() == myvector.GetFrontElement());
	test(svector.size() == myvector.GetSize());
	test(mvector.GetSize() == myvector.GetSize());
	test(svector[55] == myvector[55]);
	test(tvector[45] == myvector[45]);
		
	//Test Begin, Insert, operator[]
	iterator = myvector.Begin();
	iter = svector.begin();
	myvector.Insert(iterator, 1);
	svector.insert(iter, 1);
	test(svector[0] == myvector[0]);

	//Test End, Erase
	iterator = myvector.End();
	iterator--;
	myvector.Erase(iterator);
	svector.pop_back();
	compareWithStlVector(myvector, svector);

	//Test "delete all"
	myvector.Clear();
	svector.clear();
	compareWithStlVector(myvector, svector);

	test(svector.empty() == myvector.Empty());
	 
	system("PAUSE");
	return 0;
}
