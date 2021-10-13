#include <iostream>
#include <stdlib.h>
using namespace std;

void main()
{

	enum soldSituation
	{
		notsold,//0
		sold,//1
	};

	typedef struct car
	{
		bool soldSituation;

		union
		{
			int cost;
			char brand[20];
		}information;

	}car;

	car z[2];
	int i;

	z[0].soldSituation = 0;
	strcpy_s(z[0].information.brand, "AUDI");

	z[1].soldSituation = 1;
	z[1].information.cost = 17000;

	for (i = 0; i < 2; i++)
	{
		if (z[i].soldSituation == notsold)
		{
			cout << "The brand of the car is: " << z[i].information.brand<<endl;
		}
		else
		{
			cout << "The cost of the car is: " << z[i].information.cost<<endl;
		}
	}


	cout << endl << endl;
	system("pause");
}