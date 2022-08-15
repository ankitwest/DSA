#include <bits/stdc++.h>
using namespace std;

// #define vvi  vector<vector<int>> v
#define vi           vector<int>

int main(){
       ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
   vector<vector<int>> v;
    //vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int start,end;
        cin>>start>>end;
        
        v.push_back({start,end});
    }
    sort(v.begin(),v.end(),[&](vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    });

    int take = 1;
    int end = v[0][1];

    for(int i=1;i<n;i++){
        if(v[i][0] >= end){
            take++;
            end = v[i][1];
        }
    }

    cout<<take<<endl;
    return 0;
}