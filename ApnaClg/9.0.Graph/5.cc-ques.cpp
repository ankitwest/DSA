#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<bool> vis;
vector<vector<int>> adj;

int get_comp(int idx){
	if(vis[idx])
		return 0;
	vis[idx] = true;

	int ans = 1;
	for(auto i: adj[idx]){
		if(!vis[i]){
			ans += get_comp(i);
			vis[i] = true;
		}
	}
	return ans;
}
int32_t main(){
		  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    #endif

    int n,m;
    cin>>n>>m;
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n,0);

   	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> components;
	for(int i=0;i<n;i++){
		if(!vis[i]){
			components.push_back(get_comp(i));
		}

	}
	// for(auto i : components){
	// 		cout<<i<<" ";
	// 	}
		long long ans = 0;
		for(auto i :components){
			ans += i*(n-i);
		}
		cout<<(ans /2);
}




