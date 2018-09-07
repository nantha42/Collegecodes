#include <iostream>
using namespace std;

template <class T>
class vector{
	private:
		T *p;
		int size;
	public:
		vector(int n){
			size = n;
			p = new T[n];
				
		}
		T& operator [](int n){
			if(n>size){
				cout<<"-100";
			}
			return p[n];
		}
		void display(){
			cout<<"(";
			
			for(int i=0;i<size-1;i++)
				cout<<p[i]<<",";
			cout<<p[size-1];
			cout<<")";
		}
		void insert(){
			for(int i=0;i<size;i++)
				cin>>p[i];
		}
		void modify(T k,T j){
			for(int i=0;i<size;i++){
				if(p[i] == k)
					p[i] = j;
			}
		}
		void multi(T x){
			for(int i=0;i<size;i++)
				p[i] = x*p[i];
		}
		
};
int main(){
	vector<float> k(5);
	vector<int> j(9);
	int t;
	
	k.insert();
	k.display();
	k.modify(1,0);
	k.multi(3.5);
	k.display();
		
	j.insert();
	j.display();
	j.modify(1,0);
	j.multi(1.1);
	j.display();
	
}
