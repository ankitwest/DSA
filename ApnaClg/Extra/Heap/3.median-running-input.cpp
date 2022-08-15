#include <bits/stdc++.h>
using namespace std;

#define debug1(x) cout<<(x)<<endl

//Totally overflow from my mind

priority_queue<int,vector<int> > pqMax;
priority_queue<int,vector<int>,greater<int> > pqMin;

void insert(int x){
    if(pqMin.size() == pqMax.size()){
        if(pqMax.size()==0){
            pqMax.push(x);
            return;
        }
        if(x< pqMax.top()){
            pqMax.push(x);
        }
        else{
            pqMin.push(x);
        }
    }
    else{
        if( pqMax.size() >  pqMin.size()){
            if(x >= pqMax.top()){
                pqMin.push(x);
            }
            else{
                int temp = pqMax.top();
                pqMax.pop();
                pqMin.push(temp);
                pqMax.push(x);
            }
        }
        else{
            if(x<= pqMin.top()){
                pqMax.push(x);
            }
            else{
                int temp = pqMin.top();
                pqMin.pop();
                pqMax.push(temp);
                pqMin.push(x);
            }
        }
       
    }
     
}
int main(){
    insert(10);
    cout<<findMedian()<<endl;
    return 0;    
}