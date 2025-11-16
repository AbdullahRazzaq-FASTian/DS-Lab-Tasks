#include <bits/stdc++.h>
#define nl (cout << endl)
#define f(i, s, e) for (int i = s; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)
#define N 1000
using namespace std;

bool check(int arr[], int n)
{
    bool isMin = true, isMax = true;

    for (int i = 0; i <= (n - 2) / 2; i++)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[i] > arr[left])
            isMin = false;
        if (right < n && arr[i] > arr[right])
            isMin = false;

        if (left < n && arr[i] < arr[left])
            isMax = false;
        if (right < n && arr[i] < arr[right])
            isMax = false;
    }

    return isMin || isMax;
}

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

void heapSort(int arr[], int n)
{
    fr(i, (n - 2) / 2, 0)
        heapifyDown(arr, n, i);
    fr(i, n-1, 1){
        swap(arr[0], arr[i]);
        heapifyDown(arr, i, 0);
    }
}

int main()
{
    int arr[] = {3, 2, 1, 4, 7, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    nl;
    cout << "Before sorting: ";
    f(i,0,n) cout << arr[i] << " ";
    nl;
    heapSort(arr, n);
    cout << "After sorting:  ";
    f(i,0,n) cout << arr[i] << " ";
    nl;
    nl;
    return 0;
}