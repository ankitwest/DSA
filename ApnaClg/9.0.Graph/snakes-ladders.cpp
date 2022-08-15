#include <bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 1e9;

int32_t main(){

	   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    #endif

	int ladder,snakes;cin>>ladder;
	map<int,int> lad;
	map<int,int> sna;
	for(int i=0;i<ladder;i++){
		int u,v;cin>>u>>v;
		lad[u]=v;
	}
	cin>>snakes;
	for(int i=0;i<snakes;i++){
		int u,v;cin>>u>>v;
		sna[u]=v;
	}

	vector<int> vis(101,0);

	int moves=0; bool found = false;
	queue<int> q;
	q.push(1);
	vis[1]=1;
	while(!q.empty() and !found)
	{
		int sz = q.size();

		while(sz--)
		{
		int curr=q.front(); q.pop();

		for(int dice=1;dice<=6;dice++)
			{
			// if(curr+dice == 100)
			// 	found =true;
			if(curr+dice<=100 and !vis[curr+dice] and lad[curr+dice]){
				vis[lad[curr+dice]] = true;
				vis[curr+dice]=true;
				if(lad[curr+dice] == 100)
					{found = true;break;}
				q.push(lad[curr+dice]);
			   }
		else if(curr+dice<=100 and !vis[curr+dice] and sna[curr+dice]){
			vis[sna[curr+dice]] = true;
			vis[curr+dice]=true;
			if(sna[curr+dice] == 100)
				{found=true;break;}
				q.push(sna[curr+dice]);
		       }
		else if(curr+dice<=100 and !vis[curr+dice] and !sna[curr+dice] and !lad[curr+dice] ){
			vis[curr+dice] =true;
			if(curr+dice == 100)
				{found=true;break;}
			q.push(curr+dice);
 		       }

			}//for
		}//while sz
	moves++;
	}//while
		if(found) cout<<moves;
		else cout<<-1;
}




