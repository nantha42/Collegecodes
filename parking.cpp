#include <iostream>
using namespace std;
struct time{
	int h,m;
	
	struct time operator -(struct time b){
		struct time t;
		int k;
		k = b.h*60+b.m -(h*60 + m);
		t.h = k/60;
		t.m = k%60;
		return t;
	}
};
class one{
	protected:
		struct time entry,exit;
		int car_id;
	public:
		one(){
			cout<<"Car Id";
			cin>>car_id;
			cout<<"Enter entry time";
			cin>>entry.h>>entry.m;
			cout<<"Enter exit time";
			cin>>exit.h>>exit.m;
		}
};
class two{
	protected:
	int cartype;
	public:
	two(){
		cout<<"Enter car type by wheels";
		cin>>cartype;
		
	}
};
class derived: public one, public two
{
	private:
	float pay;
	public:
	derived()
	{
		pay = 0;
	}
	void calculate(){
		
		struct time diff = exit-entry;
		cout<<"Time Elapsed:"<<diff.h<<":"<<diff.m<<endl;
		
		int hours = diff.h + (diff.m==0?0:1);
		pay = ((cartype==4)?50*hours:30*hours);
		cout<<"You have to pay"<<pay<<endl;
	}
	
};
int main(){
	derived a;
	a.calculate();
	return 0;
}
 
