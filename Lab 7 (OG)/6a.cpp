#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main() {
    int arr1[10], arr2[10];
    cout << "Enter 10 elements for arr1:\n";
    for (int i = 0; i < 10; i++) cin >> arr1[i];
    cout << "Enter 10 elements for arr2:\n";
    for (int i = 0; i < 10; i++) cin >> arr2[i];

    int combined[20];
    for (int i = 0; i < 10; i++) combined[i] = arr1[i];
    for (int i = 0; i < 10; i++) combined[10 + i] = arr2[i];

    radixSort(combined, 20);

    cout << "\nCombined sorted array (Radix Sort):\n";
    for (int i = 0; i < 20; i++) cout << combined[i] << " ";
}
