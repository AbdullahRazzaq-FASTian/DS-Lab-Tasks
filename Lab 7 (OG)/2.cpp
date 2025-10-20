#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

int getMax(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

void countingSort(int a[], int n, int place, bool isAscending)
{
    int output[n + 1];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(a[i] / place) % 10]++;

    if (isAscending)
    {
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
    }
    else
    {
        for (int i = 8; i >= 0; i--)
            count[i] += count[i + 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(a[i] / place) % 10] - 1] = a[i];
        count[(a[i] / place) % 10]--;
    }
    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

void radixsort(int a[], int n, bool isAscending = true)
{

    int max = getMax(a, n);

    for (int place = 1; max / place > 0; place *= 10)
        countingSort(a, n, place, isAscending);
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int a[] = {181, 289, 390, 121, 145, 736, 514, 888, 122};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "\nBefore sorting array elements are - \n";
    printArray(a, n);
    radixsort(a, n, true);
    cout << "\nAfter applying Radix sort in ascending order, the array elements are - \n";
    printArray(a, n);
    radixsort(a, n, false);
    cout << "\nAfter applying Radix sort in descending order, the array elements are - \n";
    printArray(a, n);
    nl;
}