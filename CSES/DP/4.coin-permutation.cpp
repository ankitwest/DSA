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
const int mod  =  1e9+7,maxN=100,maxX=1e6;

int dp[maxX+1];

ll add(ll a , ll b){
    ll ans = a+b;
    if(ans >= MOD) return ans%MOD;
        return ans;
}
/*______________________________________________________*/

int32_t main(){
    
    int n,x;lscn(n);lscn(x);
    int arr[n];
    for(int i=0;i<n;i++)
        lscn(arr[i]);

    dp[0]=1;
   for(int amt=1;amt<=x;amt++){
       for(int i=0;i<n;i++){
            if(amt>=arr[i])
                dp[amt] = add(dp[amt] , dp[amt-arr[i]]);
        }
    }
    debug(dp[x]);

    

    return 0;
}