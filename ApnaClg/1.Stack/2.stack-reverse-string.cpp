#include <bits/stdc++.h>
using namespace std;
#define ln cout<<"\n";

#define n 100

void reverseSentence(string s){
    stack<string> st;
    for(int i=0; i<s.length(); i++){

        string word="";
        while(s[i] != ' ' and i<s.length()){
            word += s[i];
            i++;
        }

        st.push(word);
    }   

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    ln;
}


int main(){
    string s ="Hey! how are you doing?";
    reverseSentence(s);
}