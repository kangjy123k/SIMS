#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#define  N 10
typedef struct stu_info
{
	int stu_id ;
	char stu_name[N];
	int stu_course_id;
	float stu_score;
	struct stu_info*pnext;
}stu_info ,*pstu;
typedef struct usr_info
{
	char name[N];
	char psd[N];
	int role;
	struct usr_info*pnext;
}user_info, *pusr;

void printCover();
void user_login();
void user_list_tail_insert(pusr*,pusr*,pusr);
int user_list_delete(pusr*,pusr*,char*);
int user_main();
void student_part();
void admin_part	();
void add_usr();
void del_usr();
void srh_usr();
void upd_usr();
int user_intext(char*,char*,int);
void user_outtxt(int);
void srh_stu();
void add_stu();
void upd_stu();
void del_stu();
void student_list_tail_insert(pstu*,pstu*,pstu);
int student_main();
void srh_all();
void srh_by_id();
void srh_by_name();
void stulist_to_txt();
void student_list_delete(pstu*,pstu*,int);
void userlist_to_txt();