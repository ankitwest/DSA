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
const int mod  =  1e9+7,maxN=1000,maxX=1e5;

int dp[maxX+1];
/*______________________________________________________*/

int32_t main(){
      
    int n;lscn(n);
    int x;lscn(x);

    int h[n];int s[n];

   for(int i=0;i<n;i++)
        lscn(h[i]);
      for(int i=0;i<n;i++)
        lscn(s[i]);

    for(int i=0;i<n;i++){
        for(int j=x;j>=h[i];j--){
            dp[j] = max(dp[j] , dp[j-h[i]] + s[i]);
        }
    }
cout<<dp[x]<<endl;;
    

    

    return 0;
}