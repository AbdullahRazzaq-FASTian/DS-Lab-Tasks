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
    void addNode(int k, int val)
    {
        if (!head && k != 0)
            return;
        else if (k > size)
            return;
        size++;
        Node *newNode = new Node(val);
        if (k == 0)
        {
            newNode->next = head;
            if (!head)
                tail = newNode;
            head = newNode;
            return;
        }
        Node *cur = head;
        while (cur && --k > 0)
            cur = cur->next;
        if (cur)
        {
            newNode->next = cur->next;
            cur->next = newNode;
        }
        else if (!cur && --k == 0)
        {
            tail->next = newNode;
            tail = newNode;
        }
        else
            return; // Cannot insert
    }
    void deleteNode(int val)
    {
        if (!head)
            return;
        if (head->val == val)
        {
            Node *temp = head;
            head = head->next;
            if (!head)
                head = tail = nullptr;
            delete temp;
            return;
        }
        Node *cur = head->next, *prev = head;
        while (cur && cur->val != val)
            prev = cur, cur = cur->next;
        if (cur)
        {
            prev->next = cur->next;
            if (!prev->next)
                tail = prev;
            delete cur;
        }
    }
};

int main()
{
    int arr[5] = {3, 1, 2, 5, 8};
    LL list(arr, 5);
    nl;
    cout << "Before Adding: " << endl;
    list.print();
    nl;
    cout << "Adding elements: " << endl;
    list.addNode(5, 9);
    list.addNode(3, 11);
    list.addNode(0, 4);
    list.print();
    nl;
    cout << "Deleting elements: " << endl;
    list.deleteNode(1);
    list.deleteNode(2);
    list.deleteNode(5);
    list.print();
    nl;
    return 0;
}