#include<stdio.h>
#include<stdlib.h>
#define MAX 200000

void shellSort(int array[], int n);
void printArr(int* arr,int length);

int main()
{
	int i,a[MAX],n;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	shellSort(a, n);
	printArr(a,n);
	return 0;
} 
void printArr(int* arr,int length)
{
    int i;
	for(i=0;i<length;i++)
	{
        printf("%d ",arr[i]);
    }
}
void shellSort(int array[], int n)
{
    //�����м��������Ϊ��ʱ��������
    int temp;
    //�������飨��������
    //�����ʼ����ֵ
    int gap = n;
    do
	{        //��ʼ�����仯����
        gap = gap / 3 + 1;
        for (int i = gap; i < n; i++)
        {
            for (int j = i; j >= gap; j-=gap)
            {
               if (array[j] < array[j - gap])
               {
                   temp = array[j];
                   array[j] = array[j - gap];
                   array[j - gap] = temp;
               }
               else
               {
                   break;
               }
           }
       }
   } while (gap>1);
}
