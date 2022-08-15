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
const int mod  =  1e9+7,maxN=1e5 ,maxM=100;

int dp[maxN][maxM];

// Big code
/*______________________________________________________*/

int32_t main(){
           
    int n;lscn(n);int m;lscn(m);
  
    int a[n];
    for(int i=0;i<n;i++)
      		 cin>>a[i],--a[i];


   for(int i=0;i<n;i++){
    if(i){
       for(int j=0;j<m;j++){
            dp[i][j] = dp[i-1][j];
            if(j)
                dp[i][j] += dp[i-1][j-1];
            if(j<m-1)
                dp[i][j] += dp[i-1][j+1];
            dp[i][j]%=mod;
        }
    } else {
        for(int j=0;j<m;j++){
            dp[0][j] = 1;
        }
    }
        if(~a[i])
            for(int j=0;j<m;j++){
                if(j^a[i])
                    dp[i][j]=0;
           }
        }

        int ans =0;
        for(int i=0;i<m;i++)
            ans += dp[n-1][i];

        cout<<(ans%mod)<<endl;
    
    return 0;
}