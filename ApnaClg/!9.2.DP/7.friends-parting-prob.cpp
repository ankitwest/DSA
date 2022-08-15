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
    vector<int> dp(n+1,0);
    dp[0] =1;
    dp[1] =1;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + (i-1)*dp[i-2];
    }

    cout<<dp[n]<<endl;

return 0;
}