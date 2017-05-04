#include"func.h"
extern pstu pstuhead,pstutail;
extern pusr pusrhead,pusrtail;
extern int roleflag;
void srh_stu(){
	int n;
	printCover();
	if(1==roleflag){
		printf("\t\t\t0.search all\n");
		printf("\t\t\t1.search by name\n");
		printf("\t\t\t2.search by id\n");
		printf("\t\t\t3.return\n");
		printf("select a num:");
		scanf("%d",&n);
		switch(n){
			case 0:system("cls");printCover(); srh_all();break;
			case 1:system("cls");printCover(); srh_by_name();break;
			case 2:system("cls");printCover(); srh_by_id();break;
			case 3:return;
			default: break;
		}

	}
	return;
}
void add_stu(){
	pstu p1;
	p1=(pstu)calloc(1,sizeof(stu_info));
	printCover();
	printf("\t\tplease add the id:");
	scanf("%d",&p1->stu_id);
	printf("\t\tplease add the name:");
	scanf("%s",p1->stu_name);
	printf("\t\tplease add the course_id:");
	scanf("%d",&p1->stu_course_id);
	printf("\t\tplease add the score:");
	scanf("%5.2f",&p1->stu_score);
	student_list_tail_insert(&pstuhead,&pstutail,p1);
	stulist_to_txt();
	printf("add successfully!");
	Sleep(100);
}
void upd_stu(){
	pstu p2;
	int k;
	char stu_name[N];
	int stu_course_id;
	float stu_score;
	p2=pstuhead;
	printCover();
	printf("\t\tselect the num:");
	scanf("%d",&k);
	while(p2!=NULL){
		if(p2->stu_id==k){
			printf("\n\t\t%d %s %d %5.2f",p2->stu_id,p2->stu_name,p2->stu_course_id,p2->stu_score);
			break;
	}
		p2=p2->pnext;
		if(NULL==p2){
		printf("\t\tNo such a student ID!");
		Sleep(200);
		return;
		}
	}
	printf("\n\t\tplease enter the name:");
	scanf("%s",stu_name);
	printf("\t\tplease enter the course_id:");
	scanf("%d",&stu_course_id);
	printf("\t\tplease enter the score:");
	scanf("%5.2f",&stu_score);
	p2->stu_course_id=stu_course_id;
	p2->stu_score=stu_score;
	strcpy(p2->stu_name,stu_name);
	stulist_to_txt();
	printf("update successfully!");
	Sleep(200);
	return;

	
}
void del_stu(){
		pstu p2;
	int k;
	p2=pstuhead;
	printCover();
	printf("select the num:");
	scanf("%d",&k);
	while(p2!=NULL){
		if(p2->stu_id==k){
			printf("\n\t\t%d %s %d %5.2f",p2->stu_id,p2->stu_name,p2->stu_course_id,p2->stu_score);
			break;
	}
		p2=p2->pnext;
		if(NULL==p2){
		printf("\t\tNo such a student ID!");
		Sleep(200);
		return;
		}
	}
	student_list_delete(&pstuhead,&pstutail,p2);
	stulist_to_txt();
	printf("delete successfully!");
	return;
}

void stulist_to_txt(){
	pstu p;
	FILE *fp;
	fp=fopen("stu_info.txt","w");
	fclose(fp);
	fp=fopen("stu_info.txt","r+");
	p=pstuhead;
	while(NULL!=p){
		fprintf(fp,"%d %s %d %5.2f",p->stu_id,p->stu_name,p->stu_course_id,p->stu_score);
		p=p->pnext;
	}
	fclose(fp);

}

	
