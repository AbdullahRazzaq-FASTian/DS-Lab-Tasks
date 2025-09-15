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
    bool find(Node* cur, int key){
        if (cur == nullptr) return false;
        if (cur->val == key) return true;
        bool found = find(cur->next, key);
        return found;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    LL list(arr, sizeof(arr)/sizeof(arr[0]));
    cout << "List: ";
    list.print();
    if(list.find(list.head, 3))
        cout << "Element found" << endl;
    else
        cout << "Element not found" << endl;
    nl;
    return 0;
}