#include <iostream>
#include <string>
using namespace std;
 
class Building
{
	protected:
		string address;
		int number;	
	public:
		Building(string add,int n)
		{
			address=add;
			number=n;
		}
};

class House:public Building
{
	public:
		House(string add,int n,int hnum,float are):Building(add,n),house_number(hnum),house_are(are)
		{
			house_number=hnum;
			house_are=are;
		}
		void init_House()
		{
			cout<<"סլ��ַ:"<<address<<endl;
			cout<<"סլ¥��:"<<number<<endl;
			cout<<"סլ����:"<<house_number<<endl;
			cout<<"סլ���(ƽ����):"<<house_are<<endl;			
		}
	private:
		int house_number;
		float house_are;
};

class Office:public Building
{
	public:
		Office(string add,int n,string oname,string phone):Building(add,n),office_name(oname),office_phone(phone)
		{
			office_name=oname;
			office_phone=phone;
		}
		void init_Office()
		{
			cout<<"�칫�ҵ�ַ:"<<address<<endl;
			cout<<"�칫��¥��:"<<number<<endl;
			cout<<"�칫������:"<<office_name<<endl;
			cout<<"�칫�ҵ绰����:"<<office_phone<<endl;	
		}
	private:
		string office_name;
		string office_phone;
};

int main()
{
	House house("�Ҹ�·1944��",21,3,170.3);
	house.init_House();
	Office office("����·1466��",22,"�з���","6500927");
	office.init_Office();
}
