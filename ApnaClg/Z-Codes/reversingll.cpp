
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *link;
};

struct Node *reverse(struct Node *head)
{
	struct Node *prev = NULL;
	struct Node *next = NULL;

	while(head!=NULL)
{
	next=head->link;
	head->link=prev;
	prev=head;
	head=next;
}
head=prev;
return head;
}


int main()
{
	Node* head =NULL;
	head=reverse(head);
	Node* ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<endl;
		ptr=ptr->link;
	}
	return 0;
}


