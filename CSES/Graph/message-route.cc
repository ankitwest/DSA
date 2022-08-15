#include <bits/stdc++.h>
using namespace std;

#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >

#define precision(n) fixed<<setprecision(n)
#define setprecision(n,ans) cout << fixed << setprecision(9) << ans<<endl

#define setbits(x) __builtin_popcountll(x)

int gcd(int a, int b){ return b?gcd(b,a%b):a; }
int lcm(int a, int b){  return a/gcd(a, b)*b; }

#define rep(i,a,n)      for(int i = a ; i < n ; i++)
#define REP(i,a,n)      for(int i = a ; i <= n ; i++)
#define rev(i,a)            for(int i = a - 1 ; i>=0 ; i--) 
#define fill(a, x)  memset(a, x, sizeof(a))      //for array
#define all(x)      x.begin(),x.end()
#define lscn(n) scanf("%lld", &n)
#define scn(n) scanf("%d", &n)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define pii                  pair<int, int>
#define mii                  map<int , int>
#define vi                   vector<int>
#define vpi                  vector<pii>

#define ln cout<<"\n";
#define debug0(x) cout<<(x)<<" "
#define debug(x) cout<<(x)<<endl
#define debug2(x,y) cout<<(x)<<" "<<(y)<<endl
#define cy cout<<"YES"<<endl;
#define cn cout<<"NO"<<endl;

#define int long long
const int mod  =  1e9+7;
const int maxN = 100005;
vi adj[maxN];
bool vis[maxN];
int dist[maxN];
int par[maxN];

int n; int m;
bool bfs(){
	dist[1]=1;
	vis[1]=1;
	queue<int> q;
	q.push(1);

	while(!q.empty()){
		int curr = q.front(); q.pop();

		if(curr == n ) return true;

		for(auto child : adj[curr])
			if(!vis[child]){
			dist[child] = dist[curr]+1;
			vis[child]=1;  par[child]=curr;// storing the parent;
			q.push(child);
		}
	   

	}
	return false;

			
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

       cin>>n;
        cin>>m;
        int a,b;
     
        REP(i,1,m) cin>>a>>b, adj[a].pb(b) , adj[b].pb(a);

        bool f = bfs();
        if(f){
        	int dis = dist[n];
        	   vi res;
        	   par[1]=0;
        	   int path = n;
        	   while(path!=0)
        	   	res.pb(path) , path = par[path];

        	   reverse(all(res));
        	   cout<<dis<<endl;
        	   for(auto x:res)
        	   	cout<<x<<" ";


        } else{
        	cout<<"IMPOSSIBLE"<<endl;
        }

    return 0;
}





