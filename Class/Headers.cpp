#include <iostream>
#include <stdlib.h>
#include "class-Cars.h";

using namespace std;

int main()
{
	Cars c1;
   
	c1.brand = "Peugeot";
	c1.model = 3008;
	c1.color = "Dark";
	c1.proprt = "4x4";
	c1.age = 3;
	c1.print1();

	system("pause");
	return 0;
}