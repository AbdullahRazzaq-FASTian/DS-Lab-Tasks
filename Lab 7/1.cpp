#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val) : val(val), next(nullptr), prev(nullptr) {}
};

class LL
{

private:
    Node *reverseRecursive(Node *node)
    {
        if (!node)
            return nullptr;
        swap(node->prev, node->next);
        if (node->prev == nullptr)
        {
            return node;
        }
        return reverseRecursive(node->prev);
    }

public:
    Node *head;
    Node *tail;
    int size;
    LL(Node *head) : head(head), size(1)
    {
        tail = head;
        while (tail->next)
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
            Node *newNode = new Node(arr[i]);
            tail->next = newNode;
            newNode->prev = tail;
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
        while (cur)
        {
            cout << cur->val << (cur->next ? " " : "\n");
            cur = cur->next;
        }
    }
    void deleteAtPosition(size_t k)
    {
        if (!head || k >= size)
            return;

        if (k == 0)
        {
            Node *temp = head;
            head = head->next;
            if (head)
                head->prev = nullptr;
            else
                tail = nullptr;
            delete temp;
            size--;
            return;
        }

        Node *cur = head;
        for (size_t i = 0; i < k; i++)
            cur = cur->next;

        if (cur->next)
            cur->next->prev = cur->prev;
        else
            tail = cur->prev;

        cur->prev->next = cur->next;
        delete cur;
        size--;
    }
    void reverse()
    {
        head = reverseRecursive(head);
        tail = head;
        while (tail && tail->next)
        {
            tail = tail->next;
        }
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
    list.reverse();
    list.print();
    nl;
    return 0;
}