#include <bits/stdc++.h>
using namespace std;
//not working first insertAtTail

class node{
    public:
    int data;
    node* prev;
    node* next;

    node (int val){
        data=val;
        prev=NULL;
        next=NULL;
    }
};

void insertAtHead(node* &head,int val){
    node* n= new node(val);
    n->next=head;
    if(head!=NULL)
         

    head=n;
}

void insertAtTail(node* head,int val){

    if(head==NULL){
        insertAtHead(head,val);
        return ;
    }
    node* n= new node(val);
    node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

void display(node* head){
    node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void deleteAtHead(node* &head){
    node* toDelete=head;

    head=head->next;
    head->prev=NULL;
    

    delete toDelete;
}
void deletion(node* &head,int pos){
    if(pos==1){
        deleteAtHead(head);
        return ;
    }
    node* temp=head;
    int count=1;

    while(pos!=count and temp!=NULL){
        temp=temp->next;
        count++;
    }
     
    temp->prev->next=temp->next;
    if(temp->next!=NULL)
    temp->next->prev=temp->prev;

    delete temp;

}

int main()
{
    node* head=NULL;
    insertAtTail(head,70);

    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,5);
    insertAtHead(head,6);

    insertAtTail(head,8);
    insertAtTail(head,66);

    display(head);
    insertAtHead(head,0);
    display(head);
    deletion(head,2);

    display(head);

    return 0;

}