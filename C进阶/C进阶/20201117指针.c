#include <stdio.h>




/*
int main()
{
	int a[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int *p1 = (int *)(&a + 1);    //ָ��a��������ĺ�һλ���յģ�
	int *p2 = (int *)(*(a + 1));    //ָ��ڶ���a[1]�ĵ�һλ��6��
	printf("%d,%d", *(p1 - 1), *(p2 - 1));    //p1-1ָ���������һλ��p2-1ָ��6��ǰһλ����a[0][4]
	system("pause");
}
*/

/*     ָ��ÿ��4��Ԫ�أ�����ÿ��5��Ԫ��
void main()
{
	int a[5][5];
	int(*p)[4];
	p = a;
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
	system("pause");
}
*/

/*
int a[]={1,2,3,4};

sizeof(a)     16;
sizeof(a+0)    4;   //��ַ��ָ��
sizeof(*a)     4;
sizeof(a+1)    4;
sizeof(a[1])   4;
sizeof(*&a)   16;  
sizeof(&a+1)   4;
sizeof(&a[0])  4;

*/

/*
//void a;   ������ʹ�ò�����������   
// void *z;   ����ָ��
*/

/*
int Find_Max(int ar[], int n)
{
	int Max_Value = ar[0];
	for (int i = 1; i < n; i++)
	{
		if (Max_Value <ar[i])
		{
			Max_Value = ar[i];
		}
	}
	return Max_Value;
}
int Find(int ar[], int n, int(*pfun)(int ar[], int n))
{
	return pfun(ar, n);
}
void main()
{
	int ar[] = {1,34,54,12,77,67,45,89,23};
	int len = sizeof(ar) / sizeof(ar[0]);
	printf("%d \n", Find(ar,len,Find_Max));
}
*/