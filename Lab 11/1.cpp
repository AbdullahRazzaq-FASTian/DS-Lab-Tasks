#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Node
{
public:
    char val;
    string key;
    Node *next;
    Node(char val, string key) : val(val), key(key), next(nullptr) {}
};

class HashTable
{
    int size;
    Node **table = nullptr;

    int hashFunction(string key)
    {
        int sum = 0;
        for (int i = 0; i < key.length(); i++)
            sum += key[i];
        return sum % size;
    }

public:
    HashTable(int size) : size(size)
    {
        table = new Node *[size];
        for (int i = 0; i < size; i++)
            table[i] = nullptr;
    }

    void insert(char val, string key)
    {
        int hash = hashFunction(key);
        Node *newNode = new Node(val, key);

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
                    cur->val = val;
                    delete newNode;
                    return;
                }
                cur = cur->next;
            }

            if (cur->key == key)
            {
                cur->val = val;
                delete newNode;
                return;
            }

            cur->next = newNode;
        }
    }

    char search(string key)
    {
        int hash = hashFunction(key);
        Node *cur = table[hash];

        while (cur != nullptr)
        {
            if (cur->key == key)
            {
                return cur->val;
            }
            cur = cur->next;
        }
        // Key Not found, returning dummy character
        return '@';
    }

    void remove(string key)
    {
        int hash = hashFunction(key);
        Node *cur = table[hash];
        Node *previous = nullptr;

        while (cur != nullptr && cur->key != key)
        {
            previous = cur;
            cur = cur->next;
        }

        if (cur == nullptr)
        {
            cout << "Key " << key << " not found!\n";
            return;
        }

        if (previous == nullptr)
        {
            table[hash] = cur->next;
        }
        else
        {
            previous->next = cur->next;
        }

        delete cur;
        cout << "Key " << key << " deleted successfully.\n";
    }
};

int main()
{
    HashTable letsDoDis(5);
    pair<char, string> arr[10] = {
        {'A', "aaaaa"},
        {'B', "bbbbb"},
        {'C', "ccccc"},
        {'A', "zzzzz"},
        {'D', "ddddd"},
        {'E', "eeeee"},
        {'F', "fffff"},
        {'G', "ggggg"},
        {'H', "hhhhh"},
        {'I', "iiiii"}};
    nl;
    for (int i = 0; i < 10; i++)
        letsDoDis.insert(arr[i].first, arr[i].second);
    for (int i = 0; i < 10; i++)
        cout << arr[i].first << " = " << letsDoDis.search(arr[i].second) << endl;
    // Checking for key that is not inserted
    cout << letsDoDis.search("sssss") << endl;
    nl;
    return 0;
}