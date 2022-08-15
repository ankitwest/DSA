#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i = a ; i < n ; i++)

void basic(){
    map<int,int> m;
    m[0]=2;
    cout<<m[0]<<endl;
}  

//Not understood again
//?Question?  No of subarray with sum zero
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x:a) cin>>x;
//    for(int &x:a) cout<<x;

   map<int,int> count;

    int prefixSum =0;
    rep(m,0,n){
        prefixSum += a[m]; 
        count[prefixSum]++;
    }
    int ans=0;

    // map<int,int> :: iterator i;
    // for(i=count.begin(); i!=count.end();i++){
        for(auto i : count){
        int c = i.second;
        ans += (c*(c-1))/2;

        if(i.first ==0)
            ans+= i.second;
    }
    cout<<ans<<endl;

    return 0;
}