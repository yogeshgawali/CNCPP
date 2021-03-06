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
	struct node* temp =(struct node*)malloc(sizeof(struct node));
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

void findElement(struct node* head, int val)
{
    static int count = 0, occurance = 0;
    if(head == NULL)
    {
        count = 0;
        if(occurance == 0)
        {
             printf("Element %d not found.\n", val);
        }
        return;
    }
    else
    {
        count++;
        if(head->data == val)
        {
             printf("Element %d found at location %d\n", val, count);
             occurance++;
        }
        findElement(head->next, val);
    }
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
	head = listAdd(head, 35);
	head = listAdd(head, 65);
	listDisplay(head);

	findElement(head, 40);

	findElement(head, 35);

	findElement(head, 41);

	return 0;
}
