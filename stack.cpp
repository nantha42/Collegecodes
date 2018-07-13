#include <iostream>
#define MAXI 8
using namespace std;

class stack{
	int top;
	int arr[MAXI];
	public:
	stack(){
		top = -1;
	}
	void push(int x);
	int pop();
	void display();	
};
void stack::push(int x)
{
	if(top<MAXI-2){
		top++;
		arr[top] = x;
	}
	else
		cout<<"Stack Overflow"<<endl;
}
int stack::pop(){
	if(top>-1){
		int retu = arr[top];
		top--;
		return retu;
	}
	else{
		cout<<"Stack Underflow"<<endl;
	}
}
void stack::display(){
	int i = top;
	while(i>-1){
		cout<<arr[i]<<endl;
		i--;
	}
		
}
int main(){
	stack s;
	int Bool=1;
	while(Bool){
		cout<<"1.Push 2.Pop 3.Display 0.quit"<<endl;
		cin>>Bool;
		switch(Bool){
			case 1:
				cout<<"Enter number";
				int x;cin>>x;s.push(x);
				break;
			case 2:
				cout<<"Popped number:"<<s.pop()<<endl;	break;
			case 3:
				s.display();

		}
	}
	return 0;
}







