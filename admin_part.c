#include"func.h"

void admin_part(){
	int n;
	printf("\t\t\t1. search student information\n");
	printf("\t\t\t2. add student information\n");
	printf("\t\t\t3. update student information\n");
	printf("\t\t\t4. delete student information\n");
	printf("\t\t\t5. add user account\n");
	printf("\t\t\t6. update user account\n");
	printf("\t\t\t7. delete user account\n");
	printf("\t\t\t8. search user account\n");
	printf("\t\t\t9. exit\n");
	printf("\t\t\tplease select a num:\n"); 
	scanf("%d",&n);
	switch(n){
	case 1:system("cls");srh_stu();break;
	case 2:system("cls");add_stu();break;
    case 3:system("cls");upd_stu();break;
    case 4:system("cls");del_stu();break;
    case 5:system("cls");add_usr();break;
	case 6:system("cls");upd_usr();break;
	case 7:system("cls");del_usr();break;
	case 8:system("cls");srh_usr();break;
	case 9:system("cls");break;
	default:break;
	}
}