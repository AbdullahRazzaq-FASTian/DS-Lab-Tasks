#include <bits/stdc++.h>
#define nl (cout<<endl)
using namespace std;

class Node
{
public:
    string passengerName;
    Node *next;
    Node(string name) : passengerName(name), next(nullptr) {}
};

class LinkedList
{
public:
    Node *head;
    LinkedList() : head(nullptr) {}
    ~LinkedList()
    {
        Node *cur = head;
        while (cur)
        {
            Node *temp = cur;
            cur = cur->next;
            delete temp;
        }
    }

    void reserve(string n)
    {
        Node *temp = new Node(n);
        if (!head || n < head->passengerName)
        {
            temp->next = head;
            head = temp;
            return;
        }
        Node *cur = head;
        while (cur->next && cur->next->passengerName < n)
        {
            cur = cur->next;
        }
        temp->next = cur->next;
        cur->next = temp;
    }

    void cancel(string n)
    {
        if (!head)
            return;
        if (head->passengerName == n)
        {
            Node *t = head;
            head = head->next;
            delete t;
            return;
        }
        Node *cur = head;
        while (cur->next && cur->next->passengerName != n)
        {
            cur = cur->next;
        }
        if (cur->next)
        {
            Node *t = cur->next;
            cur->next = t->next;
            delete t;
        }
    }

    bool search(string n)
    {
        Node *cur = head;
        while (cur)
        {
            if (cur->passengerName == n)
                return true;
            cur = cur->next;
        }
        return false;
    }

    void display()
    {
        Node *cur = head;
        int i = 1;
        cout << "\nReservations\n";
        while (cur)
        {
            cout << i++ << ". " << cur->passengerName << endl;
            cur = cur->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList l;
    int ch;
    string n;
    while (true)
    {
        cout << "\n1. Reserve 2. Cancel 3. Search 4. Display 5. Exit\n";
        cin >> ch;
        nl;
        switch (ch)
        {
        case 1:
            cout << "Name: ";
            cin >> ws;
            getline(cin, n);
            l.reserve(n);
            cout << "\nBooking Reserved to " << n << "!\n";
            break;
        case 2:
            cout << "Name: ";
            cin >> ws;
            getline(cin, n);
            l.cancel(n);
            cout << "\nBooking to " << n << " canceled successfully!\n";
            break;
        case 3:
            cout << "Name: ";
            cin >> ws;
            getline(cin, n);
            if (l.search(n))
                cout << "Found\n";
            else
                cout << "Not Found\n";
            break;
        case 4:
            l.display();
            break;
        case 5:
            return 0;
        default:
            cout << "Wrong choice\n";
            break;
        }
    }
}
