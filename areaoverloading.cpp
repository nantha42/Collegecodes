#include <iostream>
#include <string.h>
using namespace std;
void area(float b,float h){
	cout<<"Area of Triangle "<<.5*b*h<<endl;
}
void area(int x){
	cout<<"Area of Square "<<x*x<<endl;
}
void area(float x){
	cout<<"Area of circle "<<3.14*x*x<<endl;
}
void area(int l, int b){
	cout<<"Area of Rectangle "<<l*b<<endl;
}
int main(){
	int b=1;
	float a,c;
	int e,d;
	int x;
	while(b){
		cout<<"1.Triangle 2.Square 3.Circle 4.Rectangle 0.quit"<<endl;
		cin>>b;
		switch(b){
			case 1:
			
			cin>>a>>c;
			area(a,c);break;
			case 2:
			int x;
			cin>>x;
			area(x);break; 
			case 3: cin>>a;area(a);break;
			case 4: cin>>e>>d;area(e,d);break;

		}
	}

}
