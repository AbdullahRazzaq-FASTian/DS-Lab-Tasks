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

class DLL
{
public:
    Node *head;
    Node *tail;
    int size;

    DLL(Node *head) : head(head), tail(nullptr), size(0)
    {
        Node *cur = head;
        while (cur)
        {
            size++;
            if (!cur->next)
                tail = cur;
            cur = cur->next;
        }
    }

    DLL(int arr[], int n) : head(nullptr), tail(nullptr), size(n)
    {
        head = new Node(arr[0]);
        tail = head;
        for (int i = 1; i < n; i++)
        {
            Node *newNode = new Node(arr[i]);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    ~DLL()
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
        if (cur)
            cout << cur->val << endl;
    }

    void printReverse()
    {
        Node *cur = tail;
        while (cur && cur->prev)
        {
            cout << cur->val << " ";
            cur = cur->prev;
        }
        if (cur)
            cout << cur->val << endl;
    }
    void concatenate(DLL *list)
    {
        if (!list->head)
            return;
        if (!this->head)
        {
            head = list->head;
            tail = list->tail;
            size = list->size;
        }
        else
        {
            this->tail->next = list->head;
            list->head->prev = this->tail;
            this->tail = list->tail;
            this->size += list->size;
        }
        list->head = list->tail = nullptr;
        list->size = 0;
    }
};

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    DLL list1(arr1, sizeof(arr1) / sizeof(arr1[0]));

    int arr2[] = {6, 7, 8, 9, 10};
    DLL list2(arr2, sizeof(arr2) / sizeof(arr2[0]));

    cout << "\nBefore Concatenation\n";
    list1.print();
    list2.print();

    list1.concatenate(&list2);

    cout << "\nAfter Concatenation\n";
    list1.print();
    nl;
    
    return 0;
}