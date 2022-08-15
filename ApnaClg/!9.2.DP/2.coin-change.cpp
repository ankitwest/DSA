#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+2;
int dp[N][N];

// If dp is not used then , It wil fail for larger test cases.

int coinChange(vector<int> &coins,int n,int amt){
	if(amt==0) return 1;
	if(amt<0)  return 0;

    if(n==0) return 0;
	if(n<0) return 0;

    if(dp[n][amt]!=-1)
        return dp[n][amt];

	dp[n][amt] = coinChange(coins,n,amt-coins[n-1]) + coinChange(coins,n-1,amt);

    return dp[n][amt];
}


int32_t main(){
      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    for(int i = 0 ; i < N ; i++)
    for(int j = 0 ; j < N ; j++)
        dp[i][j] = -1;

    int n; cin>>n;

    vector<int> coins(n);
    for(int i = 0 ; i < n ; i++)
    	cin>>coins[i];

    int amt; cin>>amt;

    cout<<coinChange(coins,n,amt)<<endl;
    return 0;
}