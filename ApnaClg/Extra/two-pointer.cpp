#include <bits/stdc++.h>
using namespace std;

#define debug1(x) cout<<(x)<<endl

//Not working 
int32_t main(){
    int n;cin>>n;
    int target; cin>>target;
    vector<int> a(n);

    for(auto &i:a)
        cin>>i;
    
    bool found = false;
    sort(a.begin(), a.end());
    for(int i=0;i<n;i++){
        int low = i+1 , high = n-1;
        while(low<high){
            int current = a[i] + a[low] + a[high];
            if (current == target){
                found = true;
            }
            if(current < target){
                low++;
            }
            else{
                high--;
            }
        }
    }
    
    if(found) debug1("True");
    else debug1("False");
}