#include <bits/stdc++.h>
using namespace std;
#define  int long long

const int N =1e5+2,MOD = 1e9+7;

int powerIterative(int a,int n){
	a=a%MOD;
	int ans=1;
	while(n>0){
		if(n&1)
			ans = (ans*a)%MOD;
		a=(a*a)%MOD;
		n=n>>1;
	}
	return ans;
}

int powerRecursive(int a,int n){
	if(n==0)
		return 1;

	int p=(powerRecursive(a,n/2))%MOD;
	if(n&1)
		return (((p*p)%MOD)*a)%MOD;
    else
    	return (p*p)%MOD;
    
}

int32_t main(){
	   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
	#endif
	int a,n;cin>>a>>n;

	cout<<powerIterative(a,n)<<endl;
	cout<<powerRecursive(a,n)<<endl;

}