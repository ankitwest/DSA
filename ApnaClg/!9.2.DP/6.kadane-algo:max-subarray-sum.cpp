
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){

	  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    #endif
 

  int n;cin>>n;
  vector<int> v(n);
  for(auto &x:v){
    cin>>x;
  }
  int curr=0,maxTill=INT_MIN;
  for(auto &x:v){
    curr +=x;

    maxTill = max(maxTill,curr);
    if(curr<0)curr = 0;
  }
  cout<<maxTill<<endl;
  return 0;
}