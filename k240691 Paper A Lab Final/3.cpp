#include <bits/stdc++.h>
#define m 10
#define N 1000
#define nl (cout << endl;)
#define f(i, s, e) for (int i = s; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)
using namespace std;

struct Node
{
    int id;
    string submission;
    Node *next = nullptr;
    Node(int id, string submission) : id(id), submission(submission), next(nullptr) {}
};

struct Record
{
    int hash;
    int frequency;
    int distinct;
    Record() {}
    Record(int hash, int frequency, int distinct) : hash(hash), frequency(frequency), distinct(distinct) {}
};

int merge(Record arr[], int low, int mid, int high)
{
    int n = high - low + 1;
    Record temp[n];
    int k = 0;
    int i = low, j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (arr[i].frequency > arr[j].frequency)
        {
            temp[k].hash = arr[i].hash;
            temp[k].frequency = arr[i].frequency;
            temp[k].distinct = arr[i].distinct;
            i++;
        }
        else if (arr[i].frequency == arr[j].frequency && arr[i].distinct > arr[j].distinct)
        {
            temp[k].hash = arr[i].hash;
            temp[k].frequency = arr[i].frequency;
            temp[k].distinct = arr[i].distinct;
            i++;
        }
        else if (arr[i].frequency == arr[j].frequency && arr[i].distinct == arr[j].distinct && arr[i].hash <= arr[j].hash)
        {
            temp[k].hash = arr[i].hash;
            temp[k].frequency = arr[i].frequency;
            temp[k].distinct = arr[i].distinct;
            i++;
        }
        else
        {
            temp[k].hash = arr[j].hash;
            temp[k].frequency = arr[j].frequency;
            temp[k].distinct = arr[j].distinct;
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k].hash = arr[i].hash;
        temp[k].frequency = arr[i].frequency;
        temp[k].distinct = arr[i].distinct;
        i++;
        k++;
    }
    while (j <= high)
    {
        temp[k].hash = arr[j].hash;
        temp[k].frequency = arr[j].frequency;
        temp[k].distinct = arr[j].distinct;
        j++;
        k++;
    }
    i = low;
    while(i < n){
        arr[i].hash = temp[i - low].hash;
        arr[i].frequency = temp[i - low].frequency;
        arr[i].distinct = temp[i - low].distinct;
    }
}

void mergeSort(Record arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

class HashTable
{
    Node *table[m];
    int freq[m] = {0};
    int dist[m] = {0};

    int hashFunction(int id)
    {
        return id % m;
    }

public:
    void insert(int id, string submission)
    {
        int hash = hashFunction(id);
        Node *newNode = new Node(id, submission);
        Node *cur = table[hash];
        while (cur && cur->id != id)
            cur = cur->next;
        if (cur && cur->id == id)
        {
            // Already submitted
            newNode->next = table[hash];
            table[hash] = newNode;
            freq[hash]++; // Only increment frequency
        }
        else
        {
            newNode->next = table[hash];
            table[hash] = newNode;
            freq[hash]++;
            dist[hash]++;
        }
        return;
    }

    void detectSuspicious(int k, int d)
    {
        Record arr[N];
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            if (freq[i] >= k && dist[i] >= d)
            {
                arr[cnt].hash = i;
                arr[cnt].frequency = freq[i];
                arr[cnt].distinct = dist[i];
                cnt++;
            }
        }

        if (cnt == 0)
        {
            cout << "No suspicion found" << endl;
            return;
        }

        // Before sorting
        for (int i = 0; i < cnt; i++)
        {
            cout << "Hash: " << arr[i].hash << ", Frequency: " << arr[i].frequency << ", Disntinct Students: " << arr[i].distinct << endl;
        }
        
        mergeSort(arr, 0, cnt-1);

        // After sorting
        for (int i = 0; i < cnt; i++)
        {
            cout << "Hash: " << arr[i].hash << ", Frequency: " << arr[i].frequency << ", Disntinct Students: " << arr[i].distinct << endl;
        }
    }

    ~HashTable()
    {
        for (int i = 0; i < m; i++)
        {
            Node *cur = table[i];
            while (cur && cur->next)
            {
                Node *next = cur;
                delete cur;
                cur = next;
            }
            table[i] = nullptr;
        }
    }
};

int main()
{
    HashTable ht;
    ht.insert(3, "abc");
    ht.detectSuspicious(3, 2);
    return 0;
}