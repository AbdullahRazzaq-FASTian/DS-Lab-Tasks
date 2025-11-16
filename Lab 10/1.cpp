#include <bits/stdc++.h>
#define nl (cout << endl)
#define f(i, s, e) for (int i = s; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)
#define N 1000
using namespace std;

class MinHeap
{
    int heap[N];
    int size;

public:
    MinHeap() : size(0) {}

    MinHeap(int arr[], int s) : size(s)
    {
        for (int i = 0; i < size; i++)
            heap[i] = arr[i];
        heapify();
    }

    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int parent(int i) { return (i - 1) / 2; }
    int getSize() { return size; }

    void heapify()
    {
        if (size <= 1)
            return;
        for (int i = parent(size - 1); i >= 0; i--)
            heapifyDown(i);
    }

    void heapifyDown(int i)
    {
        int idx = i;
        int l = left(i);
        int r = right(i);

        if (l < size && heap[l] < heap[idx])
            idx = l;
        if (r < size && heap[r] < heap[idx])
            idx = r;

        if (idx != i)
        {
            swap(heap[i], heap[idx]);
            heapifyDown(idx);
        }
    }

    void heapifyUp(int i)
    {
        while (i > 0 && heap[i] < heap[parent(i)])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    bool empty() { return size == 0; }

    void insert(int val)
    {
        if (size >= N)
            return;
        heap[size] = val;
        heapifyUp(size);
        size++;
    }

    void update(int i, int newVal)
    {
        if (i >= 0 && i < size)
        {
            int oldVal = heap[i];
            heap[i] = newVal;
            if (newVal < oldVal)
                heapifyUp(i);
            else
                heapifyDown(i);
        }
    }

    int remove()
    {
        if (size == 0)
            return -1;

        int root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);

        return root;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << "\n";
    }
};

class MaxHeap
{
    int heap[N];
    int size;

public:
    MaxHeap() : size(0) {}

    MaxHeap(int arr[], int s) : size(s)
    {
        for (int i = 0; i < size; i++)
            heap[i] = arr[i];
        heapify();
    }

    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int parent(int i) { return (i - 1) / 2; }
    int getSize() { return size; }

    void heapify()
    {
        if (size <= 1)
            return;
        for (int i = parent(size - 1); i >= 0; i--)
            heapifyDown(i);
    }

    void heapifyDown(int i)
    {
        int idx = i;
        int l = left(i);
        int r = right(i);

        if (l < size && heap[l] > heap[idx])
            idx = l;
        if (r < size && heap[r] > heap[idx])
            idx = r;

        if (idx != i)
        {
            swap(heap[i], heap[idx]);
            heapifyDown(idx);
        }
    }

    void heapifyUp(int i)
    {
        while (i > 0 && heap[i] > heap[parent(i)])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    bool empty() { return size == 0; }

    void insert(int val)
    {
        if (size >= N)
            return;
        heap[size] = val;
        heapifyUp(size);
        size++;
    }

    void update(int i, int newVal)
    {
        if (i >= 0 && i < size)
        {
            int oldVal = heap[i];
            heap[i] = newVal;
            if (newVal > oldVal)
                heapifyUp(i);
            else
                heapifyDown(i);
        }
    }

    int remove()
    {
        if (size == 0)
            return -1;

        int root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);

        return root;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << "\n";
    }
};

int main()
{
    int arr[] = {3, 2, 1, 4, 7, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    MinHeap mn(arr, n);
    MaxHeap mx(arr, n);
    cout << "Array to Heap" << endl;
    cout << "Min Heap: ";
    mn.print();
    cout << "Max Heap: ";
    mx.print();
    nl;

    mn.insert(10);
    mx.insert(10);
    cout << "Inserting a new value to Heap" << endl;
    cout << "Min Heap: ";
    mn.print();
    cout << "Max Heap: ";
    mx.print();
    nl;

    mn.update(4, 8);
    mx.update(4, 8);
    cout << "Updating 4th value to Heap" << endl;
    cout << "Min Heap: ";
    mn.print();
    cout << "Max Heap: ";
    mx.print();
    nl;

    mn.remove();
    mx.remove();
    cout << "Removing a value to Heap" << endl;
    cout << "Min Heap: ";
    mn.print();
    cout << "Max Heap: ";
    mx.print();
    nl;
    return 0;
}