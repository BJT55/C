#include <stdio.h>
//��̨��  
//һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж����������� 
int jumpFloor(int number ) 
{
	int count=0;
    while(number>2){
    	count=jumpFloor(number-1)+jumpFloor(number-2);
    	return count;
	}
	if ( number == 1 || number == 2)
	{
		return number;
	}
}
int main()
{
	int num;
    scanf("%d",&num);
    printf("%d",jumpFloor(num));
}
