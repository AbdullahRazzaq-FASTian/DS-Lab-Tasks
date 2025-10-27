#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

struct Node
{
    int val;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int val) : val(val) {};
};

class BST
{
    Node *root;
    int N;

    Node* insert(Node *&root, int val)
    {
        if (!root)
            root = new Node(val), N++;
        else if (root->val > val)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);    
        return root;
    }
    
    void preOrder(Node *root)
    {
        if (!root)
            return;
        cout << root->val << " ";
        if (root->left)
            preOrder(root->left);
        if (root->right)
            preOrder(root->right);
    }

    void inOrder(Node *root)
    {
        if (!root)
            return;
        if (root->left)
            inOrder(root->left);
        cout << root->val << " ";
        if (root->right)
            inOrder(root->right);
    }

    void postOrder(Node *root)
    {
        if (!root)
            return;
        if (root->left)
            postOrder(root->left);
        if (root->right)
            postOrder(root->right);
        cout << root->val << " ";
    }

    bool search(Node *root, int val)
    {
        if(!root) return false;
        if(val < root->val) return search(root->left, val);
        else if(val > root->val) return search(root->right, val);
        return true;
    }

    Node* getSuccessor(Node* cur) {
        cur = cur->right;
        while (cur != nullptr && cur->left != nullptr)
            cur = cur->left;
        return cur;
    }

    Node* deleteNode(Node* root, int val){
        if(!root) return root;
        if(val < root->val) root->left = deleteNode(root->left, val);
        else if(val > root->val) root->right = deleteNode(root->right, val);
        else{
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* succ = getSuccessor(root);
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
        return root;
    }

public:
    BST(Node *root = nullptr) : root(root), N(0) {}

    void insert(int val) { insert(root, val); }
    void preOrder() { preOrder(root); }
    void inOrder() { inOrder(root); }
    void postOrder() { preOrder(root); }
    bool search(int val) { return search(root, val); }
    void deleteNode(int val) { deleteNode(root, val);}
};

int main()
{
    BST apkaTree;
    apkaTree.insert(4);
    apkaTree.insert(2);
    apkaTree.insert(6);
    apkaTree.insert(1);
    apkaTree.insert(3);
    apkaTree.insert(5);
    apkaTree.insert(7);

    apkaTree.inOrder();
    nl;
    cout << (apkaTree.search(4)? "Found" : "Not Found");
    nl;
    cout << (apkaTree.search(8)? "Found" : "Not Found");
    nl;
    apkaTree.deleteNode(3);
    apkaTree.inOrder();
    nl;

    return 0;
}