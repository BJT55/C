#include <iostream>
using namespace std;
class Circle{

	private:
		float r;
	public:
		Circle():PI(3.1415927){
			r=0;
	}
	void aisle(float r)
	{
		float aisle;
		cout.precision(2);
		aisle=( PI*(r+3)*(r+3)-PI*r*r )*20;
		cout<<"�������:"<<fixed<<aisle<<"Ԫ"<<endl;
	}
	void fence(float r)
	{
		float fence;
		cout.precision(2);
		fence=PI*2*(r+3)*35;
		cout<<"դ�����:"<<fixed<<fence<<"Ԫ"<<endl;
	}
	const double PI;
};
int main()
{
	float r;
	cout<<"����뾶r��"<<endl;
	cin>>r;
	Circle circle;
	circle.aisle(r);
	circle.fence(r);
} 
