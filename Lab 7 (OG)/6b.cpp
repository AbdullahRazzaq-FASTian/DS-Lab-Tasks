#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int *L = new int[n1], *R = new int[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    delete[] L; delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeTwoSortedArrays(int arr1[], int n1, int arr2[], int n2, int result[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) result[k++] = arr1[i++];
        else result[k++] = arr2[j++];
    }
    while (i < n1) result[k++] = arr1[i++];
    while (j < n2) result[k++] = arr2[j++];
}

int main() {
    int arr1[10], arr2[10];
    cout << "Enter 10 elements for arr1:\n";
    for (int i = 0; i < 10; i++) cin >> arr1[i];
    cout << "Enter 10 elements for arr2:\n";
    for (int i = 0; i < 10; i++) cin >> arr2[i];

    mergeSort(arr1, 0, 9);
    mergeSort(arr2, 0, 9);

    int combined[20];
    mergeTwoSortedArrays(arr1, 10, arr2, 10, combined);

    cout << "\nCombined sorted array:\n";
    for (int i = 0; i < 20; i++) cout << combined[i] << " ";
}
