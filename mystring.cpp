#include <iostream>
#include <string.h>
using namespace std;

class myString{
	char str[40];
	public:
		myString(){
			strcpy(str,"");		
		}
		myString(char a[]){
			strcpy(str,a);
		}
		void assign(char a[]){
			strcpy(str,a);
		}
		void show(){
			cout<<str<<endl;
		}
		myString operator +(myString mys){
			myString res;
			strcat(res.str,str);
			strcat(res.str,mys.str);
			return res;
		}
		int operator ==(myString mys){
			if(strcmp(str,mys.str)==0)
				return 1;
			else return 0;
		}
		int operator -(){
			if(!strcmp(str,""))
				return 1;
			else return 0;
		}

};
int main(){
	char mstr1[30],mstr[30];
	cin>>mstr1>>mstr;
	myString m1(mstr1),m2(mstr),m3,m4;
	m3 = m1+m2;
	m3.show();
	int k;
	k = m1==m2;
	cout<<endl<<"Equality="<<k;
	cout<<endl<<"Empty or not = "<<-m4;
	cout<<endl<<"Emptry or not = "<<-m3;
	
}









