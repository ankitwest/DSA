#include <bits/stdc++.h>
using namespace std;
#define ln cout<<"\n";
#define debug1(x) cout<<(x)<<endl

#define n 100

class Stack{
    int* array;
    int top;
    public :
        Stack(){
            array = new int[n];
            top=-1;
        }

        void push(int x){
            if(top==n-1){
                cout<<"Stack overflow"<<endl;
                return;
            }
            top++;
            array[top] = x;
        }

        void pop(){
            if(top ==-1){
                cout<<"No element to pop"<<endl;
                return ;
            }
            top--;
        }

        int topmost(){
            if(top==-1){
                cout<<"No elements in stack or "<<endl;
                return -1;
            }
            return array[top];
        }

        bool empty(){
            return top==-1;
        }
};

int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    debug1(st.topmost());
    st.pop();
    debug1(st.topmost());
    st.pop();
    debug1(st.topmost());
    st.pop();
    debug1(st.topmost());
    debug1(st.empty());
    
    
   


    return 0;
}