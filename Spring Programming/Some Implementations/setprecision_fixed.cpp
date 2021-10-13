#include <iostream>
#include <stdlib.h>
#include <iomanip> // You have to use this library for using that functions

using namespace std;

// Using setprecision() func with fixed and showpoint 

int main()
{
	double x = 15.6487;
	double y = 27.64;
	double z = 43.648;

	cout << fixed << showpoint; // they're used not to make when we use setprecision()

	cout << setprecision(2) // that provide to write 2 digits after dot 
		<< "x: " << x << endl << "y: " << y << endl << "z: " << z << endl<<endl;

	cout << setprecision(3) // that provide to write 3 digits after dot 
		<< "x: " << x << endl << "y: " << y << endl << "z: " << z << endl << endl;

	cout << setprecision(4) // that provide to write 4 digits after dot 
		<< "x: " << x << endl << "y: " << y << endl << "z: " << z << endl << endl;

	cout << setprecision(3) <<" "<< x << " " << setprecision(4) << y << " " << setprecision(2) << z;

	printf("\n\n");
	system("pause");

	return 0;
}