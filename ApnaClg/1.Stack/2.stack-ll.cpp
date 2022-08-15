#include <bits/stdc++.h>
using namespace std;

#define ln cout<<"\n";
#define debug1(x) cout<<(x)<<endl


class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next= NULL;
    }
};

class Queue{
    node* front;
    node* back;

    public:   //to make a constructor
    Queue(){ 
        front=NULL;
        back=NULL;
    }

    void push(int x){
        node* newNode = new node(x);

        if(front == NULL){
            back=newNode;
            front=newNode;
            return;
        }
        back->next=newNode;
        back=newNode;
    }

    void pop(){
        if(front==NULL){
            cout<<"Queue underflow"<<endl;
            return ;
        }

        node* toDelete = front;
        front = front->next;

        delete(toDelete);
    }

    int peek(){
        if(front==NULL){
            cout<<"No element in queue"<<endl;
            return -1;;
        }

        return front->data;
    }

    bool empty(){
        return front==NULL;
    }

};


int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    debug1(q.peek());
    q.pop();

    debug1(q.peek());
    q.pop();

    debug1(q.peek());
    q.pop();

    debug1(q.empty()); 

    return 0;
}
