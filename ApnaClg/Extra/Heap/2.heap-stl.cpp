#include <bits/stdc++.h>
using namespace std;

#define debug1(x) cout<<(x)<<endl

int main(){
    priority_queue<int , vector<int> > pq;
    pq.push(2);
    pq.push(3);
    pq.push(1);
    pq.push(4);
    pq.push(4);   //1,2,3,4,4

    debug1(pq.top());
    pq.pop();
    debug1(pq.top());
     
    priority_queue<int,vector<int>, greater<int> > pqMin;

    pqMin.push(3);
    pqMin.push(1);
    pqMin.push(2);
    pqMin.push(5);  //5,3,2,1
     

    debug1(pqMin.top());
}