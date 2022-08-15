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
const int mod  =  1e9+7, maxN = 1e3;

string s[maxN];
int n,m;
// ________________________________________________________________

bool inside(int i,int j){
    return (i>=0 and i<n and j>=0 and j<m and s[i][j]=='.');
}

void dfs(int i,int j){
    s[i][j]='#';
    if(inside(i-1,j))
        dfs(i-1,j);
    if(inside(i+1,j))
        dfs(i+1,j);
    if(inside(i,j-1))
        dfs(i,j-1);
    if(inside(i,j+1))
        dfs(i,j+1);
}
int32_t main(){
   
    cin>>n>>m;
    rep(i,0,n)
    cin>>s[i];

    int ans=0;

    rep(i,0,n){
        rep(j,0,m){
            if(inside(i,j)){
                dfs(i,j); ans++;
            }
        }
    }

    debug(ans);
    return 0;
}

