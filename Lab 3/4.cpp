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

    void segregate()
    {
        if (!head)
            return;
        Node oddHead(-1), evenHead(-1);
        Node *odd = &oddHead, *even = &evenHead;
        Node *cur = head;
        while (cur)
        {
            if (cur->val & 1){
                odd->next = cur;
                odd = odd->next;
            }
            else{
                even->next = cur;
                even = even->next;
            }
            cur = cur->next;
        }
        even->next = oddHead.next;
        head = evenHead.next;
    }
};

int main()
{
    int arr[] = {17, 15, 8, 12, 10, 5, 4, 1, 7, 6};
    LL list(arr, 10);
    cout << "Before: " << endl;
    list.print();
    cout << "After: " << endl;
    list.segregate();
    list.print();
    return 0;
}