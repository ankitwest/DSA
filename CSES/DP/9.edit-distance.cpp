#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)
#define lpri(n) printf("%lld ", n)
#define lscn(n) scanf("%lld", &n)
#define pri(n) printf("%d ", n)
#define scn(n) scanf("%d", &n)

#define ln cout<<"\n";
#define debug0(x) cout<<(x)<<" "
#define debug(x) cout<<(x)<<endl
#define debug2(x,y) cout<<(x)<<" "<<(y)<<endl

#define inf INT_MAX
#define ninf INT_MIN
#define ll long long
const int mod  =  1e9+7,maxN=5e3 ,maxM=5e3;

int dp[maxN+1][maxM+1];


// Exact same code but still wrong answer
/*______________________________________________________*/

int main(){
  
      string s,t;
      cin>>s>>t;

      for(int i=1;i<s.size();i++){
        dp[i][0] = i;
      }
      for(int j=1;j<t.size();j++){
        dp[0][j] = j;
      }

        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                dp[i][j]=1e9;
                if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1];

                dp[i][j] = min({dp[i][j]  , dp[i-1][j-1] + 1, dp[i-1][j] + 1, dp[i][j-1] + 1});
            }
        }

      cout<<dp[s.size()][t.size()]<<endl;

    
    return 0;
}