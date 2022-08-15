#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lpri(n) printf("%lld ", n)
#define lscn(n) scanf("%lld", &n)
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl
#define vvi vector<vector<int>>

int main(){
	 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
	ll n;lscn(n);
	ll x;lscn(x);
	vector<vector<ll>> arr(n, vector<ll>(2,0));
	for(ll i=0;i<n;i++){
		lscn(arr[i][0]); arr[i][1]=i;
	}
	sort(arr.begin(),arr.end());
	for(ll i=0;i<n;i++){
		ll x2 = x-arr[i][0];
		for(ll j=i+1,k=n-1;j<k;j++){
			while(j<k and arr[j][0]+arr[k][0]>x2){
				k--;
			}
			if(j<k and arr[j][0]+arr[k][0]==x2){
				debug3(arr[i][1]+1,arr[j][1]+1,arr[k][1]+1);
				return 0;
			}
			
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
return 0;
}