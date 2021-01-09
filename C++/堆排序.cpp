
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
const int maxn=200000;
int a[maxn];
int N;
 
void swap(int& a,int& b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
 
/*�ӵ�i��Ԫ�ؿ�ʼ���µ�����Ԫ�ظ���ΪN*/
void down_adjust(int i,int N)
{
	while(i*2+1<N) //�����ӽ�� 
	{
		int child=i*2+1; 
		if(child+1<N&&a[child]>a[child+1]) //��֤child��ָ���ӽ���н�С�ĵ��Ǹ� 
		{
			child++;
		}
		if(a[i]>a[child]) 
		{
			swap(a[i],a[child]);	
		}
		else break; //���ڴӺ���ǰ����down_adjust���ӽ����ӽ��һ�����ӽ�㻹Ҫ�� 
		i=child;
	}
}
 
/*������*/
void heap_sort(int N)
{
	for(int i=N/2;i>=0;i--) //�ȶ�ÿ����Ҷ������һ�����µ�������֤ÿ��Ԫ�ض����������ӽ��С 
	down_adjust(i,N);
	for(int i=N;i>0;i--) //i��ʾԪ�ظ��� 
	{
		swap(a[0],a[i-1]); //��ʱa[0]һ������С��Ԫ�� 
		down_adjust(0,i-1);	//��С������Χ 
	}
	
} 
 
int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		for(int i=0;i<N;i++)
		{
			scanf("%d",&a[i]);
		}
		heap_sort(N);
		for(int i=N-1;i>=0;i--)
		{
			if(i!=0) printf("%d ",a[i]);
			else printf("%d\n",a[i]);
		}
	}
	return 0;
}
