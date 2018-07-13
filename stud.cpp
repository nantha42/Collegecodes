#include <iostream>
#include <string.h>
using namespace std;

class student{
	int regno,marks[3];
	char name[20],grade;
	float percent;
	
	public:
	student(){
		regno = 0;
		strcpy(name,"");
		grade = '\0';
		percent = 0.0;
	}
	void display()
	{
		cout<<"reg no"<<regno<<" name:"<<name<<" phy:"<<marks[0]<<" math:"<<marks[1]
		    <<" chem:"<<marks[2]<<" percent:"<<percent<<" grade:"<<grade;
	}
	void calculate()
	{
		for(int i=0;i<3;i++)
			percent+=marks[i];
		percent/=300;
		if(percent<.50)
			grade = 'R';
		else if(percent<.60)
			grade ='C';
		else if(percent<.70)
			grade = 'B';
		else if(percent<.80)
			grade = 'A';
		else if(percent<.90)
			grade = 'S';
		else if(percent<1)
			grade = 'O';
		
	}
	void get_details()
	{
		cout<<"RollNO";
		cin>>regno;
		cout<<"Name";
		cin>>name;
		for(int i=0;i<3;i++)
		{	cout<<"Enter subject "<<i;
			cin>>marks[i];
		}		
	}
};
int main()
{
	student s;
	s.get_details();
	s.calculate();
	s.display();

}
