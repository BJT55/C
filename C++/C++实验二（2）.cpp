#include <iostream>
#include <string> 
using namespace std;
class Student{
	private:
		string num[20];
		string name[20];
	public:
		int id_grade;
		int tm_grade;
		void InputStu();
		void OutputStu();		
};
void Student::InputStu(){
	cout<<"����������׼��֤�����������˳ɼ���"<<endl;
	for(int i=0;i<3;i++)
	{
		cout<<"��"<<i+1<<"λѧ��׼��֤�ţ�"<<endl;
		cin>>num[i];
		cout<<"��"<<i+1<<"λѧ��������"<<endl;
		cin>>name[i];
		cout<<"��"<<i+1<<"λѧ�����˳ɼ���"<<endl; 
		cin>>id_grade;
	}
	cout<<"�������Ŷӳɼ���"<<endl; 
	cin>>tm_grade; 
	cout<<"\n"<<endl;
}
void Student::OutputStu(){
	for(int i=0;i<3;i++){
		cout<<i+1<<"."<<"׼��֤�ţ�"<<num[i]<<"  "<<"������"<<name[i]<<"  "<<"���˳ɼ���"<<id_grade<<"  "<<endl; 
	}
	cout<<"�Ŷӳɼ���"<<tm_grade<<endl; 
}
int main(){
	Student stu;
	stu.InputStu();
	stu.OutputStu();
	return 0;
}
