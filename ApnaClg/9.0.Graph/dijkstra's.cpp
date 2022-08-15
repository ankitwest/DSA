#include <bits/stdc++.h>
using namespace std;
#define int long long

//incomplete

const int inf = 1e7;
int32_t main(){
	int n,m; cin>>n>>m;
	vector<int> dist(n+1,inf);
	vector<vector<pair<int,int>>> graph(n+1);

	for(int i=0;i<m;i++){
		int u,v,w; cin>>u,v,w;
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});

	}
	int src;cin>>src;
	dist[src]=0;

	set<pair<int,int>> s;
	s.insert({0,source});
	while(!s.empty()){
		auto x = *(s.begin());
		s.erase(x);

		for(auto i : graph[x.second])
			if(dist[it.first] > dist[])
	}
}