#include <bits/stdc++.h>
using namespace std;
#define int long long

//incomplete
const int N = 1e5+3,INF= 1e9;
vector<int> adj[N];

int cost=0;
vector<int> dist[N],parent[N];
vector<int> vis[N];

void primsMST(int source){

	for(int i=1;i<n;i++){
		dist[i] = INF;
	}
	set<vector<int>> s;
	dist[source] = 0;
	s.insert({0,source});

	while(!s.empty()){
		auto x = *(s.begin());
		s.erase(x);
		vis[x[1]] = true;
		int u = x[1];
		int v = parent[x[1]];
		int w = x[0];
		cout<<u<<" "<<" "<<w<<"\n";
		cost += w;
		for(auto it : adj[x[1]]){
			if(vis[it[0]])
				continue;
			if(dist[it[0]] > it[1]){

			}
		}
	}
}


int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    #endif
int n,m;cin>>n>>m;
for(int i=0;i<m;i++){
	int u,v,w;
	cin>>u>>v>>w;
	adj[u].push_back({v,w});
	adj[v].push_back({u,w});

}
primsMST(0);
cout<<cost<<endl;

}