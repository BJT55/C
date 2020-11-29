#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define false 0   //û���㹻��Դ���������
#define true 1   //���㹻��Դ���������
#define A 10
#define B 50

void put();   //��ӡ��Դ��Ϣ 
void bank();   //���м��㷨
void distribute(int k);   //������Դ 
void restore(int k);   //�ָ�������Դ
int release(int k);   //�ͷ���Դ
int safecheck() ;  //��ȫ�Լ��

int i=0,j=0;
int f=0;  //�Ƿ�ִ����ϱ�־ 
int m;  //�ܽ�����
int n;   //��Դ����
int resource[B];    //������Դ����Ŀ�ܺ�
int maxrequest[A][B];   //�����̶Ը�����Դ�����Դ������
int available[B];    //ϵͳ������Դ��
int allocation[A][B];   //�������ѷ��������Դ����Դ��Ŀ 
int need[A][B];    //�����̻���Ҫ������Դ����Դ��Ŀ 
int request[B];   //������Դ��Ŀ

//��ӡ��Դ��Ϣ
void put()    
{
    cout<<endl<<"-------------------------------------------"<<endl;
    cout<<"��ʼʱ������Դ��������:"<<endl;
	for (j=0;j<n;j++)
	    cout<<" ��Դ"<<j<<": "<<resource[j];
		cout<<endl;
		cout<<"-------------------------------------------"<<endl;
		cout<<"Ŀǰ������Դ�����õ�����Ϊ:"<<endl;
    for (j=0;j<n;j++)
	    cout<<" ��Դ"<<j<<": "<<available[j];
        cout<<endl;
        cout<<"-------------------------------------------"<<endl;
        cout<<"�����̻���Ҫ����Դ����:"<<endl<<endl;
    for(i=0;i<n;i++)    
	    cout<<"        ��Դ"<<i;cout<<endl;
    for (i=0;i<m;i++)
	{
	    cout<<"����"<<i<<":   ";
        for (j=0;j<n;j++)
		    cout<<need[i][j]<<"         ";
        cout<<endl;
	}
	cout<<endl;
	cout<<"-------------------------------------------"<<endl;
    cout<<"�������Ѿ��õ�����Դ��: "<<endl<<endl;
    for(i=0;i<n;i++)
	    cout<<"        ��Դ"<<i;cout<<endl;
    for (i=0;i<m;i++)
	{
	    cout<<"����"<<i<<":    ";
        for (j=0;j<n;j++)
		    cout<<allocation[i][j]<<"         ";
        cout<<endl;
	}
	cout<<endl;
}

//���м��㷨
void bank()   
{
    int flag=1;
    while(flag==1)
    {
        i=-1;
        while(i<0||i>=m)
        {
            cout<<"-------------------------------------------"<<endl;
            cout<<endl<<" ������������Դ�Ľ��̺�:";
            cin>>i;
            if(i<0||i>=m)      
			    cout<<" ����Ľ��̺Ų����ڣ���������"<<endl;
        }
        cout<<" ���������"<<i<<"���������Դ������:"<<endl;
        for (j=0;j<n;j++)
        {
		    cout<<" ��Դ"<<j<<": ";
			cin>>request[j];
            if(request[j]>need[i][j])    //�������Դ�����ڽ�����Ҫi����Դ����Դ��j
            {
                cout<<endl<<" ����"<<i<<"�������Դ�����ڽ���"<<i<<"����Ҫ"<<j<<"����Դ������!";
                cout<<" ��ϵͳ�����ڲ���ȫ״̬!"<<endl;
            flag=0;
            break;
            }
            else
            {
                if(request[j]>available[j])    //�������Դ�����ڿ�����Դ��
                    {
                        cout<<endl<<" ����"<<i<<"�������Դ������ϵͳ����"<<j<<"����Դ������!";
                        cout<<" ��ϵͳ�����ڲ���ȫ״̬!"<<endl;flag='n';
						break;
                    }
            }
        }
        if(flag==1)
        {
            distribute(i);   //������Դ
			release(i);
            if( safecheck()==0 )    //ϵͳ����ȫ 
            {
                restore(i);   //�ָ���Դ��
                put();   // �����Դ�������
            }
            else       //ϵͳ��ȫ
                put(); // �����Դ�������
        }
        else      
            cout<<endl;
            cout<<" �Ƿ�������м��㷨��ʾ,��1����,��0�˳���ʾ: ";
        cin>>flag;
    }
}

