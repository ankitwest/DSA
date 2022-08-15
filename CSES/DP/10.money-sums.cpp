#include <bits/stdc++.h>
using namespace std;

#define rep(i,n,b) for(int i=n;i<b;++i)
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
const int mod  =  1e9+7, maxN=100 , maxX=1e6;

int dp[maxX+1];
/*______________________________________________________*/

int32_t main(){
        
    int n;lscn(n);
    int arr[n];
    for(int i=0;i<n;i++)
        lscn(arr[i]);

    dp[0]=1;
    for(int j=0; j<n;j++)
        for(int i=maxX;i ; i--)
            if(i>=arr[j])
                dp[i] = dp[i] | dp[i-arr[j]];


    vector<int> ans;
    for(int i=1; i<= 1e6; i++)
        if(dp[i])
            ans.push_back(i);

        cout<<ans.size()<<endl;
        for(int a : ans)
            cout<<a<<" ";


    return 0;
}