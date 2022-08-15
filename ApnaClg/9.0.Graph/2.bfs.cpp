#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5+3;
vector<int> adj[N];
bool vis[N];

int32_t main(){

	   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    // for(int i=0;i<N;i++){
    //   vis[i]=0; 
    // }

    memset(vis,false,sizeof(vis));
    int n,m;
    cin>>n>>m;

    int x,y;

    for(int i=0;i<m;i++){
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    vis[1] = true;

    while(!q.empty())
    {
      int node = q.front();    q.pop();
      cout<<node<<endl;

      // vector<int> :: iterator it;
      // for(it=adj[node].begin();it!=adj[node].end();it++)
      // {
      //   if(!vis[*it])
      //     vis[*it]=1,q.push(*it);

        for(auto child: adj[node]){
          if(!vis[child])
            vis[child]=true,q.push(child);
        }
      }
    //}


    return 0;
  }





