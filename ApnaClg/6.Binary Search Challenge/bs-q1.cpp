#include <bits/stdc++.h>
using namespace std;


bool isFeasible(int mid,int arr[], int n ,int k){
    int pos = arr[0] , elements =1 ;

    for(int i=1;i<n;i++){
        if(arr[i] - pos >= mid ){
            pos = arr[i];
            elements++;
            if(elements == k){
                return true;
            }
        }
    }
    return false;
}

int largestMinDistance(int arr[],int n , int k){

    sort(arr,arr+n);

    int result =-1;
    int l=1; int r=arr[n-1];
    while(l<r){ 
        int mid = (l+r)/2;
        if(isFeasible(mid,arr,n,k)){
            result = max(result,mid);
            l = mid+1;
        }
        else{
            r =mid-1;
        }
    }
    return result;
}

int main(){
    int arr[] = {1,20,8,40,18};
    int n=5;
    int k=4;

     cout<<"largest min distance is :" <<largestMinDistance(arr,n,k)<<endl;
     return 0;
}