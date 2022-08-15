#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+2 , MOD = 1e9+7;
#define rep(i,a,n)       for(int i = a ; i < n ; i++)

#define vi       vector<int>
#define vvi   vector<vector<int>>

void combination(int &target , vector<int> &coins){
           vector<int> dp(target+1,0);
         dp[0]=1;  // zero ko pay  karne ka 1 tarika

    for(auto coin : coins){
        for(int amt = 1 ; amt <= target ; amt++){
                if(amt>=coin)
                dp[amt] += dp[amt-coin];
            }
      }
           cout<<dp[target]<<endl;

        // for(int amt = 0 ; amt <= target ; amt++){
        //     cout<<dp[amt]<<" ";
        // }
        return ;
}

void permutation(int &target , vector<int> &coins){
           vector<int> dpP(target+1,0);
         dpP[0]=1;  // zero ko pay  karne ka 1 tarika

        for(int amt = 1 ; amt <= target ; amt++){
            for(auto coin : coins){
                if(amt>=coin)
                dpP[amt] += dpP[amt-coin];
            }
         }
           cout<<dpP[target]<<endl;

        // for(int amt = 0 ; amt <= target ; amt++){
        //     cout<<dpP[amt]<<" ";
        // }
        return ;
}



int32_t main(){
      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n; cin>>n;
     vector<int> coins(n);
    for(int i = 0 ; i < n ; i++)
    	cin>>coins[i];

    int target;  cin>>target;


    combination(target ,  coins);
  permutation(target , coins);

    return 0;
}

    // for(int i = 0 ; i < coins.size() ; i++){
    //     for(int amt = 1 ; amt <= target ; amt++){
    //         if(amt>=coins[i])
    //          dp[amt] += dp[amt-coins[i]];
    //      }
    // }


// vector<vector<int>> dp(n,vector<int> (m,0));


