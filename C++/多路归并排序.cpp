#include<stdio.h>
#define MAX 500000
void printfAnswer(int a[],int lenth){
    for(int i=0;i<lenth;i++)
    printf("%d  ",a[i]);
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
    printfAnswer(s,n);} 
 
int main()
{
    int N,a[MAX];
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
    }
    radixsort(a,N);
}

