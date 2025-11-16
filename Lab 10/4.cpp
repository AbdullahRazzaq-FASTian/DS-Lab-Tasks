#include <bits/stdc++.h>
#define nl (cout << endl)
#define f(i, s, e) for (int i = s; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)
#define N 1000
using namespace std;

void heapifyDown(int arr[], int n, int i)
{
    int idx = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[idx])
        idx = l;
    if (r < n && arr[r] > arr[idx])
        idx = r;

    if (idx != i)
    {
        swap(arr[i], arr[idx]);
        heapifyDown(arr, n, idx);
    }
}

void min2max(int arr[], int n)
{
    fr(i, (n - 2) / 2, 0)
        heapifyDown(arr, n, i);
}

int main()
{
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    nl;
    cout << "Before converting: ";
    f(i, 0, n) cout << arr[i] << " ";
    nl;
    min2max(arr, n);
    cout << "After converting:  ";
    f(i, 0, n) cout << arr[i] << " ";
    nl;
    nl;
    return 0;
}