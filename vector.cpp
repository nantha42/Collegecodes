#include <iostream>
using namespace std;

class Vector{
	float *p;
	int s;
	
	public:
		Vector(int s){
			this->s = s;
			p = new float[s];
			for(int i=0;i<s;i++)
				cin>>p[i];		
		}
		
		void scalarproduct(float x){
			for(int i=0;i<s;i++){
				p[i] = p[i]*x;
			}
		}
		void modify(int x,float y){
			for(int i= 0;i<s;i++){
				if(p[i] = x)
				{
					p[i] = y;
					return ;
				}
			}
			cout<<"Element Not found"<<endl;

		}
		void display(int ord){
			if(ord>0){
				cout<<"[ ";
				for(int i=0;i<s;i++)
					cout<<p[i]<<" ";			
				cout<<"]"<<endl;
			}
			else if(ord<=0){
				cout<<"[ ";
				for(int i=s-1;i>=0;i--)
					cout<<p[i]<<" ";			
				cout<<"]"<<endl;
			}
		}
		
};
int main(){
	int s;
	cout<<"Enter the vector size";
	cin>>s;
	Vector v(s);
	float i,j;

	int b = 1;

	
	while(b){
		cout<<"1.multiply 2.modify 3.ascend_display 4.Descend_display";
		cin>>b;
		switch(b){
			case 1:	
				cout<<"Enter a number:";
				cin>>i;
				v.scalarproduct(i);
				break;
			case 2:
				cout<<"Enter the element to be replaced";
				cin>>i;
				cout<<"Enter the element to be insterted";
				cin>>j;
				v.modify(i,j);	break;
			case 3:
				v.display(1);
				break;
			case 4:
				v.display(-1);
				break;
		}
	}
}
