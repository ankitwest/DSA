#include <bits/stdc++.h>
using namespace std;
#define ln cout<<"\n";

//Not Understood
void insertAtBottom(stack<int> &st , int ele){

    if(st.empty()){
        st.push(ele);
        return;
    }

    int  topElement = st.top();
    st.pop();
    insertAtBottom(st,ele);

    st.push(topElement);
}
void reverse(stack<int> &st){

    if(st.empty()){
        return;
    }

    int ele= st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,ele);
}

int main(){

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    reverse(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    ln;
}