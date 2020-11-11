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

struct node* sortSelection(struct node* head)
{
    struct node *newList = NULL, *temp, *t;

    if(head == NULL)
        return NULL;

    newList = head;
    head = head->next;
    newList->next = NULL;
    while(head != NULL)
    {
        //extract first node from old list
        t = head;
        head = head->next;
        t->next = NULL;

        //insert extracted node in new list at appropriate location
        temp = newList;
        if(temp->data > t->data)
        {
            t->next = newList;
            newList = t;
        }
        else
        {
            while((temp->next != NULL) && (temp->next->data < t->data))    //10->65->70->25->90->35->40->60->50->52->75->45->NULL
                temp = temp->next;
            t->next = temp->next;
            temp->next = t;
        }
    }
    return newList;
}

int main()
{
	int choice, data;
	struct node* head = NULL;
	head = listAdd(head, 10);
	head = listAdd(head, 65);
	head = listAdd(head, 70);
	head = listAdd(head, 25);
	head = listAdd(head, 90);
	head = listAdd(head, 35);
	head = listAdd(head, 40);
	head = listAdd(head, 60);
	head = listAdd(head, 50);
	head = listAdd(head, 52);
	head = listAdd(head, 75);
	head = listAdd(head, 5);

	printf("List before sort is: \n");
	listDisplay(head);

    head = sortSelection(head);

    printf("List after sort is: \n");
    listDisplay(head);
    return 0;
}
