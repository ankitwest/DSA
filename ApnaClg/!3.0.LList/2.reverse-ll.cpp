#include <bits/stdc++.h>
using namespace std;

#define ln cout<<"\n";
#define debug0(x) cout<<(x)<<" "
#define debug1(x) cout<<(x)<<endl
#define debug2(x,y) cout<<(x)<<" "<<(y)<<endl

class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(node* &head , int val){
	node* n = new node(val);

	if(head==NULL){
		    head = n;
		return;
		}

	node* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = n;
}
void insertAtHead(node* &head,int val){
	node* n = new node(val);
	n->next=head;
	head = n;
}
void display(node* head){
	node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl; 
}
node* reverse(node* &head){

    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    while(currptr!=NULL){
        nextptr = currptr->next;

        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;

    } 
    return prevptr;
}

node* reverseRecursive(node* &head){

    if(head==NULL or head->next==NULL)
     return head;

    node* newHead= reverseRecursive(head->next);

    head->next->next=head;
    head->next=NULL;

    return newHead;
}
int main(){
    node* head=NULL;
    insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtHead(head,0);
	insertAtHead(head,23);

    display(head);
    node* newHead = reverse(head);
    display(newHead);
    return 0;
}