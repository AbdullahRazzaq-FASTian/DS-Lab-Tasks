// 24K-0809
// 24K-0719
// 24K-0691
#include <bits/stdc++.h>
#define nl (cout << endl)
#define f(i,s,e) for(int i=s;i<e;i++)
#define fr(i,s,e) for(int i=s;i>=e;i--)
using namespace std;

struct Node
{
    int id;
    double balance;
    Node *left;
    Node *right;
    Node(int id, double balance) : id(id), balance(balance), left(nullptr), right(nullptr) {}
};

class BST
{
    Node *root;
    int N;

    Node *insert(Node *root, int id, double balance)
    {
        if (!root)
        {
            root = new Node(id, balance);
            N++;
        }
        else if (root->balance > balance)
        {
            root->left = insert(root->left, id, balance);
        }
        else
            root->right = insert(root->right, id, balance);
        return root;
    }

    void inOrder(Node *root, pair<int, double> data[], int &count)
    {
        if (!root)
            return;
        if (root->left)
            inOrder(root->left, data, count);
        data[count++] = make_pair(root->id, root->balance);
        if (root->right)
            inOrder(root->right, data, count);
    }

    double search(Node *root, int id)
    {
        if (!root)
            return -1;
        if (id < root->id)
            return search(root->left, id);
        else if (id > root->id)
            return search(root->right, id);
        return root->balance;
    }

public:
    BST(Node *root = nullptr) : root(root), N(0) {}

    void insert(int id, double balance) { insert(root, id, balance); }
    void inOrder(pair<int, double> data[]) { int count = 0; inOrder(root, data, count); }
    double search(int id) { return search(root, id); }
    int getSize() { return N; }
};

int validPairs(BST &curr, BST &save, double x)
{
    int count = 0;
    pair<int, double> data[curr.getSize()];
    curr.inOrder(data);
    int n = sizeof(data)/ sizeof(data[0]);
    f(i,0,n) cout << data[i].first << " " << data[i].second << endl;
    for(int i=0; i<n; i++){
        double b = save.search(data[i].first) ;
        if(b != -1 && b+data[i].second == x){
            count++;
        }
    }
    return count;
}

int main()
{
    BST current_account;
    BST saving_account;

    double x = 11000;

    current_account.insert(0, 1000);
    current_account.insert(1, 100);
    current_account.insert(2, 9000);
    current_account.insert(3, 8000);
    current_account.insert(4, 2000);
    current_account.insert(5, 0);

    saving_account.insert(0, 100);
    saving_account.insert(1, 1000);
    saving_account.insert(2, 2000);
    saving_account.insert(3, 1900);
    saving_account.insert(4, 1800);
    saving_account.insert(5, 11000);

    cout << validPairs(current_account, saving_account, x);
}