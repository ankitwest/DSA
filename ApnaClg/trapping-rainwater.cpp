#include <bits/stdc++.h>
using namespace std;

#define ln cout<<"\n";
#define debug1(x) cout<<(x)<<endl

// using two max variable one from left and other from right
// then taking min of those two

//Not understood again

int rain_water(vector<int> a){ //Optimal solution 
    stack<int> st;
    int n = a.size();
    int ans;
    for(int i=0;i<n;i++){
        while(!st.empty() and (a[st.top()] < a[i])){
            int cur = st.top();
            st.pop();
            if(st.empty()){
                break;
            }
            int diff = i - st.top() -1;
            ans += (min(a[st.top()] , a[i]) - a[cur]) * diff;

        }
        st.push(i);
    }
    return ans;
}

int32_t main(){
    vector<int> vec{0,1,0,2,1,0,1,3,2,1,2,1};
    rain_water(vec);
    return 0;
}