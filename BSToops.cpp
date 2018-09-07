#include <iostream>
using namespace std;

template <class T>
class Tree{
	private:
		struct node{
			T data;
			node *left,*right;
		}*tree;
		
		node *pinsert(T x,node *t){
			if(t==NULL){
				node *p = new node;
				p->data = x;
				p->left = p->right = NULL;
				t = p;
			}
			else if(x<t->data){
				t->left = pinsert(x,t->left);
			}
			else t->right = pinsert(x,t->right);
			
			return t;	
		}
		node* pfindmin(node *t){
			node *temp = t;
			while(temp->left!=NULL)
				temp = temp->left;
			return temp;
			
		}
		
		void ppostorder(node *t){
			if(t!=NULL){
			ppostorder(t->left);

			ppostorder(t->right);
			cout<<t->data<<" ";
			}
		}
		void pinorder(node *t){
			if(t!=NULL){
			pinorder(t->left);
			cout<<t->data<<" ";
			pinorder(t->right);
			}
		}
		
		void ppreorder(node *t){
			if(t!=NULL){
			cout<<t->data<<" ";
			ppreorder(t->left);
			ppreorder(t->right);
			}
		}

		node* pdelete(T x,node *t){
			if(t==NULL){
				cout<<"Element no found";
				return NULL;
			}
			else if(x<t->data){
				t->left = pdelete(x,t->left);
			}
			else if(x>t->data)
				t->right = pdelete(x,t->right);
			else{
			
				if(t->left == NULL){
					node *temp = t->right;
					delete t;			
					return temp;
				}
				else if(t->right == NULL){
					node *temp = t->left;
					delete t;
					return temp;
				}
				node *temp = pfindmin(t->right);
				t->data = temp->data;	
				t->right = pdelete(t->data,t->right);
			}       
		 return t;
		}
		
		
	public:
	
		Tree(){
			tree = NULL;
		}
		void insert(T x){
			tree = pinsert(x,tree);
		}
		
		void inorder(){
			pinorder(tree);
		}
		void preorder(){
			ppreorder(tree);
		}
		void postorder(){
			ppostorder(tree);
		}
		void tdelete(T x){
			tree = pdelete(x,tree);
		}		
		
};
int main(){
	Tree<string> t;
	t.insert("nanthak"); 
	t.insert("nagthak");	
	t.inorder();
	t.tdelete("nanthak");
	t.inorder();
	
}






















