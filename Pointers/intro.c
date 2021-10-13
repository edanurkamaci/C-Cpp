#include <stdio.h>
#include <stdlib.h>


int main()
{
	int numb = 4;
	double dnumb = 5.9;
	float fnumb = 8.7;
	char chara = 'E';


	printf("            VALUES            \n");

	printf("%d\n", numb);
	printf("%.2f\n", dnumb);
	printf("%.2f\n", fnumb);
	printf("%c\n\n", chara);

	printf("            LOCATIONS            \n");

	printf("%x\n", &numb);
	printf("%x\n", &dnumb);
	printf("%x\n", &fnumb);
	printf("%x\n", &chara);

	
	int numb2=100;
	int *n = &numb2;
	char ch2 = 'K';
	char *c = &ch2;

	printf("\n%d\n", numb2);
	printf("%c\n", ch2);
	printf("\n%x\n", n);
	printf("%x\n", c);

	int var = *n;
	printf("\n%d\n", var);

	n+=5;
	c++;
	printf("\n%x\n", n);
	printf("%x\n", c);

	printf("\n\n");
	system("pause");

	return 0;
}