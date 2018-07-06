#include <stdio.h>
struct employee{
	int empno;
	char empname[20];
	char position[20];
	int salary;
}employees[100];
int count;
void empdetails(struct employee e){
	printf("No:%d name:%s Position:%s salary:%d\n",e.empno,e.empname,e.position,e.salary);
}
void empgreaterthan(int x){
	int i;
	for(i=0;i<=count;i++)
	{
		if(employees[i].salary>x){
			empdetails(employees[i]);
		}	
	}
}
void inbet(int a,int b){
	int i;
	for(i=0;i<=count;i++)
	{
		if(employees[i].salary>a && employees[i].salary<b){
			empdetails(employees[i]);
		}	
	}
}
void insert(){
	
	printf("Enter no");
	scanf("%d",&employees[count].empno);
	printf("Enter name");
	scanf("%s",&employees[count].empname);
	printf("Enter position");
	scanf("%s",&employees[count].position);
	printf("Enter salary");
	scanf("%d",&employees[count].salary);	
	count++;
}
int main(){
	count=0;	
	int y;
	do
	{

	  printf("1.insert 2.find greater 3.3to4 0.quit");
	  scanf("%d",&y);	
	  switch(y){
		
		case 1:
		insert();
		break;
		case 2:
		empgreaterthan(70000);
		break;
		case 3:
		inbet(30000,40000);
	}

	}while(y);
	return 0;
}

