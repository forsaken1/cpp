#include "String.h"

void test(int expression) {
	if(expression) cout << "Test successful" << endl;
	else cout << "Test error" << endl;
}

int main() {
	String nstr("Alexey"), snstr("Krilov"), space(" "), empty, any = nstr;
	
	test(nstr.getRC() == 2);
	test(any.getRC() == nstr.getRC());

	test(any == nstr);
	test(any == "Alexey");

	any += space + snstr;
	test(any == "Alexey Krilov");
	test(nstr.getRC() == 1);

	test(nstr  == "Alexey");
	test(snstr == "Krilov");
	test(nstr  >  "Alexex");
	test(nstr  <  "Alexez");
	test(nstr  >= "Alexey");
	test(nstr  <= "Alexey");
	test(nstr  >= "Alexex");
	test(nstr  <= "Alexez");

	test(nstr  == String("Alexey"));
	test(snstr == String("Krilov"));
	test(nstr  >  String("Alexex"));
	test(nstr  <  String("Alexez"));
	test(nstr  >= String("Alexey"));
	test(nstr  <= String("Alexey"));
	test(nstr  >= String("Alexex"));
	test(nstr  <= String("Alexez"));

	test(nstr + snstr == "AlexeyKrilov");
	test(nstr + space + snstr == "Alexey Krilov");
	test(nstr + empty == "Alexey");

	test(nstr.GetLength() == 6);
	test(snstr.GetLength() == 6);
	test(space.GetLength() == 1);

	test(!empty);

	empty = nstr;
	test(nstr.getRC() == empty.getRC());
	test(nstr.getRC() == 2);
	test(empty == nstr);

	nstr = space;
	test(nstr == space);
	test(nstr == " ");
	test(empty == "Alexey");

	test(empty[0] == 'A');
	empty[5] = 'v';
	test(empty == "Alexev");
	test(empty(0, 4) == "Alex");
	
	system("PAUSE");
	return 0;
}