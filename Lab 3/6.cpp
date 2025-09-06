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
    void deleteAtPosition(size_t k)
    {
        if (!head || (!head->next && k != 0))
            return;
        if (k == 0)
        {
            Node *temp = head;
            if (!head->next)
                head = tail = nullptr;
            else
                head = head->next;
            delete temp;
            return;
        }
        int cnt = 1;
        Node *cur = head->next, *pre = head;
        while (cur->next && cnt != k)
            cnt++, pre = cur, cur = cur->next;
        if (!cur->next && cnt == k)
            pre->next = nullptr, tail = pre;
        else if (!cur->next)
            return;
        else
            pre->next = cur->next;
        delete cur;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    LL list(arr, sizeof(arr) / sizeof(arr[0]));
    nl;
    list.print();
    size_t pos = 0;
    cout << "\nEnter position of element to delete: ", cin >> pos;
    list.deleteAtPosition(pos);
    list.print();
    nl;
    return 0;
}