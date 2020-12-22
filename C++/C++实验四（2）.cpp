#include <iostream>
#define PI 3.1416
using namespace std;

//�������Բ���������������
class Circle
{
	protected:
		double radius;
	public:
		virtual double area()=0;
		virtual double volume()=0;
};
//���� 
class Sphere:public Circle
{
	public:
		Sphere(double r=0){radius=r;}
		virtual double area()
		{
			return 4.0*PI*radius*radius;
		}
		virtual double volume()
		{
			return (4.0/3.0)*PI*radius*radius*radius; 
		}
};
//Բ���� 
class Column:public Circle
{
	private:
		double height;
	public:
		Column(double r=0,double h=0){radius=r;height=h;}
		virtual double area()
		{
			return 2*PI*radius*radius+2*PI*radius*height;
		}
		virtual double volume()
		{
			return PI*radius*radius*height; 
		}
};

int main()
{
	double rs,rc,h;
	cout<<"����������İ뾶��"<<endl;
	cin>>rs;
	cout<<"������Բ����İ뾶��"<<endl;
	cin>>rc;
	cout<<"������Բ����ĸߣ�"<<endl;
	cin>>h;
	if(rs<=0||rc<=0||h<=0)   cout<<"����������������������...."<<endl;
	Sphere sphere(rs);
	Column column(rc,h);
	cout<<"\n���壺"<<endl;
	cout<<"���Ϊ��"<<sphere.area()<<"   ���Ϊ��"<<sphere.volume()<<endl;
	cout<<"\nԲ���壺"<<endl;
	cout<<"���Ϊ��"<<column.area()<<"   ���Ϊ��"<<column.volume()<<endl;
}
