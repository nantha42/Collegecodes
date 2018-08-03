#include <iostream>
#include <vector>
using namespace std;

class account{
	protected:
		char name[20];
		char accno[3];
		char actype;
		float balance;
		
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
	int a;
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
		balance = minbal;
	}
	void withdraw()
	{
		int amt;
		cout<<endl<<"Enter the amount you want to withdraw";
		cin>>amt;
		if(balance-minbal>=amt){
			balance -= amt;
		}
		else{
			cout<<"Not sufficient balance to withdraw"<<endl;
		}
	}
	void deposit(){
		int amt;
		cout<<endl<<"Enter the amout you want to deposit";
		cin>>amt;
		
//		balance += amt;
//		cout<<"Your Current balance is "<<balance<<endl;
	}
	
};
class current:public account
{
	static int count;
	int minbal;
	public:
	current():account('c'){
		count++;
		balance = minbal = 500;
		accno[0] = 'c';
		accno[1] = 48+(count/10);
		accno[2] = 48+(count%10);
		cout<<accno;
		
	}
	
	void withdraw()
	{
		int amt;
		cout<<endl<<"Enter the amount you want to withdraw";
		cin>>amt;
		if(balance>=amt){
			balance -= amt;
		}
		else{
			cout<<"Not sufficient balance to withdraw"<<endl;
		}
	}
	void deposit(){
		int amt;
		cout<<endl<<"Enter the amout you want to deposit";
		cin>>amt;
		balance += amt;
		cout<<"Your Current balance is "<<balance<<endl;
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
	cout<<"1.create Saving 2.create Current 3.depsit 4.withdraw 5.display 6.minbalance";
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
				if(ac[0]=='s'){
					index = (ac[1]-48)*10+(ac[2]-48);
					cout<<"Index"<<index;
					s_accounts[index]->deposit();
				}
				else{
					index = (ac[1]-48)*10+(ac[2]-48);
					c_accounts[index]->deposit();
				} 	
				break;
			case 4:

				cout<<"Enter account number";
				cin>>ac;
				if(ac[0]=='s'){
					index = (ac[1]-48)*10+(ac[2]-48);
					
					s_accounts[index]->withdraw();
				}
				else{
					index = (ac[1]-48)*10+(ac[2]-48);
					cout<<index;
					c_accounts[index]->withdraw();
				} 	
				break;
				
				

		}
	}
	
	return 0;
}
