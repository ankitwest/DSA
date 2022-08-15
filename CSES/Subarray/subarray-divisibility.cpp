#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lpri(n) printf("%lld ", n)
#define lscn(n) scanf("%lld", &n)
#define scn(n) scanf("%d", &n)
#define debug0(x) cout<<x<<" "
const int mod = 2e5;

int main(){
	
	ll n;lscn(n); // ll target;lscn(target);
	
	ll arr[mod];
	map<ll,ll> mp;
	mp[0]++;

	ll presum=0;ll ans =0;
	for(ll i=0; i<n;i++){
		cin>>arr[i];
		presum = ((presum + arr[i])%n+n)%n;
		ans += mp[presum];
		mp[presum]++;
	}
	cout<<ans<<endl;

return 0;
}