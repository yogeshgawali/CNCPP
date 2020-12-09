#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d)
        {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution
{
    public:
  		Node* insert(Node* root, int data)
  		{
            if(root == NULL)
            {
                return new Node(data);
            }
            else
            {
                Node* cur;
                if(data <= root->data)
                {
                    cur = insert(root->left, data);
                    root->left = cur;
                }
                else
                {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

                return root;
            }
        }

        Node *lca(Node *root, int v1,int v2)
        {
            if((v1 < root->data) && (v2 < root->data))
            {
                lca(root->left, v1, v2);
            }
            else if((v1 > root->data) && (v2 > root->data))
            {
                lca(root->right, v1, v2);
            }
            return root;
        }

        void preOrder(Node* root)
        {
            if(root==NULL)
                return;
            std::cout<<root->data<<" ";
            preOrder(root->left);
            preOrder(root->right);
        }

        void inOrder(Node* root)
        {
            if(root==NULL)
                return;
            inOrder(root->left);
            std::cout<<root->data<<" ";
            inOrder(root->right);
        }

        void postOrder(Node* root)
        {
            if(root==NULL)
                return;
            postOrder(root->left);
            postOrder(root->right);
            std::cout<<root->data<<" ";
        }

        void display(Node *root)
        {
            if(root==NULL)
                return;
            std::cout<<"Node: "<<root->data<<"\t";
            if(root->left!=NULL)
                std::cout<<root->left->data<<" ";
            else
                std::cout<<"* ";
            if(root->right!=NULL)
                std::cout<<root->right->data;
            else
                std::cout<<"* ";
            std::cout<<endl;
            display(root->left);
            display(root->right);
        }
}; //End of Solution

int main()
{

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    std::cout<<"-----------------\n";
    std::cout<<"Dsiplaying tree: \n";
    myTree.display(root);
    std::cout<<"-----------------\n";

    std::cout<<"PreOrder traversal : ";    // 4 2 1 3 7 6
    myTree.preOrder(root);
    std::cout<<endl;

    std::cout<<"InOrder traversal  : ";    // 1 2 3 4 6 7
    myTree.inOrder(root);
    std::cout<<endl;

    std::cout<<"PostOrder traversal: ";    // 1 3 2 6 7 4
    myTree.postOrder(root);
    std::cout<<endl;

    int v1, v2;
  	std::cin >> v1 >> v2;

    Node *ans = myTree.lca(root, v1, v2);

  	std::cout << ans->data;

    return 0;
}

/*
9
8 6 5 7 11 12 13 10 9
-----------------
Dsiplaying tree:
Node: 8 6 11
Node: 6 5 7
Node: 5 * *
Node: 7 * *
Node: 11        10 12
Node: 10        9 *
Node: 9 * *
Node: 12        * 13
Node: 13        * *
-----------------
PreOrder traversal : 8 6 5 7 11 10 9 12 13
InOrder traversal  : 5 6 7 8 9 10 11 12 13
PostOrder traversal: 5 7 6 9 10 13 12 11 8
9 12
8
*/
