#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lpri(n) printf("%lld ", n)
#define lscn(n) scanf("%lld", &n)
#define scn(n) scanf("%d", &n)
#define debug0(x) cout<<x<<" "
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl
#define vvi vector<vector<ll>>
// #define mod 20000
const int mod = 2e5;

int main(){
	
	ll n;lscn(n);
	ll arr[mod];
	ll near[mod];

	for(ll i=0; i<n;i++){
		lscn(arr[i]);
		near[i]=i-1;
		while(~near[i] and arr[near[i]] >= arr[i])
			near[i]= near[near[i]];
		debug0(near[i]+1);
	}


return 0;
}