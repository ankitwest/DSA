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

//Part Two

int search(node* head,int key){
	int pos =1;
	node* temp = head;
	while(temp!=NULL){
		if(temp->data==key)
			return pos;
		else pos++;

		temp = temp->next;
	}
	return -1;
}

void deleteAtHead(node* &head){
	node* toDelete = head;
	head=head->next;

	delete toDelete;
}

void deletion(node* &head,int val){

	if(head==NULL)
		return;

	if(head->next==NULL){
	deleteAtHead(head);
	return ;
	}

	node* temp = head;
	while(temp->next->data!=val){
		temp = temp->next;
	}
	node* toDelete = temp->next;
	temp->next=temp->next->next;

	delete toDelete;
}

int main()
{
	node* head = NULL;
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtHead(head,0);
	insertAtHead(head,23);
	display(head);
	cout<<search(head,1)<<endl;

	deletion(head,1);
	display(head);

	deleteAtHead(head);
	display(head);
	return 0;	
}

//control + option + N  =  To run 
//control + option + M  = To stop  