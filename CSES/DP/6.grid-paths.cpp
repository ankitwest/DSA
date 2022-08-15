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
const int mod  =  1e9+7, maxN=1000;

int dp[maxN][maxN];
string s[maxN];


/*______________________________________________________*/

int32_t main(){
        
    int n;lscn(n);
  

    for(int i=0;i<n;i++)
      		 cin>>s[i];

    dp[0][0]=1;
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
            if(i)
                dp[i][j] +=  dp[i-1][j];
            if(j)
                dp[i][j] +=  dp[i][j-1];
            dp[i][j]%=mod;
            if(s[i][j]=='*')
            	dp[i][j]=0;

        }
    }
    
    cout<<dp[n-1][n-1];

    return 0;
}