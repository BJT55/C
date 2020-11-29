#include<stdio.h> 
#include<stdlib.h>  
#include<time.h> 

int num = 5;     //�ٶ�������Ϊ5
int count;    //���д��� 
struct PCB*line(struct PCB *q);    //�������� 
struct PCB*input(struct PCB *p,int i);    //������������ 
void sort(PCB *head);   //ð������ 
void run(struct PCB *p);    //����
void show(struct PCB *head);    //��ӡ������Ϣ
void check(struct PCB *p);     //�ж�����ʱ���Ƿ�Ϊ0

//���̿��ƿ�ṹ��
struct PCB 
{       
    char name[5];  //������      
    int time;  //����ʱ��       
	int prior;  //������       
	char status;  //����״̬��RΪ����,EΪ����       
	struct PCB *pre;  //ǰһ���̵�ָ��        
	struct PCB *next;  //��һ���̵�ָ��
};
struct PCB*head;    //ͷָ��
struct PCB*tail;    //βָ��

//�����������			
struct PCB*input(struct PCB *p, int i)    
{              
    p->name[0]='P';        //��ʼ�������� 
	p->name[1]='C';        
	p->name[2]='B';        
	p->name[3]=i+49;                
	printf("���� %s\n",p->name);        
	printf("���̵�����ʱ�䣺");        
	scanf("%d",&p->time);     
	printf("���̵���������");        
	scanf("%d",&p->prior);  
	printf("\n"); 	  
	p->status='R';      	//���̳�ʼ״̬Ϊ����              
	p->next=NULL;        //��ʼָ���һ���̵�ָ��Ϊ��       
	return p;     //���ؽ��� 
}           

//������������ 
struct PCB*line(struct PCB *q)
{       
    int i;        
    struct PCB*p=NULL;  //pΪ�����ж���PCBָ��        
	head=tail=NULL;     //��ʼ��ͷβָ��       
	for( i=0; i<num; i++ )
	{               
		p=(struct PCB*)malloc(sizeof(struct PCB));  //����ռ䣬��pָ�����PCB               
		input(p,i);         //���������Ϣ               
		p->next=NULL;               
		if( head==NULL )    //ͷָ��Ϊ�� 
		{                      
			tail=head=p;                      
			p->pre=NULL;               
		}
		else
		{                      
			p->pre=tail;                      
			tail->next=p;                      
			tail=p;               
		}        
	}        
	return p; 
}


//ð������ 
void sort(struct PCB *phead)
{     
    struct PCB *a,*b;  //�������a,b        
	int i;        
	for( i=0; i<num; i++ )
	{               
	    a=head;     //��ʼ������aΪhead               
		b=head->next;     //��ʼ������bΪhead->next               
		while( b!=NULL )    //b�ǿ� 
		{                       
		    if( a->prior < b->prior )     //a�����ȼ�С��b��������  
			{   
			    if( a->pre!= NULL)       //pָ��ǰһ���̵�ָ�벻Ϊ�� 
		        {               
		            a->pre->next=b;  //��p��ǰһ���̵ĺ�ָ��ָ��max           
		        }
		        else   //p��ǰһ����ָ��Ϊ��,��Ϊͷָ�� 
		        {                 
		            head=b;    //��ͷָ��ָ��max          
		        }           
		        if( b->next!=NULL )   //max����һ����ָ�벻Ϊ�� 
		        {                
		            b->next->pre=a;  //��max����һ���̵�ǰָ��ָ��p           
		        }
				b->pre = a->pre;    
		        a->next = b->next;       
		        b->next = a;       
		        a->pre = b;    
				a=a->pre;                              
				b=b->next;                                                                             
			} 
			a=a->next;                 
			b=b->next;                               
		} 
	} 
}



//��ӡ������Ϣ 
void show(struct PCB *head)
{    
    printf("������Ϣ��\n");    
    struct PCB *p;        
	for(p = head; p!=NULL; p =p->next)
	{               
	    printf("���� %s\t ������ %d\t ����ʱ�� %d\t ״̬ %c\n",p->name,p->prior,p->time,p->status);        
	} 
}

//���� 
void run(struct PCB *p)   
{             
    count++;  //���д���+1    
	p->time--;  //����ʱ���1 
	if(p->prior>0)            	
	p->prior--;   //��������1 
	printf("\n�� %d ������:\n",count);      
	printf("���к���: %s\t ������ %d\t ����ʱ��:%d\n\n", p->name, p->prior, p->time);        
}

//�ж�����ʱ���Ƿ�Ϊ0 
void check(struct PCB *p)
{        
    if(p->time <= 0)   //������ʱ��Ϊ0���������� 
	{                       
	    p->status = 'E';  //�޸Ľ���״̬                      
		printf("���� %s �ѽ���\n\n",p->name);                                                               
		show(head);       //��ʾ������Ϣ 
		printf("**********************************************************");                                                             
		printf("\n\n�밴�س���������һ����\n\n");                                   
		getchar();     //���ջس��� 
		head = p->next;                      
		free(p);    //�ͷ�p                     		            
	} 
}

int main()
{        
    struct PCB *p = NULL;  //pΪ�����ж���PCBָ��              
	line(p);     	//������������               
	sort(head);          //�����������ݼ���������        
	show(head);  //��ʾ������Ϣ 
	printf("**********************************************************");	       
	printf("\n");                  
	while(head != NULL)   //�������л���PCB��ִ��ѭ�����
	{               
	    p = head;  //pָ���һ������  		              
		run(p);   //���е��� 
		check(p); 
		sort(head);
		show(head);
		printf("**********************************************************");	            	       
	} 
}
