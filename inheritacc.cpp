#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class account{
	protected:
		char name[20];
		char accno[3];
		char actype;
		float balance;
		float rate;	
	public:
		static int acount;
		
	public:
		
	account(char ta)
	{
		cout<<"Enter name:";
		cin>>name;
		acount++;
		
	}
};

class savings: public account
{
	
	int minbal;
	

	static int count;
		
	public:
	savings():account('s')
	{
		count++;
		accno[0] = 's';
		accno[1] = 48+(count/10);
		accno[2] = 48+(count%10);		
		cout<<accno;
		rate = .12;
		balance = minbal = 500;
	}
	void withdraw(int amt)
	{
		if(balance-minbal>=amt){
			balance -= amt;
		}
		else{
			cout<<"Not sufficient balance to withdraw"<<endl;
		}
	}
	void deposit(int amt){
		
		
		balance += amt;
		cout<<"Your Current balance is "<<balance<<endl;
	}

	void showdetails(){
		
		cout<<name<<" "<<accno<<" "<<actype<<" "<<balance<<endl;
	}
	void calinteret(){

		float n,year;
		cout<<"Enter number of times interest is compounded per year";
		cin>>n;
		cout<<"Enter year";
		cin>>year;
		cout<<endl<<rate/n;
		balance = balance + balance*pow((rate/n),n*year);
	}
};
class current:public account
{
	static int count;
	int minbal;
	
	public:
	current():account('c'){
		count++;
		
		accno[0] = 'c';
		accno[1] = 48+(count/10);
		accno[2] = 48+(count%10);
		cout<<accno;
		balance = minbal = 500;
	}
	void showdetails(){

		cout<<name<<" "<<accno<<" "<<actype<<" "<<balance<<endl;
	}
	void withdraw(int amt)
	{
		
		if(balance>=amt){
			balance -= amt;
		}
		else{
			cout<<"Not sufficient balance to withdraw"<<endl;
		}
	}
	void deposit(int amt){
		balance += amt;
		cout<<"Your Current balance is "<<balance<<endl;
	}

	void calinteret(){
		int n,year;
		cout<<"Enter number of times interest is compounded per year";
		cin>>n;
		cout<<"Enter year";
		cin>>year;
		cout<<endl<<rate/n;
		cout<<balance*pow(((float)rate/n),n*year);
		this->balance = balance + balance*pow((rate/n),n*year);
	}
};
int account::acount = 0;
int savings::count =0;
int current::count =0;

int main(){
	std::vector<savings*> s_accounts;
	std::vector<current*> c_accounts;
	int t=1,index;
	char ac[3];
	int amt;
	int rate;
	cout<<"1.create Saving 2.create Current 3.depsit 4.withdraw 5.display 6.minbalance 7.Interest";

	while(t){
		cout<<"\nEnter choice";
		cin>>t;
		
		switch(t){
			case 1:

				s_accounts.push_back(new savings());
				break;
			case 2:
				c_accounts.push_back(new current());
				break;

			case 3:
				cout<<"Enter account number";
				cin>>ac;
				cout<<"Enter amount:";
				cin>>amt;
				if(ac[0]=='s'){
					index = (ac[1]-48)*10+(ac[2]-48)-1;
					cout<<"Index"<<index;
					s_accounts[index]->deposit(amt);
				}
				else{
					index = (ac[1]-48)*10+(ac[2]-48)-1;
					cout<<"Index"<<index;
					c_accounts[index]->deposit(amt);
				} 	
				break;
			case 4:

				cout<<"Enter account number";
				cin>>ac;
				cout<<"Enter amount:";
				cin>>amt;
				if(ac[0]=='s'){
					index = (ac[1]-48)*10+(ac[2]-48)-1;
					cout<<"Index"<<index;
					s_accounts[index]->withdraw(amt);
				}
				else{
					index = (ac[1]-48)*10+(ac[2]-48)-1;
					cout<<"Index"<<index;
					c_accounts[index]->withdraw(amt);
				} 	
				break;				
			case 5:
				cout<<"Enter account number";
				cin>>ac;

				if(ac[0]=='s'){
					index = (ac[1]-48)*10+(ac[2]-48)-1;
					cout<<"Index"<<index;
					s_accounts[index]->showdetails();
				}
				else{
					index = (ac[1]-48)*10+(ac[2]-48)-1;
					cout<<"Index"<<index; 
					c_accounts[index]->showdetails();
				}
				break;
			case 6:
				for(int i=0;i<s_accounts.size();i++)
					s_accounts[i]->showdetails();
				for(int i=0;i<c_accounts.size();i++)
					c_accounts[i]->showdetails();
				break;
			case 7:
				cout<<"Enter account number";
				cin>>ac;
				if(ac[0]=='s'){
					index = (ac[1]-48)*10+(ac[2]-48)-1;
					cout<<"Index"<<index; 
					s_accounts[index]->calinteret();
				}
				else{ 
					index = (ac[1]-48)*10+(ac[2]-48)-1;
					cout<<"Index"<<index; 
					c_accounts[index]->calinteret();
				}
		}
	}
	
	return 0;
}
