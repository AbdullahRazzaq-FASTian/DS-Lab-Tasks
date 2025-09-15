#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val) : val(val), next(nullptr) {}
};

class LL
{
public:
    Node *head;
    Node *tail;
    int size;
    LL(Node *head) : head(head)
    {
        Node *tail = head;
        while (tail)
        {
            size++;
            tail = tail->next;
        }
    }
    LL(int arr[], int n) : size(n)
    {
        head = new Node(arr[0]);
        tail = head;
        for (int i = 1; i < n; i++)
        {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
    }
    ~LL()
    {
        Node *cur = head;
        while (cur)
        {
            Node *temp = cur->next;
            delete cur;
            cur = temp;
        }
        head = tail = nullptr;
    }
    void print()
    {
        Node *cur = head;
        while (cur && cur->next)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << cur->val << endl;
    }
    void printReverse(Node* cur){
        if(cur == nullptr)
            return;
        printReverse(cur->next);
        cout << cur->val << " ";
    }
    void append(int val){
        Node* newNode = new Node(val);
        if(!head)
            head = tail = newNode;
        else
            tail->next = newNode, tail = newNode;
    }
};

int main()
{
    int arr[] = {1};
    LL list(arr, sizeof(arr)/sizeof(arr[0]));
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.print();
    list.printReverse(list.head);
    nl;
    return 0;
}