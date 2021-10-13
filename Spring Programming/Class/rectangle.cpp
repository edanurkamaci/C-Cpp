#include <iostream>
#include <stdlib.h>
using namespace std;

class Rectangle
{
private:
	int width, height;

public:

	void setValues(int, int);

	int Area()
	{
		return width * height;
	}
	int Circumference()
	{
		return 2 * (width + height);
	}
};

void Rectangle::setValues(int x, int y)
{
	width = x;
	height = y;
}
int main()
{
	Rectangle rect;

	int wid, heig;

	cout << "Enter a height for a rectangle: ";
	cin >> heig;
	cout << "Enter a width for the rectangle: ";
	cin >> wid;

	rect.setValues(wid,heig);

	cout << "Informations about rectangle:" << endl << endl;
	cout << "Area of the rectangle: " << rect.Area()<<endl;
	cout << "Circumference of the rectangle: " << rect.Circumference();

	cout << endl << endl;
	system("pause");
	return 0;
}
