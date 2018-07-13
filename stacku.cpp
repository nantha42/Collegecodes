#include<iostream>
#include<stdlib.h>
using namespace std;
class stack
{
             int stk[5];
             int top;
      public:
             stack()
              {
                top=-1;
               }
             void push(int x)
              {
		if(top<=4){
			top++;
			stk[top] = x;
			cout<<"top"<<top<<endl;
		}
                else	cout<<"Stack overflow"<<endl;
               }
             void pop()
               {
                  if(top <0)
                   {
                         cout <<"stack under flow";
                         return;
                    }
                    cout <<"deleted" <<stk[top--];
                }
             void display()
               {
                   if(top<0)
                    {
                            cout <<" stack empty";
                            return;
                    }
                    for(int i=top;i>=0;i--)
                    cout <<stk[i] <<" ";
                }
};
 
main()
{
     int ch;
     stack st;
     while(1)
        {
             cout <<"\n1.push  2.pop  3.display  4.exit\nEnter ur choice";
             cin >> ch;
             switch(ch)
              {
               case 1: 
			int a;
			 cout <<"enter the element";
                        cin >> a;
                        st.push(a);
                        break;
               case 2:  st.pop();  break;
               case 3:  st.display();break;
               case 4:  exit(0);
               }
         }
return (0);
}
