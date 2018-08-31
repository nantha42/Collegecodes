#include<iostream>
#include <list>
#include <iterator>
#include <string>
#include<map>
using namespace std;
class student{
	public:
		string name;
		int roll;
		
	student(){
		cout<<"Enter anme";
		cin>>name;
		cout<<"Roll no";
		cin>>roll;
	}
};

int main(){
	int i=0;
	list<student> lt;
	list<student>::iterator a;
	map<string,int> mapper;

	while(i<5){
		student s;
		lt.push_back(s);
		i++;
	}
		for(a = lt.begin();a!=lt.end();a++){
			mapper.insert(pair<string,int>(a->name,a->roll));
		}
	map<string,int>::iterator itr;
	string justaname="a";
	int jaroll=1;
	char t;
	while(justaname!="" || jaroll){
		cout<<"Enter a name or roll (n,r)";
		cin>>t;
		if(t=='r'){
			cin>>jaroll;
			for(itr = mapper.begin();itr!=mapper.end();itr++){
				if(itr->second==jaroll){
					cout<<itr->first<<endl;
				}
			}
		}
		else if(t=='n'){
			cin>>justaname;
			for(itr = mapper.begin();itr!=mapper.end();itr++){
				if(itr->first==justaname){
					cout<<itr->second<<endl;
				}
			}
		}
		else{
			justaname = "";
			jaroll = 0;
			
		}
	}
}
