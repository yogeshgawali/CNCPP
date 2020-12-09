#include <iostream>
using namespace std;

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << ' ';
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode *t1, *t2;
    int n1=0, n2=0;
    t1=head1;
    t2=head2;
    while(t1!=NULL)
    {
        n1++;
        cout<<t1->data<<" ";
        t1=t1->next;
    }
    cout<<endl;
    while(t2!=NULL)
    {
        n2++;
        cout<<t2->data<<" ";
        t2=t2->next;
    }
    cout<<endl;
    cout<<"n1 = "<<n1<<endl;
    cout<<"n2 = "<<n2<<endl;
    t1=head1;
    t2=head2;
    if(n1>n2)
    {
        for(int i=0; i<(n1-n2); i++)
            t1=t1->next;
    }
    else if(n1<n2)
    {
        for(int i=0; i<(n2-n1); i++)
            t2=t2->next;
    }
    while(t1!=NULL && t2!=NULL)
    {
        if(t1==t2)
            return t1->data;
        t1=t1->next;
        t2=t2->next;
    }
    return t2->next->data;
}

int main()
{
    int tests;
    cin >> tests;

    for (int tests_itr = 0; tests_itr < tests; tests_itr++)
    {
        int index;
        cin >> index;

        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        for (int i = 0; i < llist1_count; i++)
        {
            int llist1_item;
            cin >> llist1_item;
            llist1->insert_node(llist1_item);
        }

      	SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        for (int i = 0; i < llist2_count; i++)
        {
            int llist2_item;
            cin >> llist2_item;
            llist2->insert_node(llist2_item);
        }

      	SinglyLinkedListNode* ptr1 = llist1->head;
      	SinglyLinkedListNode* ptr2 = llist2->head;

      	for (int i = 0; i < llist1_count; i++)
        {
            if (i < index) {
          		ptr1 = ptr1->next;
            }
        }

      	for (int i = 0; i < llist2_count; i++) {
          	if (i != llist2_count-1) {
          		ptr2 = ptr2->next;
            }
        }

      	ptr2->next = ptr1;

        int result = findMergeNode(llist1->head, llist2->head);

        cout << result << "\n";
    }

    return 0;
}

/*
2
3
5
12
13
11
34
11
4
1
2
3
4
12 13 11 34 11
1 2 3 4 34 11
n1 = 5
n2 = 6
34
2
4
1
2
3
4
1
1
1 2 3 4
1 3 4
n1 = 4
n2 = 3
3
*/
