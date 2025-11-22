#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Hash
{
    int size;
    list<pair<string, string>> *table;

    int hashFunction(string key)
    {
        int sum = 0;
        for (char c : key)
            sum += c;
        return sum % size;
    }

public:
    Hash(int size)
    {
        this->size = size;
        table = new list<pair<string, string>>[size];
    }

    void insert(string key, string value)
    {
        int hash = hashFunction(key);
        for (auto &p : table[hash])
        {
            if (p.first == key)
            {
                p.second = value;
                return;
            }
        }
        table[hash].push_back({key, value});
    }

    void remove(string key)
    {
        int hash = hashFunction(key);
        auto &lst = table[hash];
        for (auto it = lst.begin(); it != lst.end(); ++it)
        {
            if (it->first == key)
            {
                lst.erase(it);
                cout << "key " << key << " deleted successfully !" << endl;
                return;
            }
        }
        cout << "Key " << key << " not found!" << endl;
    }

    void search(string key)
    {
        int hash = hashFunction(key);
        for (auto &p : table[hash])
        {
            if (p.first == key)
            {
                cout << "search key " << key << ": " << p.second << endl;
                return;
            }
        }
        cout << "Error: " << key << " not found!" << endl;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            if (!table[i].empty())
            {
                cout << "index " << i << ": ";
                for (auto it = table[i].begin(); it != table[i].end(); ++it)
                {
                    cout << "(" << it->first << ", " << it->second << ")";
                    auto nextIt = it;
                    nextIt++;
                    if (nextIt != table[i].end())
                        cout << " -> ";
                }
                nl;
            }
        }
    }
};

int main()
{
    Hash dict(100);

    dict.insert("AB", "FASTNU");
    dict.insert("CD", "CS");
    dict.insert("EF", "ENGINEERING");
    dict.insert("GH", "MATH");

    dict.search("AB");
    dict.remove("EF");
    dict.display();
    dict.search("ZZ"); // non-existent key

    nl;
    return 0;
}