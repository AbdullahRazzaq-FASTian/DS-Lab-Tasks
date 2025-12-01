#include <bits/stdc++.h>
#define N 1000
#define nl cout << endl
#define f(i, s, e) for (int i = s; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)
using namespace std;

struct Node
{
    double price;
    Node *left = nullptr;
    Node *right = nullptr;
    int height = 1;
    Node(double price) : price(price), height(1), left(nullptr), right(nullptr) {}
};

class AVL
{
    int size;
    Node *root = nullptr;

    int getHeight(Node *root)
    {
        if (!root)
            return 0;
        else
            return root->height;
    }
    void updateHeight(Node *root)
    {
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        root->height = 1 + max(lh, rh);
    }
    int getBalance(Node *root)
    {
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        return lh - rh;
    }

    Node *rotateRight(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node *rotateLeft(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node *balance(Node *root)
    {
        if (!root)
            return root;

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
        {
            return rotateRight(root);
        }

        if (balance > 1 && getBalance(root->left) < 0)
        {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        if (balance < 1 && getBalance(root->right) <= 0)
        {
            return rotateLeft(root);
        }

        if (balance < 1 && getBalance(root->right) > 0)
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    Node *insert(Node *root, double price)
    {
        // cout << "here" << endl;
        if (!root)
        {
            root = new Node(price);
            size++;
            // cout << size << endl;
        }
        else if (price < root->price)
        {
            root->left = insert(root->left, price);
        }
        else if (price > root->price)
        {
            root->right = insert(root->right, price);
        }
        else
            return nullptr;
        updateHeight(root);
        return balance(root);
    }

    void inorder(Node *root)
    {
        if (!root)
            return;
        if (root->left)
            inorder(root->left);
        cout << root->price << " ";
        if (root->right)
            inorder(root->right);
    }

    bool search(Node *root, double price)
    {
        if (!root)
            return false;
        if (price == root->price)
            return true;
        else if (price < root->price)
            return search(root->left, price);
        else if (price > root->price)
            return search(root->right, price);
        return false;
    }

    void traverseHelper(Node *root, int &cnt, const double rootPrice)
    {
        if (!root)
            return;
        if (search(rootPrice - root->price))
            cnt++;
        if (root->left)
            inorder(root->left);
        if (root->right)
            inorder(root->right);
    }

public:
    AVL() : size(0), root(nullptr) {}
    void insert(double price)
    {
        root = insert(root, price);
    }
    void inorder()
    {
        inorder(root);
        nl;
    }
    bool search(double price)
    {
        return search(root, price);
    }
    int validPairs()
    {
        int cnt = 0;
        traverseHelper(root, cnt, root->price);
        return cnt;
    }
};

int main()
{
    AVL tree;
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(2);
    tree.insert(6);
    tree.insert(5);
    tree.inorder();
    // cout << tree.validPairs();
    return 0;
}