#include <iostream>

struct node{
	int t;

}
struct bstnode{
        int data;
         bstnode *left,*right;
};

bstnode *insert(int x,bstnode *t){
        if(t==NULL){
                //t = (bstnode *) malloc(sizeof(bstnode));
                t = new bstnode;
                t->data = x;
                t->left = t->right = NULL;
        }
        else if(t->data>x){
                t->left = insert(x,t->left);
        }
        else if(t->data<x){
                t->right = insert(x,t->right);
        }
        return t;

}
bstnode* findmin(bstnode *t){
        bstnode *temp = t;
        
        while(temp->left!=NULL)
                  temp = temp->left;
        return temp;
        
        
}
bstnode * findmax(bstnode *t){
        bstnode *temp = t;
   
           while(temp->right!= NULL)
    	        temp = temp->right;
        return temp;
   
}

struct bstnode *delete(int x,struct bstnode *t){
        if(t==NULL){
                printf("Empty Tree");
        }

        else if(x<t->data){
                t->left = delete(x,t->left);
        }
        else if(x>t->data){
                t->right = delete(x,t->right);
        }
		else{
			if(t->left == NULL){
				struct bstnode *temp = t->right;
				delete t;			
				return temp;
			}
			else if(t->right == NULL){
				struct bstnode *temp = t->left;
				delete t;
				return temp;
			}
			bstnode *temp = findmin(t->right);
			t->data = temp->data;
			t->right = delete(t->data,t->right);
		}       
	 return t;
}