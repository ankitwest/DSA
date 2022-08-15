#include <bits/stdc++.h>
using namespace std;

#define n 20
#define ln  cout<<endl;
#define debug1(x) cout<<(x)<<endl

//Stack And Queue similar a bit
class Queue{
    int *arr;
    int front;
    int back;
    public:
    Queue(){
        arr = new int[n];
        front=-1;
        back=-1;
    }

    void push(int x){
        if(back== (n-1)){
            cout<<"Queue Overflow"<<endl;
            return ;
        }
        back++;
        arr[back]=x;

        if(front==-1){
            front++;
        }
    }

    void pop(){
        if(front == -1 or front>back){
            cout<<"No elements in queue"<<endl;
            return ;
        }
        front++;
    }

    int peek(){
        if(front==-1 or front>back){
            cout<<"No elements in queue or"<<endl;
            return -1;
        }
        return arr[front];
    }
    

    bool empty(){
        return front==-1 or front>back;
    }

};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);


    debug1(q.peek());
    q.pop();

    debug1(q.peek());
    q.pop();

    debug1(q.peek());
    q.pop();

    debug1(q.peek());

    debug1(q.empty()); 



    return 0;
}