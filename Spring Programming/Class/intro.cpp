#include <iostream>
#include <stdlib.h>
using namespace std;

class introduction
{
    public:
	   void sendMessage()
	   {
		   cout << "Hello!! Welcome to my page!" << endl << endl;
	   }
};
int main()
{

	introduction message;

	message.sendMessage();
    
	cout << endl << endl;
	system("pause");
	return 0;
}
