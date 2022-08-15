#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5+3;
vector<int> adj[N];
bool vis[N];

void dfs(int node){ 
  //preorder
 
    vis[node]=true;
    cout<<node<<" ";

    //inorder
    for(auto neigh: adj[node]){
      if(!vis[neigh]){
        vis[neigh]=true;
       //cout<<neigh<<" ";
      dfs(neigh);
         }
      }
      //postorder

    //cout<<node<<" ";

}
int32_t main(){

	   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n,m;cin>>n>>m;
    memset(vis,false,sizeof(vis));

    int x,y;
    for(int i=0;i<m;i++){
      cin>>x>>y; 
      adj[x].push_back(y);
      adj[y].push_back(x);

    }

    dfs(1);


      return 0;
}