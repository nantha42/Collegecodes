#include <iostream>
using namespace std;
class Queue{
	int front,rear;
	int arr[10];
	public:
	Queue(){
		front = rear = -1;
	}
	void Enqueue(int x){
		if(front==-1){
			front = 0;
		}

		if(rear>=9){
			cout<<"Queue Overflow";
			return;
		}
		rear++;
		arr[rear] = x;
	}
	int Dequeue(){
		if(front == -1){
			cout<<"Queue Underflow";
			return -1;
		}
		else{
			int x = arr[front];
			front++;
			if(front>rear){
				front = rear = -1;
			}
			return x;
		}
	}
	void display(){
		int i = front;
		for(;i<=rear;i++)
			cout<<arr[i]<<" ";
		cout<<endl;

	}

};
int main(){
	Queue q;
	int b,x;
	b = 1;
	while(b){
		cout<<"1.Enqueue 2.Dequeue 3.Display"<<endl;
		cin>>b;
		switch(b){
			case 1:
				cout<<"Enter a element";
				cin>>x;
				q.Enqueue(x);
				break;
			case 2:
				x = q.Dequeue();
				cout<<x<<endl;break;
			case 3:
				q.display();
		}

	}
	
}
