#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

void selectionSort(int nums[])
{
    int n = 10;
    int minIndex;
    for (int i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[minIndex])
                minIndex = j;
        }
        swap(nums[i], nums[minIndex]);
    }
}

int main()
{
    int n = 10;
    int arr[10];
    cout << "\nEnter 10 elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    selectionSort(arr);
    int cnt = 1;
    cout << "\nFirst 4 minimum elements: " << arr[0] << " ";
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
            cnt++, cout << arr[i] << " ";
        if (cnt == 4)
            break;
    }
    nl;
    nl;
    return 0;
}