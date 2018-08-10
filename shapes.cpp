#include <iostream>
using namespace std;

class shape{
	protected:
		double a,b;
	public:
	shape(){
		a = b =0;
	}
	void getdata(){
		cin>>a>>b;
	}
	virtual void display()
	{
	}
};
class triangle: public shape{
	void display(){
		cout<<.5*a*b;
	}
	
};
class rectangle:public shape{
    void display(){
		cout<<a*b;
	}
};
int main(){
	shape *p;
	int t=1;
	
	while(t){
			cout<<"calculate area 1.triangle 2.rectangle";
			cin>>t;
			
			switch(t){
				case 1:
					p = new triangle;
					break;
				case 2:
					 p = new rectangle;
					 break;
				default:
					p = new shape;
					
			}
			p->getdata();
			cout<<"Area = ";
			p->display();
					
			delete p;
	}
		
	return 1;
}

