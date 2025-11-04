#include <bits/stdc++.h>
#define nl (cout << endl)
#define f(i,s,e) for(int i=s;i<e;i++)
#define fr(i,s,e) for(int i=s;i>=e;i--)
#define N 1000
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    int height;
    Node(int val) {
        data = val;
        left = right = NULL;
        height = 1;
    }
};

class BST {
    Node *root;

    int get_height(Node *node) {
        return node ? node->height : 0;
    }

    int get_balance(Node *node) {
        return node ? get_height(node->left) - get_height(node->right) : 0;
    }

    void update_height(Node *node) {
        node->height = 1 + max(get_height(node->left), get_height(node->right));
    }

    Node *rotate_right(Node *y) {
        Node *x = y->left;
        Node *T2 = x->right;
        x->right = y;
        y->left = T2;
        update_height(y);
        update_height(x);
        return x;
    }

    Node *rotate_left(Node *x) {
        Node *y = x->right;
        Node *T2 = y->left;
        y->left = x;
        x->right = T2;
        update_height(x);
        update_height(y);
        return y;
    }

    Node *balance_node(Node *node) {
        int balance = get_balance(node);
        if (balance > 1 && get_balance(node->left) >= 0)
            return rotate_right(node);
        if (balance > 1 && get_balance(node->left) < 0) {
            node->left = rotate_left(node->left);
            return rotate_right(node);
        }
        if (balance < -1 && get_balance(node->right) <= 0)
            return rotate_left(node);
        if (balance < -1 && get_balance(node->right) > 0) {
            node->right = rotate_right(node->right);
            return rotate_left(node);
        }
        return node;
    }

    Node *insertBST(Node *node, int val) {
        if (!node) return new Node(val);
        if (val < node->data){
            node->left = insertBST(node->left, val);
            update_height(node->left);
        }
        else if (val > node->data){
            node->right = insertBST(node->right, val);
            update_height(node->right);
        }
        return node;
    }

    Node *convertToAVL(Node *node) {
        if (!node) return NULL;
        node->left = convertToAVL(node->left);
        node->right = convertToAVL(node->right);
        update_height(node);
        return balance_node(node);
    }

    void preorder(Node* node) {
        if (node != NULL) {
            int lH = get_height(node->left);
            int rH = get_height(node->right);

            cout << right << setw(2) << node->data << "   ";
            cout << right << setw(2) << lH << "   ";
            cout << right << setw(2) << rH << "   ";
            cout << right << setw(2) << get_balance(node) << endl;

            preorder(node->left);
            preorder(node->right);
        }
    }

public:
    BST() { root = NULL; }

    void insertNormal(int val) { root = insertBST(root, val); }

    void convert() { root = convertToAVL(root); }

    void display() {
        cout << "ND   LH   RH   BF" << endl;
        preorder(root);
        nl;
    }
};

int main() {
    BST tree;

    tree.insertNormal(10);
    tree.insertNormal(16);
    tree.insertNormal(12);
    tree.insertNormal(18);

    nl;
    cout << "Preorder of BST (Before Conversion): " << endl;
    tree.display();

    tree.convert();

    cout << "Preorder of AVL (After Conversion): " << endl;
    tree.display();

    return 0;
}