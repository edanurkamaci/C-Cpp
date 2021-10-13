#include <iostream>
#include <stdlib.h>

using namespace std;

void operation(int& x,int y);
void print(int x,int y);
void stati();

int main()
{
	int x = 15, y = 10;

	for (int i = 0; i < 4; i++)
	{
		operation(x, y);
		print(x, y);
		stati();
	}


	system("pause");
	return 0;
}
void operation(int& x,int y)
{
	x += x;
	y += y;

}
void print(int x,int y)
{
	cout << "x= " << x << endl;
	cout << "y= " << y << endl;
}
void stati()
{
	static int z = 20;

	z += z;
	cout << "z= " << z << endl << endl;
}
