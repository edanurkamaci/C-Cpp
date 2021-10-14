#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <iomanip>
#include <fstream>
#define size 21
using namespace std;

void input_image(ofstream &outext, double A[][size],int inp_size,int wht_px, int blck_px);
void kernel(ofstream &outext, double B[][size], int fsize);
void mirrored(ofstream &outext, double x[][size], double y[][size], int size2, int fsize);
void cutted_edge(ofstream &outext, double mirrored[][size], double kernel[][size], double cutted[][size], int new_size, int fsize);
void convertSize(ofstream &outext, double Z[size][size],double C[][size],int size3);
void print(ofstream &outext, double matrix[][size], int sizee);
void print_(ofstream &outext, int sizee);

int main()
{
	ifstream inFile;
	ofstream outFile;

	int img_size, filt_size, white_px, black_px;
	double input_img[size][size];
	double mirrored_img[size][size];
	double kernell[size][size] = {0};
	double cutted_img[size][size] = { 0 };

	outFile.setf(ios::fixed);
	outFile.precision(4);
	cout.setf(ios::fixed);
	cout.precision(4);
	 
	inFile.open("inputs.txt");

	if (!inFile)
	{
		cout << "ERROR!!! There is no file desired!" << endl << endl;
		return 1;
	}
	outFile.open("output.txt");
	
	inFile >> img_size >> filt_size >> white_px >> black_px;

	if ((filt_size / 2) * 2 + img_size > 21)
	{
		cout << "ERROR!!! The mirrored matrix to be formed will exceed the limit!" << endl << endl;
		return 1;
	}

	input_image(outFile,input_img, img_size, white_px, black_px);
	kernel(outFile, kernell, filt_size);
	mirrored(outFile, input_img, mirrored_img, img_size, filt_size);
	cutted_edge(outFile, mirrored_img, kernell, cutted_img, img_size+(filt_size/2)*2, filt_size);

	inFile.close();
	outFile.close();

	cout << endl << endl;
	system("pause");
	return 0;
}
void input_image(ofstream &outext,double A[][size], int inp_size, int wht_px, int blck_px)
{
	srand(time(0));
	
	for (int i = 0; i < inp_size; i++)
	{
		for (int j = 0; j < inp_size; j++)
		{
			A[i][j] = rand() % wht_px + blck_px;
		}
	}
	outext << " Input Image (" << inp_size << "x" << inp_size << ")" << endl; ;
	cout << " Input Image (" << inp_size << "x" << inp_size << ")" << endl; ;
	
	print(outext,A, inp_size);
}
void kernel(ofstream &outext,double B[][size], int fsize)
{
	int f,d,i,j;
	double value;

	f = fsize / 2;
	for (d = 0; d < f; d++)
	{
		value = 1.0 / pow((2 * (d + 1) + 1), 2);
		for (i = -(d + 1); i <= d + 1; i++)
		{
			for (j = -(d + 1); j <= d + 1; j++)
				B[f - i][f - j] = B[f - i][f - j] + value;
		}
	}
	for (i = 0; i < fsize; i++)
	{
		for (j = 0; j < fsize; j++)
		{
			B[i][j] = B[i][j] / static_cast<double>(fsize);
		}
	}
	outext << " Gaussian Filter (" << fsize << "x" << fsize << ")" << endl;
	cout << " Gaussian Filter (" << fsize << "x" << fsize << ")" << endl;
	print(outext,B, fsize);
}
void mirrored(ofstream &outext, double x[][size], double y[][size], int size2, int fsize)
{
	int k = 1;
	int new_size,increase=fsize / 2;
	double Z[size][size] = { 0 };

	while (k <= increase)
	{
		y[size][size] = { 0 };
		new_size = k * 2 + size2;
		for (int i = 0; i < new_size; i++)
		{
			for (int j = 0; j < new_size; j++)
			{
				if (i == 0 && j == 0)
				{
					y[i][j] = x[i][j];
				}
				else if (i == 0 && j == new_size - 1)
				{
					y[i][j] = x[i][j - 2];
				}
				else if (i == new_size - 1 && j == 0)
				{
					y[i][j] = x[i - 2][j];
				}
				else if (i == new_size - 1 && j == new_size - 1)
				{
					y[i][j] = x[i - 2][j - 2];
				}
				else if (i == 0 || i == new_size - 1)
				{
					if (i == 0)
						y[i][j] = x[i][j - 1];
					else
						y[i][j] = x[i - 2][j - 1];
				}
				else if (j == 0 || j == new_size - 1)
				{
					if (j == 0)
						y[i][j] = x[i - 1][j];
					else
						y[i][j] = x[i - 1][j - 2];
				}
				else
				{
					y[i][j] = x[i - 1][j - 1];
				}
			}
		}
		for (int i = 0; i < new_size; i++)
		{
			for (int j = 0; j < new_size; j++)
			{
				x[i][j] = y[i][j];
			}
		}
		k++;
	}
	outext << "Input Grid: Edge Mirrored Image (21x21)"<<endl ;
	cout << "Input Grid: Edge Mirrored Image (21x21)" << endl;
	convertSize(outext,Z, y, new_size);
}
void cutted_edge(ofstream &outext, double mirrored[][size], double kernel[][size],double cutted[][size], int new_size, int fsize)
{
	int k = 0, l = 0,x=0,y=0;
	int start, end;
	double conZ[size][size] = { 0 };
	
	start = fsize / 2;
	end = (new_size - 1) - fsize / 2;

	for (int i = start; i <= end; i++)
	{
		for (int j = start; j <= end; j++)
		{
			for (int m = 0 + k; m < fsize + k; m++)
			{
				for (int n = 0 + l; n < fsize + l; n++)
				{
					cutted[k][l] += kernel[x][y] * mirrored[m][n];
					y++;
				}
				y = 0;
				x++;
			}
			cutted[k][l] = cutted[k][l] / (fsize * fsize);
			x = 0;
			l++;
		}
		l = 0;
		k++;
	}
	outext << " Output Grid: Cutted-Edge Image (21x21)"<<endl;
	cout << " Output Grid: Cutted-Edge Image (21x21)" << endl;
	convertSize(outext,conZ, cutted, k);
	outext << " Output (Filtered) Image ("<<k<<"x"<<k<<")"<<endl ;
	cout << " Output (Filtered) Image (" << k << "x" << k << ")" << endl;
	print(outext,cutted, k);
}
void convertSize(ofstream &outext, double Z[size][size], double C[][size], int size3)
{
	int start = size / 2 - size3 / 2;
	int end = size / 2 + size3 / 2;
	int k = 0, l = 0,check=0;

	for (int i = start; i <= end; i++)
	{
		for (int j = start; j <= end; j++)
		{
			Z[i][j] = C[k][l];
			l++;
		}
		l = 0;
		k++;
	}
    print(outext,Z, 21);
}
void print(ofstream &outext, double matrix[][size], int sizee)
{
	print_(outext,sizee);
	for (int i = 0; i < sizee; i++)
	{
		for (int j = 0; j < sizee; j++)
		{
			outext <<setw(9) <<right << matrix[i][j];
			cout << setw(9) << right << matrix[i][j];
		}
		outext << endl;
		cout << endl;
	}
	print_(outext, sizee);
	outext << endl;
	cout << endl;
}
void print_(ofstream &outext, int sizee)
{
	for (int i = 0; i < sizee*9; i++)
	{
		outext << "-";
		cout << "-";
	}
	outext << endl;
	cout << endl;
}