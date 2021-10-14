#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <time.h>
#define size 50
using namespace std;

void createMaze(char matrix[][size], int sizee);
void makeRoad(char matrix[][size], int sizee);
int play(char matrix[][size], int sizee);
void printJvals(int sizee);

int main()
{
	char M[size][size];
	int sizee;

	while(1)
	{
		cout << "Enter a size for the maze: ";
		cin >> sizee;
		if (sizee >= 10 && sizee <= 50)
			break;
		else
			cout << "You can not enter the value less than 10 or more than 50! Try again!" << endl;
	}

	createMaze(M, sizee);
	makeRoad(M, sizee);
	play(M, sizee);

	std::cout << endl << endl;
	std::system("pause");
	return 0;
}
void createMaze(char matrix[][size], int sizee)
{
	srand(time(0));
	int num;

	for (int i = 0; i < sizee; i++)
	{
		for (int j = 0; j < sizee; j++)
		{
			num = rand() % 2;
			if(num==0)
				matrix[i][j] = '0';
			else
				matrix[i][j] = '1';
		}
	}
}
void makeRoad(char matrix[][size], int sizee)
{
	srand(time(0));
	int i = 0, j = 0, k = 0, flag = 0;

	while (1)
	{ 
		for (k = 0; k < sizee/4; k++)
		{
			if (i != sizee)
			{
				matrix[i][j] = '0';
			}
			else
			{
				flag++; break;
			}
			i++;
		}
		if (flag > 0)
			break;
		if(j < sizee-1)
		{
			for (k = 0; k < sizee / 4; k++)
			{
				if (j < sizee)
				{
					matrix[i][j] = '0';
				}
				else
					break;
				j++;
			}
		}
		else if (j == sizee - 1)
		{
			for (k = 0; k < sizee / 4; k++)
			{
				matrix[i][j] = '0';
				j--;
			}
		}
	}
	int loc_j;

	for (int m = 0; m < sizee; m++)
	{		
		matrix[rand() % sizee][rand() % sizee] = char(36);
		loc_j = rand() % sizee;
		if (matrix[m][loc_j] != '1')
		{
			while (matrix[m][loc_j] != '1')
			{
				loc_j = rand() % sizee;;
			}
		}
		matrix[m][loc_j] = char(6);
	}
}
void printJvals(int sizee)
{
	for (int n = 0; n < sizee; n++)
	{
		if (n == 0)
			std::cout << setfill(' ') << setw(7) << right << n;
		else
			std::cout << setfill(' ') << setw(3) << right << n;
	}
	std::cout << endl;
	for (int v = 0; v < sizee * 3; v++)
	{
		if (v == 0)
			std::cout << setfill(' ') << setw(5) << right << "_";
		else
			std::cout << setfill(' ') << setw(1) << right << "_";
	}
	std::cout << endl;
}
int play( char matrix[][size], int sizee)
{
	ofstream outext;
	int cont = 0, i = 0, j;
	char direction;
	int goldens = 0;
	int a, b;

	while (1)
	{
		std::cout << "--------------------Buttons for directions-------------------" << endl << endl;
		std::cout << "Right -> D |  You     : " << char(2) << endl
			<<  "Left  -> A |  Monsters: " << char(6) << endl
			<<  "Up    -> W |  Golds   : " << char(36) << endl
			<<  "Down  -> S |" << endl << endl << endl;
		
		printJvals(sizee);
		
		for (int m = 0; m <sizee; m++)
		{
			for (int l = 0; l < sizee; l++)
			{
				if(cont!=0)
				{
					if (m == i && l == j)
						matrix[m][l] = 2;
				}
				if (l == 0)
					std::cout << setfill(' ') << setw(3) << right << m<<setw(1)<<"|";
				std::cout <<setfill(' ')<<setw(3)<<right<< matrix[m][l];
				if(l==sizee-1)
					std::cout << "|";
			}
			std::cout << endl;
		}
		if (cont != 0)
		{
			matrix[i][j] = '0';
		}
		if (i == sizee)
			break;
		std::cout << endl << endl;

		if (cont == 0)
		{
			i = 0;
			outext.open("Steps Locations.txt");
			if (!outext)
			{
				cout << "File could not open!" << endl;
				return 1;
			}
			outext << setw(5) << right << "X" << setw(6) << "Y" << endl << setw(6) << "---" << setw(6) << "---" << endl;
			while (1)
			{
				std::cout << "Where do you wanna start at(0,?)? (Enter a column location for first row i.e. 4): ";
				cin >> j;
				cont = 1;
				while (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid entry.  Enter a NUMBER: ";
					std::cin >> j;
				}
				if (matrix[i][j] == '1')
					cout << "You can not start at wall! Try again!" << endl << endl;
				else if(j<0 || j>sizee-1)
					cout << "Out of the maze! Try again!" << endl << endl;
				else
					break;
			}
		}
		else
		{
			a = i, b = j;
			while (1)
			{
				while (1)
				{
					std::cout << "Press a directional button to continue on the road: ";
					cin >> direction;

					if (direction == 'D' || direction == 'd')
					{
						j++; break;
					}
					else if (direction == 'A' || direction == 'a')
					{
						j--; break;
					}
					else if (direction == 'W' || direction == 'w')
					{
						i--; break;
					}
					else if (direction == 'S' || direction == 's')
					{
						i++; break;
					}
					else
					{
						std::cout << "Invalid button! Try again!" << endl << endl;
					}
				}
				if (matrix[i][j] == '1' || j < 0 || j >= sizee || i<0)
				{
					cout << endl << "You can not go into a wall! Try again!" << endl << endl;
					i = a;
					j = b;
				}
				else
					break;
			}
		}
		if (matrix[i][j] == char(36))
			goldens++;
		else if (matrix[i][j] == char(6))
		{
			std::cout <<endl<< "You Were Caught by a Monster!"<<endl<<"Press Enter to start the game again!";
			cont = 0;
			goldens = 0;
			outext.close();
			cin.ignore(2);
		}
		if(i!=sizee)
		    outext <<setw(5)<< i <<setw(6) << j << endl;
		std::system("CLS");
	}
	std::cout <<endl<< "The number of golds you collected: " << goldens << endl;
	outext.close();
}