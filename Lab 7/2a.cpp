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

    LL(Node *head) : head(head), size(0)
    {
        tail = head;
        while (tail && tail->next)
        {
            size++;
            tail = tail->next;
        }
        if (tail)
            size++;
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
        size = 0;
    }

    void print()
    {
        Node *cur = head;
        while (cur)
        {
            cout << cur->val << (cur->next ? " " : "\n");
            cur = cur->next;
        }
    }

    void sort()
    {
        // Bubble sort
        if (!head)
            return;
        Node *curi = head, *prev = nullptr;
        while (curi->next)
        {
            Node *curj = curi->next;
            while (curj)
            {
                Node *next = curj;
                if (curi->val > curj->val)
                {
                    curi->next = curj->next;
                    curj->next = curi;
                    if(prev) prev->next = curj;
                    if(head == curi)
                        head = curj;
                }
                curj = next;
            }
            prev = curi;
            curi = curi->next;
        }
    }
};

int main()
{
    int arr[] = {3, 2, 5, 1, 4};
    LL list(arr, sizeof(arr) / sizeof(arr[0]));
    nl;
    list.print();
    list.sort();
    list.print();
    nl;
    return 0;
}
