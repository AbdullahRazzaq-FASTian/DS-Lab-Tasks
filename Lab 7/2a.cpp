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

    void sort() {
        if (!head || !head->next) return;

        bool swapped;
        do {
            swapped = false;
            Node* cur = head;
            Node* prev = nullptr;
            while (cur && cur->next) {
                Node* nextNode = cur->next;
                if (cur->val > nextNode->val) {
                    cur->next = nextNode->next;
                    nextNode->next = cur;
                    if(prev) prev->next = nextNode;
                    else head = nextNode;
                    swapped = true;
                    prev = nextNode;
                }
                else{
                    prev = cur;
                    cur = cur->next;
                }
            }
        } while (swapped);
    }

};
/* 4 3 2 1 */
/* 3 2 1 4 */
/* 2 1 3 4 */
/* 1 2 3 4 */

int main()
{
    int arr[] = {3, 2, 5, 1, 4};
    LL list(arr, sizeof(arr) / sizeof(arr[0]));
    nl;
    cout << " Before Sorting: ";
    list.print();
    list.sort();
    cout << " After Sorting: ";
    list.print();
    nl;
    return 0;
}