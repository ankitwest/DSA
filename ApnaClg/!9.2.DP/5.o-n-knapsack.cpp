#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){

	  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    #endif

    int n=5, W = 11;
    vector<int> wt = {3,2,4,5,1};
    vector<int> val = {4,3,5,6,1};
    vector<int> dp(W+1,0);

    for(int j=0;j<=W;j++){
        for(int i=0;i<n;i++){
            if(j-wt[i] >= 0)
            dp[j] = max(dp[j], val[i] + dp[j- wt[i]]);
        }
    }

    cout<<dp[W]<<endl;

 return 0;
}