#include <iostream>
using namespace std;
#include <cstdio>
#include <cmath>
#define COUNT 512

void put();  //��������
void init();  //��ʼ��
void insert(int n,float st,float si);   //���� 
void dele(int n);   //ɾ�� 
void move(int n);  //�ƶ�����
void show();   //��ӡ��� 
int apply();  //������ͷ����� 
void merge(int n,float st,float si);  //�ϲ������� 

int count;     //���ֳɵĿ���ͳ��
int applyfree;   //������ͷ����� 
float numb;    //���̴�С 
char c;    //������ 

int main()
{
    init();   //��ʼ�� 
    show();   //��ӡ 
    while(1)
    {
        put();   //�������� 
        apply();   //�����ͷ����� 
        show();   //��ӡ���� 
    }
    return 0;
}

//����ṹ�� 
typedef struct DATA
{
    char name;         //����
    float start;       //��ʼλ��
    float size;        //��С
    int flag;          //�ж��Ƿ���䣨1Ϊδ���䣬0Ϊ�ѷ��䣩 
}DATA ;
DATA a[COUNT];    //����

//��������
void put() 
{
    printf("��������������ͷŵĽ������Ƽ���Դ������\n");
    rewind(stdin);
    printf("�������������"); 
    scanf("%c",&c);
    printf("��ѡ�����루����1��/ �ͷţ�����0����"); 
    scanf("%d",&applyfree);
    printf("��������̴�С��");
    scanf("%f",&numb);
    
}

//��ʼ��
void init()
{
    count=1;
    a[0].name='?';      //δ����ʱ������Ϊ�� 
    a[0].start=0;       //��ʼ��ַΪ0 
    a[0].size=COUNT;      
    a[0].flag=1;       // ��ʼ����1 ����ʾδ����
} 

//����
void insert(int n,float st,float si)    // ��ʶ����ʼ��ַ����С 
{
    int i;
    count++;     //�²��룬����+1 
    for(i=count;i>n+1;i--)
    {
        a[i]=a[i-1];
    }
    a[n].start=st;
    a[n].size=si;
}

//ɾ��
void dele(int n)
{
    int i;
    for(i=n;i<count-1;i++)   //ɾ���Ŀ��С���ܿ��� 
    {
        a[i]=a[i+1];
    }
    count--;
}

//�ƶ����� 
void move(int n)
{
	int i;
	for(i=count;i>n+1;i--)
	{
		a[i]=a[i-1];
	}
}

//�ϲ������� 
void merge(int n,float st,float si)
{
    if( a[n-1].flag )   //ǰһ��δ���� 
    {
        a[n-1].size=a[n-1].size+si;
        dele(n);    //ɾ��a[n] 
    }
    if( a[n+1].flag )   //��һ��δ���� 
    {
        a[n].size=a[n].size+a[n+1].size;
        a[n].name='?';
        a[n].flag=1;
        dele(n+1);    //ɾ��a[n+1] 
    }
    if( !a[n-1].flag && !a[n+1].flag )    //ǰ���ѷ��� 
    {
        a[n].name='?';
        a[n].flag=1;
    }
}


//��ӡ���
void show()
{
    int i,j=0;
    printf("����   ��ʶ   ��ַ   ����   ״̬\n");
    for(i=0;i<count;i++)
    {
    	if(a[i].name==a[i+1].name)  
		    continue;    //�ظ�������ȥ 
        if( a[i].flag && a[i].size!=0 )   //���δ���� 
            printf("?      ");
        else
            printf("%c      ",a[i].name);
        printf("%d%8.0f%8.0f    ",j,a[i].start ,a[i].size);        
        if( a[i].flag )
            printf("δ����\n");
        else
        {
            if( a[i].size!=0 )
            {
        	    printf("�ѷ���\n");
		    } 
			else  printf("\n"); 
		}
		j++;
    }
}

//  ������ͷ� 
int apply()   
{
    int i=0;
    int aflag=0;
    int fflag=0;
    if(applyfree)           //������Դ������1�� 
    {
        while( !aflag && i<count )
        {
            if( a[i].size>=numb && a[i].flag )   //�������ҵ�������ҵ��Ҫ��С�ڵ��ڿ�������������װ�� 
            {
                if( a[i].size==numb )
                {
                    a[i].name =c;
                    a[i].flag =0;
                }
                else
                {
                	count++;
                    move(i);
                    insert( i+1, a[i].start+numb, a[i].size-numb );
                    a[i+1].flag=1;     //δ���� 
                    a[i+1].name='?';
                    a[i].name=c;
                    a[i].size=numb;
                    a[i].flag=0;      //�ѷ��� 
                }
                aflag=1;   //������ϣ�aflag=1�������� 
            }
            i++;
        }
        if(aflag)
        {
            printf("\n����ɹ���\n");
            return 1;
        }
        else
        {
            printf("\n����ʧ�ܣ�û���㹻��Ŀ��пռ䡣\n");
            return 0;
        }
    }
    else     //�ͷ���Դ������0�� 
    {
        while( !fflag && i<count )
        {
            if( a[i].name==c )
            {
                if( a[i].size==numb )
                {
                merge( i, a[i].start, a[i].size );
                }
                else
                {
                    if( a[i].size>numb ) 
                    {
                    	count++;
                        move(i);
                        insert( i+1, a[i].start+numb, a[i].size -numb );
                        a[i+1].name=c;
                        a[i+1].flag=0;     //�ѷ��� 
                        a[i].size=numb;
                        a[i].name='?';
                        a[i].flag=1;      //δ���� 
                        if( a[i-1].flag )   //���ͷŵ������ǰһ��Ϊ������ 
                        {
                            merge(i,a[i].start ,a[i].size );   //�ϲ������� 
                        }
                    }
                    else
                    {
                        printf("\n�ͷ�ʧ�ܣ�ʹ�õ�����С��Ҫ���ͷŵ�������\n");
                        return 0;
                    }
                }
                fflag=1;
            }
            i++;
        }
        if( fflag )
        {
            printf("\n�ͷųɹ���\n");
            return 1;
        }
        else
        {
            printf("\n�ͷ�ʧ�ܣ�δ�ҵ�ƥ��Ľ������ơ�\n");
            return 0;
        }
    }
}


