#include <bits/stdc++.h>
using namespace std;

int main()
{
       ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif

    int q;cin>>q;
    int n=q;
    map<int ,int> hash;
    map<int ,int> count;
     // first will contain <element, frequency> pairs
    // second will contain <frequency, frequencyCount> pairs

    while(q--)
    {
        int a;int b;  cin>>a>>b;
        if(a==1)
        {
            int temp=hash[b];
            if(temp){
                count[temp]--;
                hash[b]++;
                count[hash[b]]++;
            }
            else{
                hash[b]++;
                count[hash[b]]++;
            }
        }
        else if(a==2)
        {
            int temp=hash[b];
            if(temp){
                count[temp]--;
                hash[b]--;
                count[hash[b]]++;
            }
        }
        else 
        {
            if(count[b])
                cout<<1<<endl;
            else
                cout<<0<<endl;
            
        }
    }
    
    return 0;
}
