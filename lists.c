#include"func.h"
//学生信息尾插
void student_list_tail_insert(pstu *pphead,pstu *pptail,pstu p)
{
	pstu pnew = (pstu)calloc(1,sizeof(stu_info));
	memcpy(pnew,p,sizeof(stu_info));
	if(NULL == *pptail)
	{
		*pphead = pnew;
		*pptail = pnew;
	}else{
		(*pptail)->pnext = pnew;
		*pptail = pnew;
	}
}
void user_list_tail_insert(pusr *pphead,pusr *pptail,pusr p)
{
	pusr pnew = (pusr)calloc(1,sizeof(user_info));
	memcpy(pnew,p,sizeof(user_info));
	if(NULL == *pptail)
	{
		*pphead = pnew;
		*pptail = pnew;
	}else{
		(*pptail)->pnext = pnew;
		*pptail = pnew;
	}
}
int user_list_delete(pusr *pphead,pusr *pptail,char* str)
{
	pusr pcur=*pphead;
	pusr ppre=*pptail;
	if(NULL==pcur)
	{
		printf("\n\t\t\tno data!\n");
		Sleep(2000);
		return -1;
	}else if(0 == strcmp(pcur->name,str))
	{
		*pphead=pcur->pnext;
		if(NULL==pcur->pnext)
		{
			*pptail=NULL;
		}
		free(pcur);
		pcur=NULL;  
	}else{
		while(pcur!=NULL)
		{
			if(0 == strcmp(pcur->name,str))
			{
				ppre->pnext=pcur->pnext;
				break;
			}
			ppre=pcur;
			pcur=pcur->pnext;
		}
		if(NULL==pcur)
		{
			printf("\n\t\t\tno data\n");
			Sleep(2000);
			return -1;
		}
		if(NULL==ppre->pnext)
		{
			*pptail=ppre;
		}
		free(pcur);
		pcur=NULL;
	}
	return 1;
}
void student_list_delete(pstu *pphead,pstu *pptail,int i)
{
	pstu pcur=*pphead;
	pstu ppre=*pptail;
	if(NULL==pcur)
	{
		printf("\t\t\tno data\n");
		Sleep(2000);
		return ;
	}else if(i==pcur->stu_id)
	{
		*pphead=pcur->pnext;
		if(NULL==pcur->pnext)
		{
			*pptail=NULL;
		}
		free(pcur);
		pcur=NULL;  
	}else{
		while(pcur!=NULL)
		{
			if(pcur->stu_id==i)
			{
				ppre->pnext=pcur->pnext;
				break;
			}
			ppre=pcur;
			pcur=pcur->pnext;
		}
		if(NULL==pcur)
		{
			printf("\t\t\tno data\n");
			Sleep(2000);
			return ;
		}
		if(NULL==ppre->pnext)
		{
			*pptail=ppre;
		}
		free(pcur);
		pcur=NULL;
	}
}