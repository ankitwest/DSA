//K-OS WITH THE OCDE

#include <bits/stdc++.h>
using namespace std;

#define scn(n) scanf("%d", &n)
#define lscn(n) scanf("%lld", &n)

#define rep(i, a, b) for(int i=(int)(a); i<(int)(b); i++)
#define test int t;cin>>t;while(t--)
#define lcm(m,n)             (m*n)/__gcd(m,n)

const int inf = INT_MAX;
const int ninf = INT_MIN;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define all(x)      x.begin(),x.end()
#define sz(s) s.size()   //for vector as well as string   int len=sz(s)
#define fill(a, x)  memset(a, x, sizeof(a))
#define szo(arr) sizeof(arr)/sizeof(arr[0]);    //int arrSize = szo(arr)

#define en  "\n"
#define ln cout<<"\n"

#define MOD                   1000000007
#define pi                   3.14159265358979323846
#define ll                   long long
#define ld                    long double
#define dd                    double
#define ull                   unsigned long long

#define pii                  pair<int, int>
#define pll                  pair<ll, ll>
#define mii                                  map<int , int>
#define mll                                  map<ll, ll>

#define vi                   vector<int>
#define vl                   vector<ll>
#define vpi                  vector<pii>
#define vpl                  vector<pll>

#define debug0(x) cout<<(x)<<" "
#define debug(x) cout<<(x)<<endl
#define debug2(x,y) cout<<(x)<<" "<<(y)<<endl
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl
#define debug4(x,y,z,w) cout<<x<<" "<<y<<" "<<z<<" "<<w<<endl
#define debug5(x,y,z,w,s) cout<<x<<" "<<y<<" "<<z<<" "<<w<<" "<<s<<endl

// #define N 100100
// #define int long long
int n=100100; 
list<int>graph[n];
int ans;
int red,blue;
char colors[n];

pair<int, int> dfs(int src, int parent=-1)
{
    int r= (colors[i] =='A' );
    int b= (colors[i] =='B');
    for(auto neighbour : graph[src])
    {
        if(neighbour!=parent){
            pair<int, int> result= dfs(neighbour,parent); 
             
            ans += ( result.first==red) and (result.second==0);
             ans += ( result.first==0) and (result.second==blue);

             r+=result.first;
             b+=result.second;
        }
    }
    return {r,b};
}

void solve()
{
    cin>>n;
    
    red=0; blue=0;
    rep(i,0,n)
    {
        char color;
        cin>>color;
        colors[i]=color;
        if(color== 'A') red+=1;
        if(color== 'B') blue+=1;        

    }
    rep(i,1,n)
    {
        int u,v;
        cin>>u>>v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }

    ans=0;
    dfs(0);
    cout<<ans<<endl; 

}

int main()
{
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    //TEST
    solve();
}
