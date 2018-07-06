#include <stdio.h>
#include <stdlib.h>
struct employee{
	int empno;
	char empname[20];
	char position[20];
	int salary;
	struct employee *next;
}*head;
void insertatend(){
	struct employee *node = (struct employee*)malloc(sizeof(struct employee));
	/*printf("Enter no");
	scanf("%d",&node->empno);
	printf("Enter name");
	scanf("%s",node->empname);
	printf("Enter position");
	scanf("%s",node->position);*/
	printf("Enter salary");
	scanf("%d",&node->salary);	
	
	if(head==NULL){
		head=node;
		node->next = NULL;
	}
	else{
		struct employee *temp;
		temp = head;
		while(temp->next!=NULL)
			temp = temp->next;
		temp->next = node;
	} 
}
void nonrecursive(){
	struct employee *a=NULL,*b=NULL,*c=NULL;
	struct employee *temp=head;
	while(temp->next!=NULL){
		a = temp;
		b = temp->next;
		a->next = c;
		temp = b->next;
		b->next = a;
		c = b;
	}
	temp->next = c;
	head = temp;
}
struct employee *reverse(struct employee *a,struct employee *b){
	if(b==NULL){
		head = a;
		return head;
	}
	else{
		struct employee *anext = reverse(b,b->next);
		anext->next = a;
		return a;
	}	
}
void crverse(){
	printf("reversing the list");
	struct employee *thead;
	thead = reverse(head,head->next);
	thead->next = NULL;
}
void bubblesort(){
	struct employee *stop;
	struct employee *big;
	struct employee *temp;
	big = head;
	stop=NULL;
	
	for(stop=NULL;stop!=head;){
		temp = big;
		for(big=head;big->next!=stop;big=big->next){
			
			
			if(big->salary>big->next->salary){
				if(big==head){
					struct employee *netemp = big->next;
					big->next = netemp->next;
					netemp->next = big;
					big = netemp;
					head = netemp;
				}
				else{
				temp->next = big->next;
				big->next = big->next->next;
				temp->next->next = big;
				big = temp->next;	
				}
			}
			temp = big;
		}
		stop = big;
	}

}
void display(){
	struct employee *temp;
	temp = head;
	while(temp!=NULL){
		printf("No:%d name:%s Position:%s salary:%d\n",temp->empno,temp->empname,temp->position,temp->salary);
		temp = temp->next;
				
	}
}
void main(int argc,char *argv[])
{
	
	int y;
	do{
		printf("1.insert 2.bubblesort 3.display 4.creverse 5.nonrecursive 0.quit");
		scanf("%d",&y);
		switch(y)
		{
			case 1:insertatend();break;
			case 2:bubblesort();break;
			case 3:display();break;
			case 4:crverse();break;
			case 5:nonrecursive();break;

		}	
	}while(y);
}
