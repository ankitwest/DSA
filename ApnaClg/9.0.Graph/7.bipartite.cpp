#include <bits/stdc++.h>
using namespace std;
#define int long long


vector<vector<int>> adj;
vector<bool> vis;
vector<int> col;
bool bipart;

//Answer may be not correct
void color(int u, int curr){
	if(col[u] != -1 and col[u] != curr){
		bipart = false;
		return;
	}

	col[u] = curr;
	if(vis[u])
		return ;
	vis[u]= true;

	for(auto i : adj[u])
		if(curr==1) col[i]=0;
		if(curr==0) col[u]=1;
}


int32_t main(){
	 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    #endif

	int n,m;cin>>n>>m;
	adj = vector<vector<int>> (n);
	vis = vector<bool>(n,false);
	col = vector<int>(n,-1);

	for(int i=0; i<m;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);

	}
	for(int i=0;i<n;i++){
		if(!vis[i])
			col[i] =0;  //col(i,0);
	}

	if(bipart)
		cout<<"Graph is bipart";
	else
		cout<<" Graph is not Bipartite";


}

