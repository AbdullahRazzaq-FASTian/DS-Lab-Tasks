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
    void helper(int i, int size, Node *&ptr, bool &ans)
    {
        if (i > size / 2)
        {
            if (size & 1)
                ptr = ptr->next;
            return;
        }
        Node *temp = ptr;
        ptr = ptr->next;
        helper(i + 1, size, ptr, ans);
        if (temp->val != ptr->val)
            ans = false;
        ptr = ptr->next;
    }

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

    bool isPalindrome(){
        bool isPal = true;
        Node *ptr = head;
        helper(1,size, ptr, isPal);
        return isPal;
    }
};

int main()
{
    int arr[] = {1, 2, 2, 1, 1};
    LL list(arr, sizeof(arr)/sizeof(arr[0]));
    cout << "\nList: ";
    list.print();
    if(list.isPalindrome()) cout << "List Is Palindrome";
    else cout << "List is not Palindrme";
    nl;
    nl;
    return 0;
}