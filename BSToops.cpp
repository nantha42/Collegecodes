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

		node* ldelete(T x,node *t){
			if(t==NULL){
				cout<<"Element no found";
				return NULL;
			}
			else if(x<t->data){
				t->left = ldelete(x,t->left);
			}
			else if(x>t->data)
				t->right = ldelete(x,t->right);
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
				t->right = ldelete(t->data,t->right);
			}       
		 return t;
		}
		node * pfindmax(node *t){
			node *temp = t;
			while(temp->right != NULL)
				temp  = temp->right;
			return temp;
		}
		
		node* rdelete(T x,node *t){
			if(t==NULL){
				cout<<"Element not found";
				return NULL;
			}
			else if(x<t->data){
				t->left = rdelete(x,t->left);
			}
			else if(x>t->data)
				t->right = rdelete(x,t->right);
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
				node *temp = pfindmax(t->left);
				t->data = temp->data;	
				t->left = ldelete(t->data,t->left);
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
			tree = ldelete(x,tree);
		}
		void jdelete(T x){
			tree = rdelete(x,tree);
		}		
		
};
int main(){
	Tree<int> t;
	int x=1,a;
	
	while(x){
		cout<<"1.Insert 2.Delete 3.Preorder 4.Inorder 5.PostOrder";
		cin>>x;
		switch(x){
			case 1:
		
				cout<<"Enter a number";
				cin>>a;
				t.insert(a);
				break;
			case 2:
				cout<<"Enter a number";
				cin>>a;
				t.tdelete(a);
				break;
			case 3:
				t.preorder();
				break;
			case 4:
				t.inorder();
				break;
			case 5:
				t.postorder();
				break;		
				
		}
	}		
}






















