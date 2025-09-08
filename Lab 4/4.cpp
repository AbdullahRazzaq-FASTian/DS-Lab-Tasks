#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

void bubbleSort(int nums[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false; 
        for (int j = 0; j < n-i-1; j++)
        {
            if(nums[j] > nums[j+1]){
                swap(nums[j], nums[j+1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }
}

bool hasDuplicate(int arr[], int n) {
    bubbleSort(arr, n);

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1])
            return true;
    }
    return false;
}

int main() {
    int arr[] = {3, 5, 1, 7, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\nArray: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    nl;

    if (hasDuplicate(arr, n)) cout << "\nArray contains duplicates\n";
    else cout << "\nArray does not contain duplicates\n";
    nl;

    return 0;
}
