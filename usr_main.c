//以文本中的用户建立链表，刷新登陆界面
#include "func.h"
extern pusr pusrhead ,pusrtail;
pusr pusrhead = NULL,pusrtail = NULL;

int user_main()
{
	FILE *fp;
	pusr per;
	fp = fopen("user_info.txt","r+");
	if(NULL == fp)
	{
		perror("fopen");
		return -1;
	}
	per = (pusr)calloc(1,sizeof(user_info));
	while(memset(per,0,sizeof(user_info)),fscanf(fp,"%s %s%d",per->name,per->psd,&per->role) != EOF)
	{
		user_list_tail_insert(&pusrhead,&pusrtail,per);
	}
	fclose(fp);
	user_login();
}