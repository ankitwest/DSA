#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2 , MOD = 1e9+7;
#define rep(i,a,n)       for(int i = a ; i < n ; i++)
int dp[N]; 

int minSquare(int n){
    if(n == 1 or n==2 or n==3 or n==0)
    return n;

    int ans = MOD;
    for(int i =1 ; i*i<=n; i++){
        int afterSubtraction = n-i*i;
        ans = min(ans , 1+ minSquare(afterSubtraction));
    }
    return ans;
}
int minSquareDP(int n){
    if(n == 1 or n==2 or n==3 or n==0)
    return n;

    if(dp[n]!=MOD)
        return dp[n];

    for(int i=1 ; i*i<=n; i++){
        //int afterSubtraction = n-i*i;
        dp[n] = min(dp[n] , 1+ minSquare(n-i*i));
    }
    return dp[n];
}
int main(){
       ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    for(int i = 0 ; i <= N ; i++)
        dp[i] = MOD;
    int n;
    cin>>n;
    


    cout<<minSquareDP(n)<<endl;
    return 0;
}