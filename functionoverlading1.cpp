#include <iostream>
#include <string.h>
using namespace std;
void add(int a,int b){
	cout<<a+b<<endl;
}
void add(float a,float b){
	cout<<a+b<<endl;
}
void add(char a[],char b[]){
	char c[50];
	strcat(a,b);
	strcpy(c,a);
	cout<<c<<endl;
}
int main(){
	int a,b;
	cin>>a>>b;
	add(a,b);
	float c,d;
	cin>>c>>d;
	add(c,d);
	char e[30],f[30];
	cin>>e>>f;
	add(e,f);
	return 0;
}
