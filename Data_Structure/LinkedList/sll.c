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
	int pos, d, i, ch;
	nn = create(val);
	temp = head;
	printf("\nEnter choice: ");
    printf("\n\t1. Add at beginning\n\t2. Add to end\n\t3. Add to position\n\t4. Add after node\n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1: if(temp==NULL)
                    printf("List is empty. Adding data at start...");
strt:           nn->next = head;
                head = nn;
                return head;
        case 2: while(temp->next != NULL)
                    temp=temp->next;
                temp->next = nn;
                break;
        case 3: printf("Enter node position: ");
                scanf("%d", &pos);
                if(pos==1)
                    goto strt;
                for(i=1; i<pos-1; i++)
                {
                    if(temp->next == NULL)
                    {
                        printf("Location out of list size...");
                        return head;
                    }
                    temp=temp->next;
                }
                nn->next = temp->next;
                temp->next = nn;
                break;
        case 4: printf("Enter node value: ");
                scanf("%d", &d);
                while(temp->data!=d)
                    temp = temp->next;
                nn->next=temp->next;
                temp->next = nn;
                break;
        default: printf("Enter correct choice");break;
    }
    return head;
}

struct node* listRemove(struct node* head)
{
	struct node* temp,*t2;
	int ch, pos, i, d;
	temp=head;
	if(temp==NULL)
	{
		printf("List is empty. No removal possible...");
        return head;
	}
	printf("\nEnter choice: ");
    printf("\n\t1. From beginning\n\t2. From end\n\t3. From position\n\t4. With data\n");
    scanf("%d",&ch);
	switch(ch)
    {
strtR:  case 1: if(temp->next==NULL)
                {
                    free(temp);
                    return NULL;
                }
                head = temp->next;
                free(temp);
                return head;
        case 2: if(temp->next == NULL)
                {
                    free(temp);
                    return NULL;
                }
                while(temp->next->next!=NULL)
                    temp=temp->next;
                t2=temp->next;
                temp->next = NULL;
                free(t2);
                break;
        case 3: printf("Enter node position: ");
                scanf("%d", &pos);
                if(pos==1)
                    goto strtR;
                for(i=1; i<pos; i++)
                {
                    if(temp->next == NULL)
                    {
                        printf("Location out of list size...");
                        return head;
                    }
                    temp=temp->next;
                }
                t2 = temp->next;
                temp->next = temp->next->next;
                free(t2);
                break;
        case 4: printf("Enter node value: ");
                scanf("%d", &d);
                if(temp->data==d)
                    goto strtR;
                while(temp->next->data!=d)
                {
                    if(temp->next == NULL)
                    {
                        printf("Node with data %d not present in list...", d);
                        return head;
                    }
                    temp=temp->next;
                }
                t2=temp->next;
                temp->next = temp->next->next;
                free(t2);
                break;
        default: printf("Enter correct choice");break;
    }
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

int main()
{
	int choice, data;
	struct node* head = NULL;
	while(1)
	{
		printf("\nEnter choice : ");
		printf("\n\t1. ADD\n\t2. DELETE\n\t3. DISPLAY\n\t4. EXIT\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter data to add in list: ");
                    scanf("%d", &data);
                    head = listAdd(head, data);
                    break;
			case 2: head = listRemove(head);
                    break;
			case 3: listDisplay(head); break;
			case 4: exit(0); break;
			default: printf("Enter correct choice");break;
		}
	}
	return 0;
}
