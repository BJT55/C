#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 5

void printfsort(int *s,int n);  //���
void bubblesort(int *s,int n);  //ð������ 
void quicksort(int *s,int left,int right);  //�������� 
void selectsort(int *s,int n);  //ѡ������
void insertsort(int *s,int n);  //�������� 
void shellsort(int *s,int n);  //ϣ������ 
void mergesort(int *s,int left,int right);
void merge(int *s,int left,int mid,int right);  //�鲢����
int max(int *s, int n);
void radixsort(int *s, int n);  //������ 


int main()
{
	int choose,N=size;
	int a[N];
	do
	{

        printf("\n\n************************�����㷨****************************\n");
	    printf("                        1.ð������\n");
	    printf("                        2.��������\n");
	    printf("                        3.ѡ������\n");
	    printf("                        4.��������\n");
	    printf("                        5.ϣ������\n");
		printf("                        6.�鲢����\n");
		printf("                        7.������\n");	
		printf("                        8.Ͱ����\n");
	    printf("                        0.�˳�ϵͳ\n");
	    printf("\n��������Ҫ�����%d������\n",N); 
	    for(int i=0;i<N;i++)     //������Ҫ����������� 
	    {
		    scanf("%d",&a[i]);
	    } 
	    printf("\n��������ѡ������򷽷�:");
        scanf("%d", &choose);
        switch(choose)
	    {
	        case 1:
			    bubblesort(a,N);
				printfsort(a,N); 
                break;
            case 2:
			    quicksort(a,0,N-1);
			    printfsort(a,N); 
                break;
            case 3:
            	selectsort(a,N);
            	printfsort(a,N);
            	break;
            case 4:
            	insertsort(a,N);
            	printfsort(a,N);
            	break;
            case 5:
            	shellsort(a,N);
            	printfsort(a,N);
            	break;
            case 6:
            	mergesort(a,0,N-1);
            	printfsort(a,N);
            	break;
            case 7:
            	radixsort(a,N);
            	printfsort(a,N);
            	break;
            case 0:
                break;
	    }	    
    }while(choose!=0);
}

void bubblesort(int *s,int n)  //ð������ 
{
	int i,j,temp;
	for(i=0;i<n;i++)   //���������ֵ�³���С��ֵ�ϸ� 
	{
		for(j=0;j<n;j++)
		{
			if(s[j]>s[j+1])
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}
}


void quicksort(int *s,int left,int right)   //�������� 
{
	int i,j,k,temp;
	if(left>right)
	{
		return ;
	}
	temp=s[left];
	i=left;
	j=right;
	while(i!=j)
	{
		while(s[j]>=temp&&i<j)  //���ҿ�ʼ�Ƚ� 
		{
			j--;
		}
		while(s[i]<=temp&&i<j)   //����ʼ�Ƚ� 
		{
			i++;
		}
		if(i<j)   //�����ֵ�����ұ���ֵ������ 
		{
			k=s[i];
			s[i]=s[j];
			s[j]=k;
		}
	}
	s[left]=s[i];
	s[i]=temp;
	quicksort(s,left,i-1);
	quicksort(s,i+1,right);
}


void selectsort(int *s,int n)   //ѡ������ 
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(s[i]>s[j])
			{
				temp=s[j];
				s[j]=s[i];
				s[i]=temp;
			}
		}
	}
}


void insertsort(int *s,int n)  //��������
{
	int i,j,temp=s[0];
	for(i=1;i<n;i++)
	{
		temp=s[i];
		j=i-1;
		while(j>=0&&temp<s[j])
		{
			s[j+1]=s[j];
			j--;
		}
		s[j+1]=temp;
	}
 } 

 
void shellsort(int *s,int n)   //ϣ������ 
{
	int t=size,temp,i,j,k;
	while(t!=1)
	{
		t=t/2;
		for(i=0;i<size;i++)
		{
			for(j=i+t;j<size;j++)
			{
				if(s[j]<s[i])
			    {
				temp=s[j];
				s[j]=s[i];
				s[i]=temp;
			    } 
			}
			
		}
	}
}


void mergesort(int *s,int left,int right)  //�鲢���� 
{
	if(left<right)
	{
		int mid=(left+right)/2;
		mergesort(s,left,mid);
		mergesort(s,mid+1,right);
		merge(s,left,mid,right);
	}
}
void merge(int *s,int left,int mid,int right)
{
	int i=left,j=mid+1,t=left;
	int srr[size];
	while(i<=mid&&j<=right)
	{
		if(s[i]<s[j])
		{
			srr[t++]=s[i++];
		} 
		else srr[t++]=s[j++];
	}
	while(i<=mid)   
	{
		srr[t++]=s[i++];
	}
	while(j<=right)   
	{
		srr[t++]=s[j++];
	}
	for(int k=left;k<=right;k++)
	{
		s[k]=srr[k];
	}  
}


int max(int *s, int n) 
{
    int x=1; //��������λ��
    int y=10;
    for(int i=0;i<n;i++)
    {
        while(s[i]>=y)
        {
            y*=10;
            x++;
        }
    }
    return x;
}
void radixsort(int *s, int n) //��������
{
    int x=max(s,n);
    int temp[n];
    int count[10]; //������
    int i,j,k;
    int radix = 1;
    for(i =1;i<=x; i++) //����x������
    {
        for(j=0;j<10;j++)
            count[j]=0; //ÿ�η���ǰ��ռ�����
        for(j=0;j<n;j++)
        {
            k = (s[j]/radix)%10; //ͳ��ÿ��Ͱ�еļ�¼��
            count[k]++;
        }
        for(j=1;j<10;j++)
            count[j]=count[j-1]+count[j]; //��tmp�е�λ�����η����ÿ��Ͱ
        for(j=n-1;j>=0;j--) //������Ͱ�м�¼�����ռ���tmp��
        {
            k = (s[j]/radix)%10;
            temp[count[k]-1]=s[j];
            count[k]--;
        }
        for(j=0;j<n;j++) //����ʱ��������ݸ��Ƶ�data��
            s[j]=temp[j];
        radix=radix*10;
    }
} 


void printfsort(int *s,int n)   //��ӡ��� 
{
	int k; 
	for(k=0;k<size;k++)
	{
		printf("%d  ",s[k]);
	}     
}
