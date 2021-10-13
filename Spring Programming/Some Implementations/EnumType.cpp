#include <iostream>
#include <string>

using namespace std;

void main()
{
	enum sports{BASKETBALL,FOOTBALL,VOLEYBALL,BASEBALL,JOGGING,SWIMMING};

	sports myFavor = BASKETBALL;
	sports iHate = JOGGING;

	for (int i = myFavor; i <= iHate; i++)
	{
		cout << "I wrote true code" << endl;
	}
	cout << endl;
	cout << myFavor << endl << iHate << endl;
	
	switch (myFavor)
	{
	    case BASKETBALL:
	    {
		   cout << "BASKETBALL";
		   break;
	    }
	    default:
		   break;
	}

	system("pause");
}