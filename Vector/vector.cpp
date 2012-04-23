#include "vector.h"
#include <vector>

int main() {
	Vector<int> vector, tvector(100);

	for(int i = 0; i < 5; i++)
		vector.PushBack(i);

	Vector<int> mvector = vector;
	tvector = vector;

	//vector.PopBack();
	//vector.PopFront();

	vector.Print();
	mvector.Print();
	tvector.Print();
	 
	system("PAUSE");
	return 0;
}
