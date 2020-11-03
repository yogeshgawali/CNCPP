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

void listAdd(struct node** h, int val)
{
	struct node* temp,*nn;
	nn = create(val);
	temp = *h;

	if(temp==NULL)
    {
        printf("List is empty. Adding data at start...\n");
        *h = nn;
        return;
    }
    while(temp->next != NULL)
        temp=temp->next;
    temp->next = nn;
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

void createLoop(struct node* head, int m)
{
	struct node* temp=head, *t2=head;
	int n=1;
	while(n != m)
    {
        temp=temp->next;
        t2 = t2->next;
        n++;
    }
    while(temp->next != NULL)
        temp=temp->next;
    temp->next = t2;
}

struct node* detectLoop(struct node* head)
{
    struct node *sp, *fp;
    sp = head;
    fp = head;
    while(sp && fp && fp->next)
    {
        sp = sp->next;
        fp = fp->next->next;
        if(sp == fp)
        {
            printf("Loop exist.\n");
            return fp;
        }
    }
    printf("Loop do not exist.\n");
    return NULL;
}

int removeLoop(struct node* head, struct node* ln)
{
    struct node *dn = head, *temp;
    if(ln==NULL)
        return;
    while(ln->next != dn)
    {
        temp=ln;
        while(temp->next!=ln)
        {
           if(temp->next==dn)
           {
               temp->next=NULL;
               return 1;
           }
           temp=temp->next;
        }
        dn=dn->next;
    }
    return 0;
}

int main()
{
	int choice, data, i, m;
	struct node* head = NULL, *ln=NULL;
	for(i=0; i<10; i++)
    {
        listAdd(&head, i*10);
	}
	printf("List created with %d entries.\n", 10);
	listDisplay(head);

    printf("Enter m: ");
    scanf("%d", &m);
	createLoop(head, m);

	ln = detectLoop(head);

    removeLoop(head, ln);

    listDisplay(head);
	return 0;
}
//head = listRemove(head);
    //listDisplay(head);

/*
      <-----------M------------------> <----------
      @ ----- @ ----- @ ----- @ ----- @ ------ @  \
                                     /  -- N -  \  K
                                    / /       \  \  \
                                   @ /         \  @
                                   | |          | |
                                   | |          | |
                                   @ |         /  @
                                    \ \       /  /
                                     \  -----   /
                                      @ ------ @

*/
