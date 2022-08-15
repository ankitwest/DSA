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
#define int long long
const int mod  =  1e9+7,maxA=500;

int dp[maxA+1][maxA+1];
/*______________________________________________________*/

int32_t main(){
 
    int a;lscn(a);
    int b;lscn(b);

     for(int i=1;i<a;i++){
        dp[i][0] = i;
      }
      for(int j=1;j<b;j++){
        dp[0][j] = j;
      }

    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i^j)
                dp[i][j]= 1e9;
            
            for(int k=1;k<i;k++)
                dp[i][j] = min(dp[i][j] , dp[k][j] + dp[i-k][j] + 1);
            
            for(int k=1;k<j;k++)
                dp[i][j] = min(dp[i][j] , dp[i][k] + dp[i][j-k] + 1);
        }
    }


cout<<dp[a][b]<<endl;
    return 0;
}