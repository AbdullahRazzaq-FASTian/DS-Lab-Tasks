#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

void countSort(int arr[], int n, int exp)
{
    int digit, output[n], count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        digit = (arr[i] / exp) % 10;
        count[digit]++;
    }
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n-1; i >= 0; i--)
    {
        digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n)
{
    // Maximum Digit = 4, therefore max exp = 1000
    for (int exp = 1; exp <= 1000; exp *= 10)
        countSort(arr, n, exp);
}

int main()
{
    int arr[] = {2022, 2023, 2024, 2022, 2023, 2024};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "\nBefore Sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    nl;
    radixSort(arr, n);
    cout << "\nAfter Sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    nl;
    nl;
    return 0;
}