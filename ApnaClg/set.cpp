#include <bits/stdc++.h>
using namespace std;
#include <unordered_set>
#define ln cout<<"\n";
#define debug0(x) cout<<(x)<<" "
#define debug1(x) cout<<(x)<<endl
#define debug2(x,y) cout<<(x)<<" "<<(y)<<endl

void setFun(){
     set<int, greater<int> > s;
    s.insert(1);
    s.insert(3);
    s.insert(3);
    s.insert(2);
    s.insert(4);
    s.insert(5);

    for(auto i : s){
        debug0(i);
    }ln;

    for(auto i = s.begin();i!=s.end();i++){
        debug0(*i);
    }ln;

    for(auto i = s.rbegin();i!=s.rend();i++){
        debug0(*i);
    }ln;

    s.erase(2);
    s.erase(s.begin());
    for(auto i : s){
        debug0(i);
    }ln;

//lower_bound and upper_bound

    set<int>s1;
    s1.insert(1);
    s1.insert(3);
    s1.insert(5);

    cout<<*s1.lower_bound(2)<<"\n";
    cout<<*s1.lower_bound(3)<<endl;
    cout<<*s1.upper_bound(3)<<endl;
    cout<<(s1.upper_bound(5)==s1.end())<<endl;
}


void multisetFun(){
    multiset<int>s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    s.insert(3);

    s.erase(3);

    for(auto i : s){
        debug0(i);
    }ln;
}
void unorderedsetFun(){
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    for(auto i : s){
        debug0(i);
    }ln;
}
int main(){
   
    setFun();
    multisetFun();
    unorderedsetFun();

}
// - Insertion : O(log N)
// - Deletion : O(log N)
// - LowerBound/UpperBound : O(log N)