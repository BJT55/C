#include<stdio.h> 
#include<stdlib.h>
#include<time.h> 

//���������15�� 
void random(int *a)
{ 	
	int i,number=0;
	srand((unsigned) time(NULL));    //ÿ�����в�����ͬ������� 
	for (i=0; i<15; i++)     //ȡ15�����������������a�� 
	{	
		number=rand()%201;        //����1-200������� 
		a[i]=number;      //��������������� 
	} 
} 

//��ӡ����
void Print(int *a)    
{
	for(int i=0;i<15;i++)  //��ӡÿһ������Ľ�� 
	{
		printf("%d ",a[i]);
    } 
	printf("\n\n");

}

//ð������
void Sort(int *a) 
{	
	int i,j;
	int key;
	int temp;
	for(i=0;a[i]!='\0';i++)  
	{
		key=0;
		for( j=0; j+1<15-i; j++ )
		{
			if( a[j]>a[j+1] )
			{
				key=1;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		if(key==0)  
		    break;
    }
}

//���� 
void run(int *a)
{	
	int	i,j,k;
	int count=1;   //���� 
    int start;    //��ʼ�ŵ� 
	int avl=0;   //ƽ��Ѱ������ 
	for(i=0;i<15;i++)
	{
		if(a[i]>=100)
		{
			start=i;  
		    break;
		}
	}
	avl=a[start]-100;
    for(j=start;j<15;j++)       //����100 
    {
    	printf("%2d:%5d����\n",count, a[j] );
    	count++;
    	if(j+1<15)
    	avl=avl+a[j+1]-a[j];
	}
	avl=avl+a[14]-a[start-1];
	for(k=start-1;k>=0;k--)     //С��100 
	{
		printf("%2d:%5d����\n",count, a[k]);
		count++;
		if(k-1>=0)
		avl=avl+a[k]-a[k-1];
	}
	avl/=15;
	printf("\n\nƽ��Ѱ������:%d",avl); 
}

//������ 
int main()
{		
	int a[15]={0};
	random(a);    //����� 
	printf("********************���̵���********************\n\n");
	printf("��ͷ��100�Ŵŵ��ϣ�����ŵ������ӵķ������ƶ�\n\n"); 
	printf("********************���̵���********************\n");
	printf("\n15������ŵ���������:\n");
	Sort(a);   //��С�������� 
	Print(a);    // ��ӡ�źõ������ 
	run(a);	  //���� 
	return 0;
}

