#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int x;
    cin>>x;

    sort(a.begin(),a.end(), greater<int>());
    int ans =0;
    for(int i=0;i<n ;i++){
        ans = ans + x/a[i];
        x -= x/a[i] * a[i];  //integer val and not decimal value
    }

    cout<<ans<<endl;
    return 0;
}