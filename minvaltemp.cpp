#include <iostream>
using namespace std;
template <class T>
void fun(T a[],int n){
	T min=a[0];
	for(int i=1;i<n;i++){
		if(min>a[i]){
			min = a[i];
		}
	}
	cout<<"Min = "<<min<<endl;
} 
int main(){
	char a[10];
	int b[5];
	float c[5];
	
	cout<<"Enter a string";
	cin>>a;

	
	for(int i=0;i<5;i++)
		cin>>b[i];
		
	for(int i=0;i<5;i++)
		cin>>c[i];
		
	fun(a,10);
	fun(b,5);
	fun(c,5);
	return 0;
}
