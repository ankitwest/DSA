#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5+3;

bool isCycle(int src,vector<vector<int>> &adj,vector<bool> &visited , int parent){
	 visited[src] = true;
	 for(auto i : adj[src]){
	 	if(i!=parent){
	 		if(visited[i])
	 			return true;
	 		if(!visited[i] and isCycle(i,adj,visited,src)){
	 			return true;
	 		}
	 	}
	 }
	 return false;
}

int32_t main(){
	  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    #endif

	int n,m; cin>>n>>m;
	vector<vector<int>> adj(n);

	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bool cycle = false;
	vector<bool> visited(n,false);

	for(int i=0;i<n;i++){
		if(!visited[i] and isCycle(i,adj,visited,-1)){
			cycle = true;
		}
	}

	if(cycle)
		cout<<"Cycle is present";
	else
		cout<<"Cycle is not present";
}