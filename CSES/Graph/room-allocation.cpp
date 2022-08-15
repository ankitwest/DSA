#include <bits/stdc++.h>
using namespace std;

#define ll long long
// #define ar array
#define lpri(n) printf("%lld ", n)
#define lscn(n) scanf("%lld", &n)

int main(){
	ll n;lscn(n);
	ll arr[n];
	ll sum=0;
	for(ll i=0;i<n;i++){
		lscn(arr[i]);
		sum+=arr[i];
	}
	sort(arr,arr+n);

	lpri(max(sum,2ll*(arr[n-1])));

}