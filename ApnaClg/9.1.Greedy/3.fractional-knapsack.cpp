#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
	double v1 = (double) a.first/a.second;
	double v2 = (double) b.first/b.second; 

	return v1>v2;
}


int32_t main(){

	   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    #endif

	int n;
	cin >> n;

	vector<pair<int,int>> a(n);

	for(int i = 0; i < n;i++){
		int x,y;cin>>x>>y;
		a[i].first=x;
		a[i].second=y;

	}

	int w;cin>>w;
	sort(a.begin(),a.end(),compare);

	int ans =0;
	for(int i=0;i<n;i++){
		if(w >= a[i].second){
			ans += a[i].first;
			w -= a[i].second;
			//continue; //continue the loop 
		}
		else{
		double vw = (double) a[i].first/a[i].second;
		ans += vw * w;
		//w=0;
		break;
		}
	}

	cout << ans << endl;
	return 0;
}