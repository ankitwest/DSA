#include <bits/stdc++.h>
using namespace std;

#define ln cout<<"\n";
#define debug0(x) cout<<(x)<<" "
#define debug1(x) cout<<(x)<<endl
#define debug2(x,y) cout<<(x)<<" "<<(y)<<endl

#define int long long
#define rep(i,a,n)           for(int i = a ; i < n ; i++)

int start=1;
void solve(){
	int a,b,c;cin>>a>>b>>c;
	int d,e,f;cin>>d>>f;
	int p,q,r;cin>>p>>q>>r;

	vector<int> v;
	int x=(r+a)/2;v.push_back(x);
	x=(q+b)/2;v.push_back(x);
	x=(p+c)/2;v.push_back(x);
	x=(f+d)/2;v.push_back(x);

	int ctr,ans=-1;
	for(int i=0;i<v.size();i++){
		ctr=0;
		e=v[i];
		if(c-b==b-a) ctr++;
		if(f-e==e-d) ctr++;
		if(r-q==q-p) ctr++;

		if(p-d==d-a) ctr++;
		if(q-e==e-b) ctr++;
		if(r-f==f-c) ctr++;

		if(r-e==e-a) ctr++;
		if(p-e==e-c) ctr++;

		ans = max(ans,ctr);
	}
	cout<<"Case"<<' '<<"#"<<start<<":"<<" "<<ans<<endl;
	 start++;
	return;
}
int32_t main(){
	   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	#endif
	
	int n;cin >> n;
	while(n--) solve();
	
    
}
