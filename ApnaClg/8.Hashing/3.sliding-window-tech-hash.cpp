#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i = a; i < n; i++)

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(auto &x:v) cin>>x;

    int sum=0,minSum=INT_MAX;
    for(int i = 0; i < k; i++){
        sum+=v[i];
    }
    minSum=min(sum,minSum);
    for(int i = k; i < n; i++){
        sum= sum + v[i] - v[i-k];
        minSum=min(sum,minSum);
    }
    cout<<minSum<<endl;
        
    }


