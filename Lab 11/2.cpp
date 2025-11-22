#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Node
{
public:
    string key;
    string value;
    Node *next;
    Node(string key, string value) : key(key), value(value), next(nullptr) {}
};

class HashTable
{
    int size;
    Node **table = nullptr;

    int hashFunction(string key)
    {
        int sum = 0;
        for (char c : key)
            sum += c;
        return sum % size;
    }

public:
    HashTable(int size) : size(size)
    {
        table = new Node *[size];
        for (int i = 0; i < size; i++)
            table[i] = nullptr;
    }

    void addRecord(string key, string value)
    {
        int hash = hashFunction(key);
        Node *newNode = new Node(key, value);

        if (table[hash] == nullptr)
        {
            table[hash] = newNode;
        }
        else
        {
            Node *cur = table[hash];
            while (cur->next != nullptr)
            {
                if (cur->key == key)
                {
                    cur->value = value;
                    delete newNode;
                    return;
                }
                cur = cur->next;
            }
            if (cur->key == key)
            {
                cur->value = value;
                delete newNode;
                return;
            }
            cur->next = newNode;
        }
    }

    void wordSearch(string key)
    {
        int hash = hashFunction(key);
        Node *cur = table[hash];
        while (cur != nullptr)
        {
            if (cur->key == key)
            {
                cout << "search key " << key << ": " << cur->value << endl;
                return;
            }
            cur = cur->next;
        }
        cout << "Error: " << key << " not found!" << endl;
    }

    void removeRecord(string key)
    {
        int hash = hashFunction(key);
        Node *cur = table[hash];
        Node *prev = nullptr;

        while (cur != nullptr && cur->key != key)
        {
            prev = cur;
            cur = cur->next;
        }

        if (cur == nullptr)
        {
            cout << "Key " << key << " not found!" << endl;
            return;
        }

        if (prev == nullptr)
            table[hash] = cur->next;
        else
            prev->next = cur->next;

        delete cur;
        cout << "key " << key << " deleted successfully !" << endl;
    }

    void printDictionary()
    {
        for (int i = 0; i < size; i++)
        {
            Node *cur = table[i];
            if (cur != nullptr)
            {
                cout << "index " << i << ": ";
                while (cur != nullptr)
                {
                    cout << "(" << cur->key << ", " << cur->value << ")";
                    if (cur->next != nullptr)
                        cout << " -> ";
                    cur = cur->next;
                }
                nl;
            }
        }
    }
};

int main()
{
    HashTable dict(100);

    dict.addRecord("AB", "FASTNU");
    dict.addRecord("CD", "CS");
    dict.addRecord("EF", "ENGINEERING");
    dict.addRecord("GH", "MATH");

    dict.wordSearch("AB");
    dict.removeRecord("EF");
    dict.printDictionary();

    dict.wordSearch("ZZ"); // non-existent key

    nl;
    return 0;
}