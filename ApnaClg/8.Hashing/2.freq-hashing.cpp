#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i = a; i < n; i++)
#define pii                  pair<int,int>
#define vpi                  vector<pii>

//Why does it give wrong
int32_t main(){
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    map<int,int> freq;
    int presentSize = freq.size();
    for(auto &x:a){
    int presentSize = freq.size();
  
        if(presentSize == k and freq[x]==0)
            break;

        freq[x]++;
    }

    vector<pii> ans;
    for(auto &i:freq){
        if(i.second != 0)
            ans.push_back(make_pair(i.second,i.first));
        
    }

    sort(ans.begin(), ans.end(),greater<pair<int,int>>());

     for(auto &z:ans){
        cout<<z.second << " "<<z.first<<endl;
    }

    // vpi :: iterator it;
    // for(it=ans.begin(); it!=ans.end();it++){
    //     cout<<it->second<<' '<<it->first<<endl;
    // }

}