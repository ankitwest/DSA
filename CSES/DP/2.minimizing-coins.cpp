amt#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)
#define lpri(n) printf("%lld ", n)
#define lscn(n) scanf("%lld", &n)
#define pri(n) printf("%d ", n)
#define scn(n) scanf("%d", &n)

#define inf INT_MAX
#define ninf INT_MIN
const int mod  =  1e9+7;

#define ln cout<<"\n";
#define debug0(x) cout<<(x)<<" "
#define debug(x) cout<<(x)<<endl
#define debug2(x,y) cout<<(x)<<" "<<(y)<<endl

#define int long long

const int mxN=100,mxX=1e6;
int dp[mxX+1];

int32_t main(){
       
        int n;  lscn(n); int x; lscn(x);
         int arr[n];
        for(int i=0;i<n;i++){
            lscn(arr[i]);
        }
        
        for(int amt=1; amt<=x; amt++){
            dp[amt]=mod;
        	for(int j=0;j<n;j++){
                if(amt>=arr[j])
        		dp[amt] = min(dp[amt],dp[amt-arr[j]]+1);        	
            }
        }
      if(dp[x]>=1e9) debug(-1);
      else debug(dp[x]);

    return 0;
}
