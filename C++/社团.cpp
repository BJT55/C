#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define STU_NUM		40	  			/* ����ѧ������ */
#include<windows.h>

struct student
{
	long	number;		//ѧ��ѧ��			
	char	name[10];          //ѧ������    	
	long    phone;	    // ѧ���绰���� 
	char    point[20];		           //ѧ���ص�      	
    char    role[15];  //ѧ��ְ�� 
	char    gender[5];   //ѧ���Ա� 
	int     age;               //ѧ������ 
};

typedef struct student STU;   //����ṹ������ 

void Appendrole(STU *head, int n)          //����³�Ա 
{
	int		j;
	STU		*p;
	for (p=head; p<head+n; p++)
	{
		printf("\n����ѧ��:");
		scanf("%d", &p->number);
		printf("��������:");
		scanf("%s", p->name);		
		printf("�����ֻ���:");
		scanf("%d", &p->phone);	
		printf("�����س�:");
		scanf("%s", p->point);	
		printf("����ְ��:");
		scanf("%s", p->role);	
		printf("�����Ա�:");
		scanf("%s", p->gender);	
		printf("��������:");
		scanf("%d", &p->age);	
	}
}


void Printrole(STU *head, int n)//��ӡn�����ų�Ա����Ϣ 
{
	STU  *p;
	int  i;
	char str[100] = {'\0'};
	strcat(str, "ѧ��    ����  ");
	strcat(str,"     �ֻ���      �س�       ְ��     �Ա�     ����");
	printf("%s", str);           		/* ��ӡ��ͷ */	
	for (p=head; p<head+n; p++)  	/* ��ӡn��ѧ������Ϣ */
	{
		printf("\n%3d %8s %11d %10s %10s %6s %7d\n", p->number, p->name,p->phone,p->point,p->role,p->gender,p->age);		
	
	}
}

int Searchrole(STU *head,char a[],int n)   //����ѧ����ְ�� 
{

	int i;
	for (i=0; i<n; i++)
	{
		if (strcmp((head+i)->role,a)==0)	
		return i;
	}
	return -1;
}

void Searchperson(STU *head, int n)
{
	char zhiwu[15];
	 int findNo;
	printf("\n������Ҫ���ҵ�ְ��:"); 	
	scanf("%s", zhiwu);
	findNo = Searchrole(head,zhiwu,n);
	if (findNo == -1)
	{
		printf("\nû���ҵ�!\n");
	}
	else
	{
		Printrole(head+findNo, 1);
	}
}

char Menu(void)   //��ʾ�˵����ҿ������û�����ѡ�� 
{ 
	char ch;
	printf("\n���Ź���\n");
	printf(" 1.�³�Ա���\n");
	printf(" 2.��ְλ����\n");
	printf(" 3.��Ա��ʾ\n");	
	printf(" 0.�˳�ϵͳ\n");
	printf("����������ѡ��:");
	scanf(" %c", &ch); /*��%cǰ���һ���ո񣬽����ڻ������еĻس�������*/
	return ch;
}
int main()                           				
{
	char	ch;
	int	    n;
	STU 	stu[STU_NUM]; 
	printf("������ѧ����n(n<40):");
	scanf("%d", &n);
	while (1)
	{
		ch = Menu();					    /* ��ʾ�˵�������ȡ�û����� */
		switch (ch)
		{
			case'1':Appendrole(stu, n);/* �����³�Ա���ģ�� */
						break;
			case'2':Searchperson(stu, n );/* ���ð�ְλ����ģ�� */
						break;
			case'3':Printrole(stu, n);	/* ��Ա��ʾģ�� */
						break;			
			case'0':exit(0);                  /* �˳����� */
						printf("�������!");
			       	break;
			default:printf("�������!");
						break;
		}		
	}
}

