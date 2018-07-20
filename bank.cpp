#include <iostream>
#include <string.h>
using namespace std;
class Account{
	
	char name[30];
	int acno;
	
	char type;
	float bal;
	
	
	public:
	Account(){
		strcpy(name,"");
		acno = 0;
		type = ' ';
		bal = 0.0;	
	}
	void Edit_account(){
		cout<<"Enter account holder name";
		cin>>name;
		cout<<"Enter account number";
		cin>>acno;	
		cout<<"Enter account type: 'S'aving 'C'urrent 'J'oint 'M'inor"<<endl;
		cin>>type;
		cout<<"Enter initial amount";
		int amt;
		cin>>amt;
		this->depositamt();
	}		
	void depositamt(){
		int amt;
		cout<<"Enter the amt";
		cin>>amt;
		
		bal = bal+amt;
		cout<<"Money deposited"<<endl;	
	}
	float withdraw(){
		int amt;
		cout<<"Enter amount";
		cin>>amt;
		if(bal > amt){
			bal = bal - amt;
			cout<<"Money withdrawn"<<endl;
			return amt;
		}
		else{
			cout<<"Cannot Withdraw Money"<<endl;
			return 0;		
		}
	}
	bool match(int no){
		if(acno == no)
			return true;
		return false;
	}
	void display(){
		cout<<"Name:"<<name<<endl
			<<"Accno:"<<acno<<endl;
		cout<<"Type of Account:";
		switch(type){
			case 'S':
				cout<<" Savings"<<endl;
				break;
			case 'C':
				cout<<" Current"<<endl;
				break;
			case 'M':
				cout<<" Minor"<<endl;
				break;
			case 'J':
				cout<<" Joint"<<endl;
				break;
				
		}
		cout<<"Balance: "<<bal<<endl;

	}
	
};
int enter(){
	int a;
	cout<<"Enter the account no";
	cin>>a;
	return a;
}
int main(){
	Account ac[5];
	int i =0,b = 1;int acc;
	//Enter the accounts
	for(;i<5;i++)
		ac[i].Edit_account();	
	


	while(b){
		cout<<"1.Deposit 2.Withdraw 3.ViewAccount";
		cin>>b;
		switch(b){
			case 1:
				acc = enter();	
				for(i=0;i<5;i++)
				{ 
					if(ac[i].match(acc)){
						ac[i].depositamt();
						break;
					}
				}
				break;
			case 2:
			
				acc = enter();	
				for(i=0;i<5;i++)
				{
					if(ac[i].match(acc)){
						ac[i].withdraw();
						break;
					}
				}
				break;
			case 3:
				acc = enter();
				for(i=0;i<5;i++)
				{
					if(ac[i].match(acc)){
						ac[i].display();break;
					}				
				}
		}
	}
}
