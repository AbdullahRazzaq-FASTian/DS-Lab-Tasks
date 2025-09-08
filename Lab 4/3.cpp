#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

void bubbleSort(string arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] >= arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int main()
{
    string arr[] = {"banana", "apple", "cherry", "date", "grape"};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "\nBefore Sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    nl;
    bubbleSort(arr, n);
    cout << "\nAfter Sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    nl;
    nl;
    return 0;
}