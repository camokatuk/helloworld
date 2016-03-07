#include "ClassX.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ClassÕóÿñ x;
	x.remove(1);
	x.printAll();
	
	x.add(12);
	x.printAll();

	x.add(1);
	x.add(2);
	x.add(3);
	x.printAll();

	x.remove(1);
	x.remove(1);
	x.printAll();

	x.add(4);
	x.printAllGets();
	
}

