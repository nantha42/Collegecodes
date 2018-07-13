#include <iostream>
using namespace std;
class strings{
	char string[100];
	
	public:
	strings(){}
	strings(char str[]){
		int i;
		for(i=0;str[i] != '\0';i++)
			string[i] = str[i];
		str[i] = '\0';
	}
	void setdef(){
		string[0] = '\0';
	}
	void copy(char str[]){
		int i;
		for(i=0;str[i] != '\0';i++)
			string[i] = str[i];
		string[i] = '\0';
	}
	void substring(strings str){
		int i,j,found = 0;

		for(i=0;string[i]!='\0';i++){
			for(j=0;;){
				if(string[i+j]!=str.string[j]){
					found = 0;
					break;
				}
				
				j++;
				cout<<j<<" "<<str.length()<<endl;
				if(j==str.length()){
					found = 1;break;
				}
			}
			if(found==1)break;
		}
		if(found == 1) cout<<"Found at"<<i<<endl;
		else cout<<"Not Found";

	}
	void extract(strings s,int i,int l){
		int j=0;
		while(j<l){
			string[j] = s.string[i+j];
			j++;
		}
		string[j] = '\0';
	}
	int length(){
		int i,count=0;
		for( i=0;string[i]!='\0';i++){
			count++;
		}
		return count;
	}
	void copy(strings target)
	{	
		int i;
		for( i=0;target.string[i]!='\0';i++)
		{
			string[i] = target.string[i];
		}
		string[i] = '\0';
	}
	void concat(strings nstr){
		int i,len;
		len = this->length();
		
		for( i=0;nstr.string[i]!='\0';i++){
			string[len+i] = nstr.string[i];			
		}
		string[len+i] = '\0';
	}
	void display(){
		cout<<string<<endl;
	}

};
int main()
{


	int Bool=1;
	strings s,s1,s2;
	char str[100],str1[100],str2[100];
	while(Bool){
		cout<<"1.length 2.Copy 3.Concat 4.Substring 0.Quit"<<endl;
		cin>>Bool;
		switch(Bool){
			case 1:

				cin>>str;
				s.copy(str);
				cout<<"length "<<s.length()<<endl;
				break;
			case 2:
				
				
				cout<<"Enter two strings";
				cin>>str1>>str2;
				s1.copy(str1);
				s2.copy(str2);

				s1.display();
				s2.display();
				cout<<"Copying"<<endl;
				s1.copy(s2);
				s1.display();
				s2.display();
				break;
			case 3:
				
				
				cout<<"Enter two strings";
				cin>>str1>>str2;
				s1.copy(str1);
				s2.copy(str2);
				
				cout<<"Concated String";
				s1.concat(s2);
				s1.display();
				break;
			case 4:

				int start,lent;
				cout<<"Enter string, starting position, length";
				cin>>str1>>start>>lent;
				
				s2.copy(str1);
				
				s1.extract(s2,start,lent);
				s1.display();
				break;

		}
		s.setdef();
		s1.setdef();
		s2.setdef();
		
	}


	return 0;
}
