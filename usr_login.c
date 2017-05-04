//µÇÂ½½çÃæ
#include "func.h"
extern pusr pusrhead ,pusrtail;
int roleflag;
void user_login()
{
	char user_name[20];
	char user_psd[20];
	char ch;
	int i = 0;
	pusr p;
	printf("\t\t\taccount£º");
	gets(user_name);
	printf("\t\t\tpassword£º");
	while((ch = getch()) != '\r')
	{
		if(ch != '\b')
		{
			printf("*");
			user_psd[i++] = ch;
		}
		else 
		{
			if(i > 0)
			{
				printf("\b");
				i--;
			}
			else continue;
		}
	}
	user_psd[i] = '\0';
	//gets(user_psd);
	p = pusrhead;
	while(p != NULL)
	{
		if(0 == strcmp(user_name,p->name))
		{
			if(0 == strcmp(user_psd,p->psd))
			{
				if(0 == p->role)
				{
					system("cls");
					roleflag = 0;
					student_part();
				}
				else {
					system("cls");
					roleflag = 1;
					admin_part();
				}
			}
			else{ 
				printf("\n\t\terror\n");
				Sleep(2000);
				system("cls");
				printCover();
				user_login();
			}
		}
		else p = p->pnext;
	}
	if(NULL ==p)
	{
		printf("\n\t\t\tnot found\n");
		Sleep(2000);
		system("cls");
		printCover();
		user_login();
	}

}