//������Դ 
void distribute(int k)    
{
    for (j=0;j<n;j++)
    {
        available[j]=available[j]-request[j];
        allocation[k][j]=allocation[k][j]+request[j];
        need[k][j]=need[k][j]-request[j];
    }
}

//�ָ�������Դ
void restore(int k)    
{
    for (j=0;j<n;j++)
    {
        available[j]=available[j]+request[j];
        allocation[k][j]=allocation[k][j]-request[j];
        need[k][j]=need[k][j]+request[j];
    }
}

//ִ����Ϻ��ͷ���Դ 
int release(int k)
{
	for(j=0;j<n;j++)
	{
		if(need[k][j]==0)
		{
			available[j]=available[j]+maxrequest[k][j];
		}
	} 
} 

//��ȫ�Լ�� 
int safecheck()   //����ȫ����0����ȫ����1 
{
    int work[B],finish[A];   //�������� 
    for(j=0;j<n;j++) 
        work[j]=available[j];     //��ʼ�� 
    for(i=0;i<m;i++) 
        finish[i]=false;    //��ʼ�� 
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if( finish[i]==false && need[i][j]<=work[j] )    
            {
                work[j]=work[j]+allocation[i][j];    
            }
        }
        finish[i]=true;    
    }
    for(i=0;i<m;i++)
    {
        if(finish[i]==false)
        {
            cout<<endl;cout<<" ϵͳ����ȫ!   ����ʧ��!  "<<endl;
            cout<<endl;
			return 0;
        }
        else
		{
		    cout<<endl;
            cout<<" ϵͳ��ȫ��   ����ɹ���"<<endl;
			cout<<endl;
			
			return 1;
        }
    }
}


int main() //������
{
    int p;
    cout<<endl;
    cout<<"\t****************************************************"<<endl;
    cout<<"\t                    �� �� �� �� ��                   "<<endl;
    cout<<"\t****************************************************"<<endl;
    cout<<endl<<"�������ܽ�����:";
    cin>>m;
    cout<<endl<<"-------------------------------------------"<<endl;
    cout<<"����������Դ����:";
    cin>>n;
    cout<<endl<<"-------------------------------------------"<<endl;
    cout<<"�����������Դ����:";
    for(i=0;i<n;i++)
        cin>>resource[i];
        cout<<endl<<"-------------------------------------------"<<endl;
        cout<<"�������������Ҫ�ĸ�����Դ���������:("<<m<<" * "<<n<<"����)\n";
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            do
            {
			    cin>>maxrequest[i][j];
                if (maxrequest[i][j]>resource[j])
				    cout<<endl<<"�ѷ�����Դ�����˸���Դ����,����������"<<endl;
            }while (maxrequest[i][j]>resource[j]);
        }
    }
    cout<<endl<<"-------------------------------------------"<<endl;
    cout<<"����������ѷ��������Դ������:("<<m<<" * "<<n<<"����)\n";
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            do
            {
			    cin>>allocation[i][j];
                if (allocation[i][j]>maxrequest[i][j])
				    cout<<endl<<"�ѷ�����Դ�����������Դ,����������"<<endl;
            }while (allocation[i][j]>maxrequest[i][j]);
        }
    }
    for (j=0;j<n;j++)   //��ʼ����Դ����
    {
        p=resource[j];
        for (i=0;i<m;i++)
        {
            p=p-allocation[i][j];  //��ȥ�Ѿ���ռ�ݵ���Դ
            available[j]=p;
            if(available[j]<0)
                available[j]=0;
        }
    }
    for (i=0;i<m;i++)
        for(j=0;j<n;j++)
            need[i][j]=maxrequest[i][j]-allocation[i][j];   //������Դ��Ϊ���������Դ����ȥ�ѷ�����Դ�� 
    put();    //��� 
    bank();    //���м��㷨 
}

