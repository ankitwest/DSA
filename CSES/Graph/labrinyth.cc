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
const int maxN = 1001;

// vi adj[maxN];
char arr[maxN][maxN];
char br[maxN][maxN];
bool vis[maxN][maxN];
// int color[maxN];

vector<char> path;

int n,m;

bool isValid(int x,int y){
	if(x<0 || x>n or y<0 || y>m) return false; //x<1 or y<1
	if(arr[x][y]=='#' or vis[x][y]==true) return false;

	return true;
}
bool bfs(int x,int y){
	queue<pair<int,int>> q;
	q.push({x,y});
	vis[x][y]=true;

	while(!q.empty()){
		auto p = q.front();q.pop();
		int a = p.ff ; int b = p.ss;

		if(arr[a][b]=='B'){
			while(1){
				path.push_back(br[a][b]);

				if(path.back()=='L') b++;
				if(path.back()=='R') b--;
				if(path.back()=='U') a++;
				if(path.back()=='D') a--;

				if(a==x and b==y) break;

			}
			return true;
		}
		if(isValid(a,b-1)) br[a][b-1] = 'L' , q.push({a,b-1}) , vis[a][b-1] =1;
		if(isValid(a,b+1)) br[a][b+1] = 'R' , q.push({a,b+1}) , vis[a][b+1] =1;
		if(isValid(a-1,b)) br[a-1][b] = 'U' , q.push({a-1,b}) , vis[a-1][b] =1;
		if(isValid(a+1,b)) br[a+1][b] = 'D' , q.push({a+1,b}) , vis[a+1][b] =1;

		
	}
	return false;
}

int main(){
	    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	    // freopen("input.txt", "r", stdin);
	    
	    cin>>n>>m;
	      int x,y;
	
	    REP(i,1,n){
	    	REP(j,1,m){
	    		cin>>arr[i][j];
	    		if(arr[i][j]=='A') x=i,y=j;
	    	}
	    }

	    if(bfs(x,y)){
	    	cy;
	    	debug(path.size());
	    	while(path.size() > 0) 
	    		cout<<path.back() , path.pop_back();

	    } else{
	    	cn;
	    }
	


}
