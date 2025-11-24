// 24K-0809
// 24K-0719
// 24K-0691
#include <bits/stdc++.h>
#define nl (cout << endl)
#define f(i, s, e) for (int i = s; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)
#define N 1000
using namespace std;

class MinHeap
{
    int size;
    int arr[N];

public:
    MinHeap() : size(-1) {}

    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int parent(int i) { return (i - 1) / 2; }
    int getSize() { return size + 1; }

    void heapifyUp(int i)
    {
        while (i > 0 && arr[i] < arr[parent(i)])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i)
    {
        int maxIndex = i;
        int l = left(i);
        int r = right(i);
        if (l < size && arr[l] < arr[i])
            maxIndex = l;
        if (r < size && arr[r] < arr[i])
            maxIndex = r;
        if (i != maxIndex)
        {
            swap(arr[i], arr[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

    void push(int val)
    {
        if (size < N)
        {
            size++;
            arr[size] = val;
            heapifyUp(size);
        }
    }

    int pop()
    {
        if (size >= 0)
        {
            int val = arr[0];
            arr[0] = arr[size];
            // cout << size << endl;
            size--;
            heapifyDown(0);
            return val;
        }
        return -1;
    }

    void print()
    {
        f(i, 0, size) cout << arr[i] << " ";
        nl;
    }
};

int main()
{
    MinHeap mn;
    mn.push(6);
    mn.push(8);
    mn.push(4);
    mn.push(5);
    mn.push(2);
    mn.push(3);
    // mn.print();
    // mn.pop();
    // mn.print();
    string a = "";
    string b = "";
    f(i,0,3){
        a += (mn.pop() + '0');
        b += (mn.pop() + '0');
    }
    int sum1 = stoi(a);
    int sum2 = stoi(b);
    cout << a << " " << b << endl;
    int sum = sum1 + sum2;
    cout << sum << endl;
    return 0;
}