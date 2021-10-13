#include "class-Cars.h"
#include <iostream>
#include <string>

using namespace std;

void Cars::print1()
{
	cout << Cars::brand << " " << Cars::model << " " << Cars::proprt << " " << Cars::color << " " 
		<< Cars::age
		<< endl << endl;
}