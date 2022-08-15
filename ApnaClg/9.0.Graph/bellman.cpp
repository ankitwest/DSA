#include <bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 1e9;

//wrong answer

int32_t main(){
	  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    #endif

	int n,m;cin>>n>>m;
	vector<vector<int>> edges;
	for(int i =0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edges.push_back({u,v,w});

	}
	int src;cin>>src;
	vector<int> dist(n,inf);
	dist[src] =0;

	for(int iter =0;iter<n-1;iter++){
		for(auto e : edges){
			int u = e[0];
			int v = e[1];
			int w = e[2];
			dist[v] = min(dist[v],w+ dist[u]);

	}
}

for(auto i : dist){
	cout<<dist[i]<<" ";
}
cout<<endl;	
}