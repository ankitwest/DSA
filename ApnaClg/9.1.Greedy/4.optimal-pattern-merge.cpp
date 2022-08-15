#include <bits/stdc++.h>
using namespace std;


int32_t main(){

	   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    #endif


int n;cin >> n;
vector<int> a(n);

for(int i=0; i<n;i++){
	cin >> a[i];
}

priority_queue<int , vector<int> , greater<int> > minHeap;

for(int i=0;i<n;i++){
	minHeap.push(a[i]);
}

int ans=0;

while(minHeap.size()>1){
	int e1 = minHeap.top(); minHeap.pop();
	int e2 = minHeap.top(); minHeap.pop();

	ans += e1 + e2;
	minHeap.push(e1 + e2);

}

cout<< ans << endl;
return 0;
}
// 2 4 5 7
//6 + 11 + 24 = 35
