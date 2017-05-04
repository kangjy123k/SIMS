//学生界面
#include"func.h"

void student_part(){
	int n;
	printCover();
	printf("\t\t\t1、search student information\n");
	printf("\t\t\t2、exit\n");
	printf("please select a num:");
	scanf("%d",&n);
	switch(n)
	{
	case 1:system("cls");srh_stu();break;
	case 2:system("cls");exit(0);break;
	default:break;
}
}