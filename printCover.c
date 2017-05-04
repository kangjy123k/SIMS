#include  "func.h"
#define HEADMAX 80
void printCover()
{
	int i,j;
	for(j = 0;j < 3;j++)
	{   if(1 == j)
		{
			for(i = 0;i < 28;i++)
				printf("*");
			printf("student information system");
			for(i = 0;i < 29;i++)
				printf("*");
			printf("\n");
			continue;
		}
		for(i  = 0;i < HEADMAX;i++)
		{
			printf("*");
		}
		printf("\n");
	}
}