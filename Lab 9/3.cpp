#include <bits/stdc++.h>
#define nl (cout << endl)
#define f(i, s, e) for (int i = s; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)
#define N 1000
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int val)
    {
        data = val;
        left = right = NULL;
        height = 1;
    }
};

class AVL
{
    Node *root;

    int get_height(Node *node)
    {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int get_balance(Node *node)
    {
        if (node == NULL)
            return 0;
        return get_height(node->left) - get_height(node->right);
    }

    void update_height(Node *node)
    {
        int l_h = get_height(node->left);
        int r_h = get_height(node->right);

        node->height = 1 + max(l_h, r_h);
    }

    Node *rotate_right(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        update_height(y);
        update_height(x);

        return x;
    }

    Node *rotate_left(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        update_height(x);
        update_height(y);

        return y;
    }

    Node *balance_node(Node *node)
    {
        int balance = get_balance(node);

        if (balance > 1 && get_balance(node->left) >= 0)
            return rotate_right(node);

        if (balance > 1 && get_balance(node->left) < 0)
        {
            node->left = rotate_left(node->left);
            return rotate_right(node);
        }

        if (balance < -1 && get_balance(node->right) <= 0)
            return rotate_left(node);

        if (balance < -1 && get_balance(node->right) > 0)
        {
            node->right = rotate_right(node->right);
            return rotate_left(node);
        }

        return node;
    }

    Node *insert(Node *node, int val)
    {
        if (node == NULL)
            return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        else
            return node;

        update_height(node);
        return balance_node(node);
    }

    Node *find_min(Node *node)
    {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    Node *delete_node(Node *node, int val)
    {
        if (node == NULL)
            return node;

        if (val < node->data)
            node->left = delete_node(node->left, val);
        else if (val > node->data)
            node->right = delete_node(node->right, val);
        else
        {
            if (node->left == NULL || node->right == NULL)
            {
                Node *temp = node->left ? node->left : node->right;

                if (temp == NULL)
                {
                    temp = node;
                    node = NULL;
                }
                else
                    *node = *temp;

                delete temp;
            }
            else
            {
                Node *temp = find_min(node->right);
                node->data = temp->data;
                node->right = delete_node(node->right, temp->data);
            }
        }

        if (node == NULL)
            return node;

        update_height(node);
        return balance_node(node);
    }

    void inorder(Node *node)
    {
        if (node != NULL)
        {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    AVL()
    {
        root = NULL;
    }

    void insert(int val)
    {
        root = insert(root, val);
    }

    void remove(int val)
    {
        root = delete_node(root, val);
    }

    void display()
    {
        inorder(root);
        cout << endl;
    }
};

int main()
{
    AVL tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    cout << "Inorder before insertion: ";
    tree.display();

    tree.insert(12);

    cout << "Inorder after insertion: ";
    tree.display();

    return 0;
}