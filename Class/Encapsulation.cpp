#include <iostream>
#include <string>

using namespace std;

class Student
{
   private:

   string id;
   string second_name; 
   
   public:

   string numb;
   string name;
   string department;
  
   void setId(string numb)
   {
	   id = numb; 
   }
   void setSname(string nme)
   {
	   second_name = nme; 
   }
   
   void print()
   {
	   cout << name <<" " << second_name << " " << numb << " " 
		    << department << " " << id << endl << endl;
	   //cout << id << " " << second_name;
   }
};

int main()
{
	Student s1;

	s1.name = "Eda";
	s1.department = "Computer Engineering";
	s1.numb = "152120191005";
	s1.setId("10040322888");
	s1.setSname("Nur");
	s1.print();

	system("pause");
	return 0;
}