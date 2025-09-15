#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

int helper(int *arr[], int size, int dim)
{
    if (size == 0)
        return 0;
    return arr[dim][size - 1] + helper(arr, size - 1, dim);
}

int recursiveArraySum(int *arr[], int sizes[], int dim)
{
    if (dim == 0)
        return 0;
    return helper(arr, sizes[dim - 1], dim - 1) + recursiveArraySum(arr, sizes, dim - 1);
}

int main()
{
    int dim = 3;
    int sizes[dim] = {2, 3, 1};
    int **arr = new int *[dim];
    // Allocating and Assigning random values
    int temp = 1;
    for (int i = 0; i < dim; i++)
    {
        arr[i] = new int[sizes[i]];
        for (int j = 0; j < sizes[i]; j++)
            arr[i][j] = temp++;
    }
    nl;
    cout << "Array elements: " << endl;
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < sizes[i]; j++)
            cout << arr[i][j] << " ";
        nl;
    }
    nl;
    cout << "Total sum: " << recursiveArraySum(arr, sizes, dim) << endl;
    nl;
    return 0;
}