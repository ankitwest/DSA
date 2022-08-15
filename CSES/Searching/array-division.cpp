#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lpri(n) printf("%lld ", n)
#define lscn(n) scanf("%lld", &n)
#define scn(n) scanf("%d", &n)
#define debug0(x) cout<<x<<" "
const int mod = 2e5;  //2147483647

//Not Right Answer and also not understood
int main(){
	
	ll n;lscn(n); ll k;lscn(k);
	ll arr[mod];

	for(ll i=0; i<n;i++){
		cin>>arr[i];
	}

		ll lb=*max_element(arr,arr+n); ll ub=1e10;
		while(lb<ub){
			ll mid = (lb+ub)/2;
			ll c=0;
			ll ls=0;
			for(ll i=0;i<n;i++){
				if(ls+arr[i]>mid){
					c++;
					ls=0;
				}
				ls+=arr[i];
			}
			c++;
			if(c>k) lb=mid+1;
			else ub=mid;
		}
	lpri(lb);
		
	

return 0;
}




