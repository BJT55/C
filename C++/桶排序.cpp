#include<stdio.h>
#include<stdlib.h>
#define MAX 500000
//Ͱ����
void bucketsort(int* s, int n)
{
    int i,j,max_num=s[0];
    int* bucket;
    //������������ֵ
    for(i=1;i<n;i++)
	{
        if(s[i]>max_num)
		{
            max_num=s[i];
        }       
    }
    max_num++;  //���ֵ��1
    if(s==NULL || n<=1)
	{
        return;
    }
    if((bucket = (int*)malloc(sizeof(int)*max_num))==NULL){return;}
    for(i=0;i<max_num;i++)
	{
        bucket[i]=0;   //��Ͱ�����ʼ��
    }
    for(i=0;i<n;i++)
	{ // Ѱ�����У���Ԫ��һ��һ�������Ӧ��Ͱ��
        bucket[s[i]]+=1;   
    }
    for(i=0,j=0;i<max_num;i++)
	{
        while((bucket[i])>0)
		{  //��ÿ�����ǿյ�Ͱ�ӽ�������
            s[j]=i;   //�Ӳ��ǿյ�Ͱ�������Ŀ�ٷŻ�ԭ����������
            j++;
            bucket[i]--;
        }
    }
    free(bucket);
    bucket = NULL;
}
int main()
{
	int N,a[MAX];
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	bucketsort(a,N);
	for(int j=0;j<N;j++)
	{
		printf("%d ",a[j]);
	}
}
