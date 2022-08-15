#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)
#define lpri(n) printf("%lld ", n)
#define lscn(n) scanf("%lld", &n)
#define pri(n) printf("%d ", n)
#define scn(n) scanf("%d", &n)

#define inf INT_MAX
#define ninf INT_MIN
const int MOD  =  1e9+7;

#define ln cout<<"\n";
#define debug0(x) cout<<(x)<<" "
#define debug(x) cout<<(x)<<endl
#define debug2(x,y) cout<<(x)<<" "<<(y)<<endl

#define ll long long

const int mxN=1e6;
ll dp[mxN+1];

ll mod_add(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a + b) % MOD) + MOD) % MOD;}

ll add(ll a , ll b){
	ll ans = a+b;
	if(ans >= MOD) return ans%MOD;
		return ans;
}


int32_t main(){
	 
    dp[0]=1;
        ll n;  lscn(n); 
        for(int i=1; i<=n; i++){
        	for(int j=1;j<=min(i,6);j++){
        		dp[i] = add(dp[i],dp[i-j]);
        	}
        }
      debug(dp[n]);

    return 0;
}
