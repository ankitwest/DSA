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

int _rank[maxN];
int par[maxN];

int findRoot(int a){
	if(par[a] == -1) return a;

	return par[a] = findRoot(par[a]);
}

int merge(int a , int b){
	a = findRoot(a);
	b = findRoot(b);

	if(_rank[a] < _rank[b]) swap(a , b);

	par[b] = a;
	_rank[a] += _rank[b];

	return _rank[a];
}

signed main(){
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  // freopen("input.txt", "r", stdin);
	int n; int m;
	int a,b;
  cin>>n>>m;
  REP(i,1,n)  _rank[i]=1 , par[i] = -1;

  int cc =n;
  int mx = 1;

  REP(i,1,m){
  	cin>>a>>b;
  	if(findRoot(a) != findRoot(b))  mx = max(mx, merge(a,b)) , cc--;
  	debug2(cc,mx);
  }
   return 0;
}






