#include <stdio.h>

//�ṹ���ڴ����
//   #pragma pack(2)  ����2�ֽڶ���   ---��һ������ָ���ֽ�
/*
typedef struct Text
{
	char a;   //1
	double b;   //8
	int c;    //4
}Text;
// ����b��c��λ�õ������������ֵΪ16

void main()
{
	printf("%d\n",sizeof(Text));   //24
}
*/

//�������Ĳ���
/*
typedef struct Text
{
	short a;    // 2 + ����6��
	struct
	{
		int b;
		double c;    // structΪ24
		char d;
	};
	int e;   // 4 +(�� 4��
}Text;

void main()
{
	printf("%d\n", sizeof(Text));    //���Ϊ40
}
*/


/*
typedef struct Text
{
	short a;    // 2 + ����6��
	struct
	{
		int b;    // 4 +(��4)
		double c[10];    // 80
		char d;    // 1 +(��7)
	};
	int e;   // 4 +(�� 4��
}Text;

void main()   //  8+96+8=112
{
	printf("%d\n", sizeof(Text));    //���Ϊ112
}

*/

/*
#pragma pack(2)
typedef struct Text
{
	short a;    // 2 
	struct
	{
		int b;   //  4
		double c;    // 8
		char d;   // 1+(��1)
	};
	int e;   // 4 
}Text;

void main()
{
	printf("%d\n", sizeof(Text));    //���Ϊ20
}
*/

/*
typedef struct Text
{
	short a;    // 2 + ����6��
	struct t  //��������t����Ϊ���ͣ���ռ�ڴ棬cpp��ʽ��Ϊ8��c��ʽ���¶���struct�൱�ڲ�����
	{
		double c;   // 8
		int b;   // 4 
		char d;  // 1 +( 3 )
	};
	int e;   // 4 +(�� 4��
}Text;

void main()
{
	printf("%d\n", sizeof(Text));    //���Ϊ32
}
*/

//��Ϊ������1��
/*
#pragma pack(4)
unsigned short *pCharArr[10][10];
typedef struct unRec
{
	unsigned long a;   // 4
	unsigned short b[7];   // 2 * 7
	unsigned char c;   // 1 + ( 1 )
}Rec_c;
Rec_c stMax, *pstMax;

void main()
{
	printf("%d\n", sizeof(pCharArr));    //  4 * 10 * 10
	printf("%d\n", sizeof(stMax));   //  20
	printf("%d\n", sizeof(pstMax));  //  4
	printf("%d\n", sizeof(*pstMax));   //20
}
*/

/*
//λ�򣨽�ʡ�ռ䣩
typedef struct text
{
	char a : 1;   // 0 1 ����ֵ   
	char n : 1;
	char c : 1;
}text;
void main()
{
	printf("%d\n", sizeof(text));
}
//���ٿռ���С��λ�����ֽڣ��� ��1 ������ռ��1λ����bitλ�Ƕȣ�
//1.λ���ܿ��ֽڴ洢
//2.λ���ܿ����ʹ洢
*/
/*
typedef struct text
{
	char a : 1;    // λ���ܿ����ʹ洢
	int b : 1;
}text;
void main()
{
	printf("%d\n", sizeof(text));   //  8
}
*/

//λ��

/*
struct S
{
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
};
void main()
{
	struct S s = { 0 };
	s.a = 10;
	s.b = 12;
	s.c = 3;
	s.d = 4;
}
*/

/*
//ö��
enum Color
{
	red,   //ö���á� �� ���ָ�
	green,
	blue
};
void main()
{				// Ĭ�ϴ��㿪ʼ�����μ�1,ֻ��������
	printf("%d %d %d\n", red, green, blue);   //����� 0 1 2  //���и�ֵ����ֵ�����μ�1
	printf("size = %d \n", sizeof(enum Color));    //  4  (ÿ��ֻ�ܴ���һ����
}                                            

*/


//���ϣ������壩
/*
union Un
{
	char c;
	int i;
};
void main()
{
	union Un un;
	printf("%d\n", sizeof(un));   //  4 (����Ա�Ĵ�С��
}

*/

//�жϴ�С��
/*
union Un
{
	int a;
	char c;
};
void main()
{
	union Un un;
	un.a = 1;
	if (un.c == 1)
	{
		printf("little\n");
	}
	else printf("big\n");
}
*/

//����������ֽڶ���
/*
union Un1  // 5+(3)
{
	char c[5];   // 5
	int i;   //4
};
union Un2    // 14 + (2)
{
	short c[7];  //  14
	int i;       //  4
};
*/



