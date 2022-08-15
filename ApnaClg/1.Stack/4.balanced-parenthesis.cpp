#include <bits/stdc++.h>
using namespace std;
#define ln cout<<"\n";
#define debug1(x) cout<<(x)<<endl


bool isValid(string s){
    int n= s.size();

    stack<char> st;
    bool ans = true;

    for(int i=0;i<n;i++){
        if(s[i] == '{' or s[i] == '(' or s[i] == '['){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            if(!st.empty() and st.top()=='(')
                st.pop();
            else return false;
        }
        else if(s[i] == '}'){
            if(!st.empty() and st.top()=='{')
                st.pop();
            else return false;
        }
         else if(s[i] == ']'){
            if(!st.empty() and st.top()=='[')
                st.pop();
            else return false;

        }
    }

    if(!st.empty())  return false;
    return ans;
}
int main(){
    string s="{([])}";
    string a="[{()}]{{}}{";
  
    if(isValid(a)){
        debug1("Valid String");
    }
    else{
        debug1("Invalid String");
    }
      return 0;
}


