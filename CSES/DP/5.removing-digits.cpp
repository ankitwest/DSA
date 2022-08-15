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
const int mod  =  1e9+7,maxN=1e6;

int dp[maxN+1];
/*______________________________________________________*/

int32_t main(){
   
    int n;lscn(n);

   for(int i=1;i<=n;i++){
    dp[i]=1e9;
    int no=i;
        while(no){
            dp[i]= min(dp[i],dp[i-no%10]+1);
            no/=10;
        }
    }
    debug(dp[n]);

    

    return 0;
}