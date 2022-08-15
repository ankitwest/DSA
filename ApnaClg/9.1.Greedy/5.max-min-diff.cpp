#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){

	   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    #endif

    int n;cin >> n;
    vector<int> a(n);
    for(auto &i : a)
    	cin>>i;

    sort(a.begin(),a.end());
    int minD=0,maxD=0;

    for(int i=0;i<n/2;i++){
    	maxD += ( a[n/2+i]-a[i]);
    	minD += ( a[2*i+1]-a[2*i]);
    }

cout<<maxD<<" "<<minD<<endl;
return 0;
}