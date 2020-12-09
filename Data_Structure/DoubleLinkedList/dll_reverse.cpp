#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

void print_doubly_linked_list(DoublyLinkedListNode* head) {
    DoublyLinkedListNode *temp = head;
    while (temp) {
        cout << temp->data;

        temp = temp->next;

        if (temp) {
            cout << ' ';
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the reverse function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* reverse1(DoublyLinkedListNode* head) {
    DoublyLinkedListNode *temp=head, *nh=NULL, *t;
    if(temp==NULL)
        return NULL;
    else
    {
        while(temp->next!=NULL)
        {
            t=temp;
            temp=temp->next;
            t->next=nh;
            t->prev=NULL;
            nh=t;
        }
        temp->next=nh;
        temp->prev=NULL;
        return temp;
    }
}

int main()
{
    int t;
    cin >> t;

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        DoublyLinkedList* llist = new DoublyLinkedList();

        int llist_count;
        cin >> llist_count;

        for (int i = 0; i < llist_count; i++)
        {
            int llist_item;
            cin >> llist_item;

            llist->insert_node(llist_item);
        }

        printf("List before reverse:\n");
        print_doubly_linked_list(llist->head);
        cout << "\n";

        DoublyLinkedListNode* llist1 = reverse1(llist->head);

        printf("List after reverse:\n");
        print_doubly_linked_list(llist1);
        cout << "\n";

        free_doubly_linked_list(llist1);
    }

    return 0;
}
