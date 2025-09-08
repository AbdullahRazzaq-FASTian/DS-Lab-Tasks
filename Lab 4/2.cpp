#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

void insertionSort(int nums[])
{
    int n = 9;
    for (int i = 1; i < n; i++)
    {
        int key = nums[i];
        int j = i;
        while (j > 0 && nums[j - 1] > key)
        {
            nums[j] = nums[j - 1];
            j--;
        }
        nums[j] = key;
    }
    int mid = n / 2;
    int key = nums[n - 1];
    for (int i = n-1; i >= mid + 1; i--)
        nums[i] = nums[i - 1];
    nums[mid] = key;
}

int main()
{
    int arr[9] = {20, 12, 15, 2, 10, 1, 13, 9, 5};
    cout << "\nBefore Sorting: ";
    for (int i = 0; i < 9; i++)
        cout << arr[i] << " ";
    nl;
    insertionSort(arr);
    cout << "\nAfter Sorting: ";
    for (int i = 0; i < 9; i++)
        cout << arr[i] << " ";
    nl;
    nl;
    return 0;
}