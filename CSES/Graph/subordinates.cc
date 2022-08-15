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
const int maxN  =  2e5+1;

vector<int> tree[200001];
int n;
vector<int> ans;
int vis[maxN];

void dfs(int src){

	int subordinates = 0;
	vis[src]=1;

	for(auto child: tree[src]){
		if(!vis[child]){
			dfs(child);
			subordinates += 1 + ans[child];
		}
	}
	ans[src] = subordinates;
}
      
int32_t main(){
	     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	    // freopen("input.txt", "r", stdin);

	    cin>>n;
	    ans.resize(n+1);
	    REP(i,2,n){
	    	int x;cin>>x; 
	    	tree[x].pb(i);
	    	tree[i].pb(x);
	    }


	    dfs(1);

	    REP(i,1,n){
	    	debug0(ans[i]);
	    }

}