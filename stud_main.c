#include "func.h"
extern pstu pstuhead,pstutail;
pstu pstuhead = NULL,pstutail = NULL;


int student_main()
{
	FILE *fp;
	pstu pst;
	fp = fopen("stu_info.txt","r+");
	if(NULL == fp)
	{
		perror("fopen");
		return -1;
	}
	pst = (pstu)calloc(1,sizeof(stu_info));
	while(memset(pst,0,sizeof(stu_info)),fscanf(fp,"%d%s%d%f",&pst->stu_id,pst->stu_name,&pst->stu_course_id,&pst->stu_score) != EOF)
	{
		student_list_tail_insert(&pstuhead,&pstutail,pst);
	}
	fclose(fp);
	return 0;
}