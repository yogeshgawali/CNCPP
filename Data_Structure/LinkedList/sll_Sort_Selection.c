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

void findMiddleNode(struct node* head)
{
    struct node *fastPtr, *slowPtr;
    int count = 0;
    fastPtr = head;
    slowPtr = head;
    while(fastPtr != NULL && fastPtr->next != NULL)
    {
        count++;
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    printf("Middle node is %d, at location %d\n", slowPtr->data, count);
}

struct node* sortSelection(struct node* head)
{
    struct node *localHead = head, *unsortPtr, *toSortPtr, *temp, *pretemp=NULL;
    int count = 0;

    if(head == NULL)
        return NULL;
    else if(head->next == NULL)
        return head;

    unsortPtr = head->next;

    while(unsortPtr != NULL)
    {
        toSortPtr = unsortPtr;
        unsortPtr = unsortPtr->next;
        pretemp = toSortPtr;
        temp = localHead;
        while(temp != toSortPtr)    //10->65->70->25->90->35->40->60->50->52->75->45->NULL
        {
            if(toSortPtr->data < temp->data)
            {
                struct node *t = toSortPtr;
                if(temp == localHead)
                    localHead = toSortPtr;
                pretemp->next = toSortPtr;
                toSortPtr->next = temp;
                temp = t;
                while(temp->next != t)
                    temp=temp->next;
                temp->next = unsortPtr;
                break;
            }
            pretemp=temp;
            temp = temp->next;
        }
    }
    return localHead;
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
	listDisplay(head);

    head = sortSelection(head);

    listDisplay(head);
    return 0;
}
