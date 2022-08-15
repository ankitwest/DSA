#include <bits/stdc++.h>
using namespace std;

#define ln cout<<"\n";
#define debug1(x) cout<<(x)<<endl

void heapify(int arr[],int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n and arr[left] > arr[largest])
        largest=left;

    if(right < n and arr[right] > arr[largest])
        largest=right;

    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
    
}

void heapsort(int arr[] , int n){
    for(int i=n/2 -1 ;i>=0;i--){
        heapify(arr,n,i);
    }

    for(int i=n-1 ; i>=0;i--){
        swap(arr[0],arr[i]);

        heapify(arr,i,0);
    }
}


  void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      cout<<arr[i]<<" ";
    ln;
  }

 int main(){
     int arr[] = {1,12,9,5,6,10};
     int n = sizeof(arr)/sizeof(arr[0]);
     heapsort(arr,n);

     cout<<"Sorted array is \n";
     printArray(arr,n);
 }