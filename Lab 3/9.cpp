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

Node *reverse(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *cur = head, *prev = nullptr, *next = nullptr;
    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

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

    void func()
    {
        if (!head || !head->next)
            return;
        Node *odd = head, *even = head->next, *evenHead = head->next;
        while (even && even->next)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = reverse(evenHead);
        tail = evenHead;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    LL list(arr, sizeof(arr) / sizeof(arr[0]));

    cout << "\nBefore\n";
    list.print();

    list.func();

    cout << "\nAfter\n";
    list.print();
    nl;

    return 0;
}