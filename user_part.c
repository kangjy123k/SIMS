//用户的增删改查
#include"func.h"
extern pusr pusrhead,pusrtail;

void add_usr(){
	char user_name[20];
	char user_psd[20];
	int k,i;
	
	pusr per;
	printCover();
	printf("\t\tplease enter the account：");
	scanf("%s",user_name);
	printf("\t\tplease enter the password：");
	scanf("%s",user_psd);
	printf("\t\tplease the role：");
	scanf("%d",&k);
	per = (pusr)calloc(1,sizeof(user_info));
	strcpy(per->name,user_name);
	strcpy(per->psd,user_psd);
	per->role = k;
	user_list_tail_insert(&pusrhead,&pusrtail,per);
	userlist_to_txt();
	printf("add successfully！");
	printf("\n\n\n\n\n\n\nreturn with 1：");
	scanf("%d",&i);
	if(1 == i)
		return;
}
void upd_usr(){
	char user_name[20];
	char user_psd[20];
	int k;
	int i;
	pusr p;
	FILE *fp;
	printCover();
	printf("please enter the account：");
	scanf("%s",user_name);
	p = pusrhead;
	while(p != NULL)
	{
		if(0 == strcmp(p->name,user_name))
		{
			printf("\n\n\taccount：%s\tpassword：%s\troot：%d\t\n",&p->name,&p->psd,p->role);
			break;
		}
		else if(NULL == p->pnext)
		{
			printf("not found");
		}
		p = p->pnext;
	}
	printf("\n\n\nplease enter the new password：");
	scanf("%s",user_psd);
	printf("please enter the new root：");
	scanf("%d",&k);
	strcpy(p->psd,user_psd);
	p->role = k;
	fp = fopen("user_account.txt","w");
	fclose(fp);
	fp = fopen("user_account.txt","w+");
	p = pusrhead;
	while(p != NULL)
	{
		fprintf(fp,"%s %s %d\n",p->name,p->psd,p->role);
		p = p->pnext;
	}
	fclose(fp);
	printf("\n\n\nupdate successfully!");
	printf("\n\n\n\n\n\n\nreturn with 1：");
	scanf("%d",&i);
	if(1 == i)
		return;
}
void del_usr(){
	char user_name[20];
	pusr p;
	int n = 0,flag = 0;
	printCover();
	printf("\tplease enter the account：");
	scanf("%s",user_name);
	p = pusrhead;
	while(p != NULL)
	{
		n++;
		if(0 == strcmp(p->name,user_name))
			break;
		p = p->pnext;
	}
	//user_outtxt(n);
	flag = user_list_delete(&pusrhead,&pusrtail,user_name);
	if(1 == flag)
	{
		userlist_to_txt();
		system("cls");
		printCover();
		printf("\n\ndelete successfully！");
		Sleep(2000);
	}
	else return;


}
void srh_usr(){
	char user_name[20];
	int i;
	pusr p;
	printCover();
	printf("please enter the account：");
	scanf("%s",user_name);
	p = pusrhead;
	while(p != NULL)
	{
		if(0 == strcmp(p->name,user_name))
		{
			printf("\n\n\taccount：%s\tpassword：%s\troot：%d\t\n",&p->name,&p->psd,p->role);
			break;
		}
		else if(NULL == p->pnext)
		{
			printf("not found!");
		}
		p = p->pnext;
	}
	printf("\n\n\n\n\n\n\nreturn with 1：");
	scanf("%d",&i);
	if(1 == i)
		return;

}
void userlist_to_txt(){
	pusr p;
	FILE *fp;
	fp = fopen("user_account.txt","w");
	fclose(fp);
	fp = fopen("user_account.txt","r+");
	p = pusrhead;
	while(p != NULL)
	{
		fprintf(fp,"%s %s %d\n",p->name,p->psd,p->role);
		p = p->pnext;
	}
	fclose(fp);

	
}



