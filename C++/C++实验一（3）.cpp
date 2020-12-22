//M��ͬѧN�ſγɼ�������ѧ���ɼ��������룬���ң���������ȹ��� 

#include <iostream>
#include <string.h>
using namespace std;

const int M=3;  //���� 
const int N=3;  //���� 
char name[M][20];
int score[M][N];

void menu()
{
	cout<<"*********ѧ����Ϣ����ϵͳ*********"<<endl; 
	cout<<"      1.����          2.����      "<<endl; 
	cout<<"      3.����          4.���      "<<endl; 
	cout<<"      5.�˳�   "<<endl; 
	cout<<"**********************************"<<endl;
} 

class Student
{
public:
	void Input();      //����
	void Output();     //���
	void Search();     //����
	void Sort();		 //����
public:
	char name[M][20];
	int score[M][N];
};
 
void Student::Input()
{
	for (int i = 0; i < M;	i++) {
		cout << "����ѧ������" << endl;
		cin>>name[i];
		cout << "��ֱ�����" <<N<<"�ſγ̵ĳɼ�" << endl;
		for (int j = 0; j < N; j++)
		{
			cin >> score[i][j];
		}
	}	
}
 
 
void Student::Search()     
{
	int flag=1;
	char Find_name[20] = {0};
	cout << "������Ҫ��ѯ��ѧ��������" << endl;
	cin >> Find_name;
	for (int i = 0; i < M; i++)
	{ 
		if (strcmp(Find_name, name[i]) == 0)     
		{
			cout << "��ѯ�ɹ���" << endl;
			flag=0;
			cout << "����"<<"  "<<"����" << "  " << "Ӣ��" << "  " << "�����" << endl;
			for (int j = 0; j < N; j++)
			{
				if (j == 0)
				{
					cout << name[i] <<"    "<<score[i][j]<< "    ";
				}
				else {
					cout << score[i][j] << "    ";
				}
			}
			cout <<"\n"<< endl;
			break;
		}
	}
	if(flag)     cout << "��ѯʧ��........\n"<< endl;
}

void Student::Sort()
{
	int num,temp,choose;
	cout<<"��������Ҫ����ɼ��Ŀ�Ŀ��1.����    2.Ӣ��     3.�����     "<<endl;
	cin>>num;
	choose=num-1;
	for(int i=0;i<N ;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			if(score[i][choose]<score[j][choose])
			{
				temp=score[i][choose];
				score[i][choose]=score[j][choose];
				score[j][choose]=temp;
			}
		}
	}
	cout<<"�ɼ�������Ϊ:"<<endl;
	for(int j=0;j<M;j++)
	{
		cout<<name[j]<<"--"<<score[j][choose]<<"   ";
	} 
	cout<<"\n"<<endl;
}

void Student::Output()
{
	for (int i = 0; i < M;	i++)
	{
		cout << "����"<<"  "<<"����"<<"  "<<"Ӣ��"<<"  "<<"�����"<<"  "<< endl;
		cout<<name[i]<<"    ";
		for (int j = 0; j < N; j++)
		{
			cout<<score[i][j]<<"    ";
		}
		cout<<"\n"<<endl;
	}
}


int main()
{
	int choose=1;
	Student stu;
	while(choose)
	{	
		menu();
		cout<<endl;
		cout<<"������˵�ѡ�"<<endl;
		cin>>choose;
		switch(choose)
		{
			case 1:
				stu.Input();
				break;
			case 2:
				stu.Search();
				break;
			case 3:
				stu.Sort();	
				break;
			case 4:
				stu.Output();
				break;	
			case 5:
				cout<<"�˳��ɹ�..........\n"<<endl; 
				choose=0;
				break;
			default:
				cout<<"�˵�ѡ������������ѡ��.......\n"<<endl;		
		} 
	}
}
