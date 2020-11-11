#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

struct node
{
	int data;
	struct node *next;
};

struct node* create(int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
        return NULL;
	temp->data=data;
	temp->next=NULL;
	return temp;
}

struct node* listAdd(struct node* head, int val)
{
	struct node* temp,*nn;
	nn = create(val);
	temp = head;

	if(temp==NULL)
    {
        printf("List is empty. Adding data at start...\n");
        head = nn;
        return head;
    }
    while(temp->next != NULL)
        temp=temp->next;
    temp->next = nn;
    return head;
}

struct node* listRemove(struct node* head)
{
	struct node* temp,*t2;
	temp=head;
	if(temp==NULL)
	{
		printf("List is empty. No removal possible...\n");
        return head;
	}
	if(temp->next==NULL)
    {
        free(temp);
        return NULL;
    }
    while(temp->next->next!=NULL)
        temp=temp->next;
    t2=temp->next;
    temp->next = NULL;
    free(t2);
    return head;
}

void mthModeFromLast(struct node* head, int l)
{
	struct node *bwptr, *fwptr;
	int loc = 0;
	bwptr = head;
	fwptr = head;
	while((fwptr != NULL) && loc < l)
    {
        fwptr = fwptr->next;
        loc++;
    }
    if(fwptr == NULL && loc<l)
    {
        printf("Index out of list.\n");
        return;
    }
	while(fwptr!=NULL)
	{
		fwptr = fwptr->next;
		bwptr = bwptr->next;
	}
	printf("%d th node from last is %d\n", l, bwptr->data);
}

void listDisplay(struct node* head)
{
	struct node* temp=head;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}

int main()
{
	int choice, data;
	struct node* head = NULL;
	head = listAdd(head, 10);
	head = listAdd(head, 15);
	head = listAdd(head, 20);
	head = listAdd(head, 25);
	head = listAdd(head, 30);
	head = listAdd(head, 35);
	head = listAdd(head, 40);
	head = listAdd(head, 45);
	head = listAdd(head, 50);
	head = listAdd(head, 55);
	head = listAdd(head, 60);
	head = listAdd(head, 65);
	listDisplay(head);
	mthModeFromLast(head, 5);
    mthModeFromLast(head, 20);

	return 0;
}
