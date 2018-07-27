#include <iostream>
using namespace std;
class Float{
	float x;
	public:
	Float(){
		x = 0;
	}
	Float(float t){x=t;}
	
	Float operator +(Float a){
		Float r;
		r.x = x+a.x;
		return r;
	}
	Float operator -(Float a){
		Float r;
		r.x = x-a.x;
		return r;
	}
	
	Float operator *(Float a){
		Float r;
		r.x = x*a.x;
		return r;
	}
	
	Float operator /(Float a){
		Float r;
		r.x = x/a.x;
		return r;
	}
	void show(){
		cout<<x<<endl;
	}
};
int main(){
	Float a(3),b(4),c,d,e,f;
	c = a+b;
	d = a-b;
	e = a*b;
	f = a/b;
	c.show();
	d.show();
	e.show();
	f.show();
	
}
