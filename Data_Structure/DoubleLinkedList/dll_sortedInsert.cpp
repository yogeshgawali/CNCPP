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

void print_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << " ";
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

// Complete the sortedInsert function below.

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
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    struct DoublyLinkedListNode *nn, *temp = head;
    nn=(DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));
    nn->data=data;
    nn->next=NULL;
    nn->prev=NULL;

    if(temp==NULL)
    {
        return nn;
    }

    else if(temp->next==NULL)
    {
        if(temp->data>=data)
        {
            nn->next=temp;
            temp->prev=nn;
            return temp;
        }
        else
        {
            nn->prev=temp;
            temp->next=nn;
            return temp;
        }
    }
    else if(temp->next!=NULL && temp->data>data)
    {
        temp->prev=nn;
        nn->next=temp;
        return nn;
    }
    else
    {
        while(temp->next!=NULL)
        {
            if((temp->data<data && temp->next->data>data) || (temp->data==data))
            {
                nn->next=temp->next;
                nn->prev=temp;
                temp->next=nn;
                nn->next->prev=nn;
                return head;
            }
            temp=temp->next;
        }
        nn->prev=temp;
        temp->next=nn;
        return head;
    }
}

int main()
{
    int t;
    cin >> t;
    for (int t_itr = 0; t_itr < t; t_itr++) {
        DoublyLinkedList* llist = new DoublyLinkedList();

        int llist_count;
        cin >> llist_count;

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;

            llist->insert_node(llist_item);
        }

        int data;
        cin >> data;

        cout<<"List before insert:\n";
        print_doubly_linked_list(llist->head);
        cout << "\n";

        DoublyLinkedListNode* llist1 = sortedInsert(llist->head, data);

        cout<<"List after insert:\n";
        print_doubly_linked_list(llist1);
        cout << "\n";

        free_doubly_linked_list(llist1);
    }

    return 0;
}
