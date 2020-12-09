#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct node {
	int data;
	struct node *link;

};

typedef struct node ST_ND;
int list_choice = 0;

ST_ND *list[2] = {0,};

/*Create NEW node and make a list*/
static int create_list(ST_ND **head, int new_data)
{
	ST_ND *temp = *head;
	ST_ND *new_node = NULL;


	new_node = (ST_ND *) malloc(sizeof(ST_ND ));
	if(new_node < 0)
	{
		printf("Faild to allocate Memory... \n");
		return -1;
	}
	new_node -> data = new_data;
	new_node -> link = NULL;


	if(*head == NULL)
	{
		*head = new_node;
		 return 0;
	}


	while(temp -> link != NULL)
	{
		temp = temp -> link;
	}
		temp -> link = new_node;
		return 0;
}

/*Display the list*/
static int display_list(ST_ND *head, int list)
{
	if(head == NULL)
	{
		printf("List is Empty, can't dispaly\n");
		return 0;
	}

	while(head != NULL)
	{
		printf("List: %d, Address: %p data: %d\n", list, head -> link, head -> data);
		head = head -> link;
	}

	return 0;
}


/*  Length of list    */
static int length_list(ST_ND *list)
{
	int len = 0;

	if(list == NULL)
	{
		printf("Length of the list is = %d\n", len);
	}
	else
	{
		while(list != NULL)
		{
			list = list -> link;
			len++;
		}

	}

	return len;
}


/*Finds merge point of two signly lists*/
static int merge_list(ST_ND *list1, ST_ND *list2)
{
        int x = 0, y = 0, diff = 0, i = 0, node = 0;

        x = length_list(list1);
        y = length_list(list2);

        diff = x - y;
	node = diff;

        if(diff > 0)
        {
		printf("diff = %d\n", diff);
                for(; i < diff; i++)
                {
                        list1 = list1 -> link;
			printf("i = %d\n", i);
                }
        }
        else
        {
                diff = y - x;
                for(; i < diff; i++)
                {
                        list2 = list2 -> link;
                }
        }


        while(list1 != NULL && list2 != NULL)
        {
		node++;

                if(list1 -> data == list2 -> data)
                {
                        printf("Merge point found @@ Node: %d, Data1 = %d, Data2 = %d\n", node, list1 -> data, list2 -> data);
                }
		list1 = list1 -> link;
                list2 = list2 -> link;

        }
        return 0;
}



int main()
{
	int data = 0, choice = 0, list_choice = 0;

	while(1)
	{
		printf("Enter the following choice: \n \
			1. Create a Node    \n \
			2. Display          \n \
			3. Merge a list     \n \
			4. Exit             \n \
			");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("List 1 or List 2: Choice '1' or '2' \n");
				scanf("%d", &list_choice);

				if(list_choice == 1)
				{
					printf("Enter the data for list 1 \n");
					scanf("%d", &data);
					create_list(&list[list_choice - 1], data);
				}
				else if(list_choice == 2)
				{
					printf("Enter the data for list 2 \n");
					scanf("%d", &data);
					create_list(&list[list_choice - 1], data);
				}
				else
				{
					printf("Enter '1' or '2' \n");
				}
			break;

			case 2:
					printf("List 1 or List 2: \n");
					scanf("%d", &list_choice);

					if(list_choice == 1)
					{
						display_list(list[list_choice - 1], list_choice);
					}
					else if(list_choice == 2)
					{
						display_list(list[list_choice - 1], list_choice);
					}
					else
					{
						printf("No list exist() \n");
						return 0;
					}
			break;

			case 3:
				  	if(list[0] == NULL)
        			  	{
                				printf("List1 is Empty, Can't find the Merge point \n");
                				return 0;
        			  	}
        				else if (list[1] == NULL)
        				{
                				printf("List2 is Empty, Can't find the Merge point \n");
                				return 0;
        				}


					merge_list(list[0], list[1]);
			break;

			case 4:
				exit(1);
				break;
			default:
				printf("Exit");
		}
	}

}
