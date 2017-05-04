#include"func.h"
extern pstu pstuhead;
void srh_all(){
	int n;
	pstu p;
	p=pstuhead;
	while(NULL!=p){
		printf("\n\t\t%d %s %d %5.2f",p->stu_id,p->stu_name,p->stu_course_id,p->stu_score);
		p=p->pnext;
	}
	printf("\n\n\n\return with 1:");
	scanf("%d",&n);
	if(n==1)
		return;
}
void srh_by_id(){
	int k;
	int n;
	pstu p;
	p=pstuhead;
	printf("please enter the id:");
	scanf("%d",&k);
	while(NULL!=p){
	    if(p->stu_id==k){
			printf("\t\t\t%d %s %d %5.2f",p->stu_id,p->stu_name,p->stu_course_id,p->stu_score);
		   break;
		}
		p=p->pnext;
		if(p==NULL){
			printf("No such a student!");
			break;
		}
	}
		printf("\n\n\nreturn with 1:");
		scanf("%d",&n);
		if(n==1)
		{
			return;
		}
	}


void srh_by_name(){
	char name[N];
	int n;
	pstu p;
	p=pstuhead;
	printf("\t\tplease enter the name£º");
	scanf("%s",name);
	
	while(NULL!=p){
	    if(!strcmp(p->stu_name,name)){
			printf("\t\t\t%d %s %d %5.2f",p->stu_id,p->stu_name,p->stu_course_id,p->stu_score);
		break;
		}
		p=p->pnext;
		if(p==NULL){
			printf("No such a student!");
			Sleep(2000);
			break;
		}
}
	printf("\n\n\nreturn with 1:");
		scanf("%d",&n);
		if(n==1)
		{
			return;
		}
}
