#include "vector.h"
#include <vector>

int main() {
	Vector<int> vector;

	for(int i = 0; i < 100; i++)
		vector.PushBack(i);
	 
	system("PAUSE");
	return 0;
}
