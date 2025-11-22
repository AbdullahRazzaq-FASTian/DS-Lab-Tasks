#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Node
{
public:
    int a, b;
    Node *next;
    Node(int a, int b) : a(a), b(b), next(nullptr) {}
};

class HashTable
{
    int size;
    Node **table = nullptr;

    int hashFunction(int a, int b)
    {
        return (a + b) % size;
    }

public:
    HashTable(int size) : size(size)
    {
        table = new Node *[size];
        for (int i = 0; i < size; i++)
            table[i] = nullptr;
    }

    void insert(int a, int b)
    {
        int hash = hashFunction(a, b);
        Node *newNode = new Node(a, b);

        if (table[hash] == nullptr)
        {
            table[hash] = newNode;
        }
        else
        {
            Node *cur = table[hash];
            while (cur->next != nullptr)
                cur = cur->next;
            cur->next = newNode;
        }
    }

    bool search(int a, int b, int &x, int &y)
    {
        int hash = hashFunction(a, b);
        Node *cur = table[hash];

        while (cur != nullptr)
        {
            if (cur->a != a && cur->a != b && cur->b != a && cur->b != b)
            {
                x = cur->a;
                y = cur->b;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
};

int main()
{
    int arr[] = {3, 4, 7, 1, 2, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    HashTable ht(50);

    nl;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int x, y;
            if (ht.search(arr[i], arr[j], x, y))
            {
                cout << "(" << x << ", " << y << ") and (" << arr[i] << ", " << arr[j] << ")" << endl;
                found = true;
                break;
            }
            ht.insert(arr[i], arr[j]);
        }
        if (found)
            break;
    }

    if (!found)
        cout << "No pairs found" << endl;

    nl;
    return 0;
}
