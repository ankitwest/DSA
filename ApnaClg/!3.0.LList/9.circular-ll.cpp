#include <bits/stdc++.h>
using namespace std;


class node{
	public :
	int data;
	node* next;

	node(int val){
		data = val;
		next =NULL;
	}
};

void insertAtHead(node* &head,int val){
	node* n = new node(val);
    node* temp = head;

    if(head == NULL){
        n->next = n;
        head=n;
        return;
    }
	
    while(temp->next!=head){
		temp = temp->next;
	}

    temp->next=n;
    n->next = head;
    head =n;
}
void insertAtTail(node* &head , int val){
	
    if(head == NULL){
        insertAtHead(head, val);
        return;
            }
     node* n = new node(val);
	node* temp = head;


	while(temp->next!=head){
		temp = temp->next;
	}
	temp->next = n;
    n->next = head;
}

void display(node* head){
	node* temp = head;
    do{
        cout<<temp->data<<"->";
        temp = temp->next;
    }
	while(temp!=head);
    cout<<endl;
	//cout<<"NULL"<<endl; 
}
void deleteAtHead(node* &head){
    node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }

    node* toDelete = head;
    temp->next = head->next;
    head = head->next;

    delete toDelete;
}
void deletion(node* &head, int pos){

    if(pos==1){
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    int count =1;
    pos--;
    while(count!=pos ){
        count++;
        temp = temp->next;
    }

    node* toDelete = temp->next;
    temp->next = temp->next->next;

    delete toDelete;
}

int main(){ 
    node* head=NULL;

    int arr[]={1,2,3,4,5};
    for(int i=0;i<5;i++){
        insertAtTail(head,arr[i]);
    } 

    insertAtTail(head,6);
   
    display(head);

    deletion(head,6);
    display(head);

    deletion(head,1);
    display(head);


    return 0;

}