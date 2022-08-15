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
#define fill(arr, x)  memset(arr, x, sizeof(arr))      //for array
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

// #define int long long
const int mod  =  1e9+7;
const int maxN = 100005;

vi adj[maxN];
bool vis[maxN];
int color[maxN];

bool dfs(int node,int c){
	vis[node] = 1;
	color[node] = c;

	for(auto child: adj[node]){
		if(!vis[child]){
			bool res =dfs(child,c^1);
			if(res==false) return false;
		} else{
			if(color[node]==color[child])
				return false;
		}
	}	
	return true;
}
bool bfs(int source){
	queue<int> q;
	q.push(source);
	vis[source] = 1;
	color[source] = 1;

	while(!q.empty()){
		int node = q.front(); q.pop();

		for(auto child : adj[node]){
			if(!vis[child]){
				q.push(child);
				vis[child]=1;
				color[child] = color[node]^1;
			} else{
				if(color[node]==color[child])
					return false;
			}
		}
	}
	return true;
}
int main(){
	    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	    // freopen("input.txt", "r", stdin);
	    int n,m;    int a,b;
	    cin>>n>>m;
	
	    REP(i,1,m) cin>>a>>b , adj[a].pb(b) , adj[b].pb(a);

	    bool flag = true;
	    REP(i,1,n){
	    	if(!vis[i]){
    		    		flag = dfs(i,0);
    		    		// flag = bfs(i);
	    		    	if(flag==false) break;
	    		    }
	    }

	    if(flag==false) 
	    	cout<<"IMPOSSIBLE";
	    else
	    	REP(i,1,n) debug0(color[i]+1);

	    ln;

}
