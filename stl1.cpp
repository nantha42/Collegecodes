#include <iostream>
#include <vector>
using namespace std;
int find(vector <int> b,int x){

	vector<int>::iterator a;
	int t=0;
	for(a = b.begin();a != b.end();++a,t++){
		if(x==*a)
			return t;
		
	
	}
	
}
int count(vector <int> b,int x){
	int count = 0;
	vector<int>::iterator a;
	for(a = b.begin();a!=b.end();++a){
		if(x==*a)
			count++;
	}
	return count;
}
int main(){
	vector <int> a;
	int i=1;
	cout<<"Enter other than 1";
	while(i){
		cin>>i;
		if(i!=0)
		a.push_back(i);
	}
	cout<<endl<<find(a,3);
	cout<<endl<<count(a,3);
	
}
