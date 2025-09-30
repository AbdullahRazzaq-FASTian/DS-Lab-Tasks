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
        if (tail) size++;
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
            cout << cur->val << (cur->next? " " : "\n");
            cur = cur->next;
        }
    }

    void insertNodeAtAlternate(LL &list){
        if(!head){
            head = list.head;
            list.head = list.head->next;
            head->next = nullptr;
        }
        Node* cur1 = head, *cur2 = list.head;
        while (cur1 && cur2)
        {
            Node* next1 = cur1->next;
            Node* next2 = cur2->next;
            cur1->next = cur2;
            cur2->next = next1;
            cur1 = next1;
            cur2 = next2;
        }
        list.head = cur2;
    }
};

int main()
{
    int arr1[] = {1, 3, 5, 7, 9};
    LL list1(arr1, sizeof(arr1) / sizeof(arr1[0]));
    int arr2[] = {2, 4, 6, 8, 10, 11, 12};
    LL list2(arr2, sizeof(arr2) / sizeof(arr2[0]));
    nl;
    cout << "List 1: ";
    list1.print();
    nl;
    cout << "List 2: ";
    list2.print();

    list1.insertNodeAtAlternate(list2);

    nl;
    cout << "List 1: ";
    list1.print();
    nl;
    cout << "List 2: ";
    list2.print();
    nl;
    return 0;
}