#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

int main()
{   
    int rows;
    cout << "Enter No. of Rows: ", cin >> rows;
    int size[rows];
    int **arr = new int *[rows];
    for (int i = 0; i < rows; i++){
        cout << "Enter Size of Row: ", cin >> size[i];
        arr[i] = new int[size[i]];
        cout << "Enter elements: ";
        for(int j=0; j<size[i]; j++){
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < size[i]; j++)
            cout << arr[i][j] << " ";
        nl;
    }

    for (int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}