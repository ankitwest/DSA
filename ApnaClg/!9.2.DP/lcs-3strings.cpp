#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e3+2;

int dp[200][200][200];

int lcs(string &s1, string &s2, string &s3 , int n,int m ,int o){  //O(1) pass by refenence
    if(n == 0 || m == 0 || o==0)
        return 0;

    if(dp[n][m][o] != -1)
        return dp[n][m][o];

    if(s1[n-1] == s2[m-1] and s3[o-1] == s2[m-1])
        dp[n][m][o] = 1 + lcs(s1,s2,s3,n-1,m-1,o-1);
    // else
    // {
    //     dp[n][m][o] = max(lcs(s1,s2,n,m-1) , lcs(s1,s2,n-1,m));
    // }
    int l = lcs(s1,s2,s3,n-1,m,o);
    int r = lcs(s1,s2,s3,n,m-1,o);
    int p = lcs(s1,s2,s3,n,m,o-1);

    return max({l,r,p});
}

int32_t main(){

	  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    #endif

    // for(int i = 0; i <N;i++){
    //     for(int j=0;j<N;j++){
    //         dp[i][j]  -1;        }
    // }
    memset(dp,-1,sizeof(dp));
    
     string s1,s2,s3;
     cin >> s1 >> s2 >>s3;

     int n = s1.size(),m=s2.size(),o=s3.size();

     cout<<lcs(s1,s2,s3,n,m,o)<<endl;

     return 0;
    }