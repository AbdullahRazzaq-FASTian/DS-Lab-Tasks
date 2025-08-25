#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Matrix
{
    int **mat = nullptr;
    int rows, cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols)
    {
        mat = new int *[rows];
        cout << "Enter Matrix Elements: " << endl;
        for (int i = 0; i < rows; i++)
        {
            mat[i] = new int[cols];
            for (int j = 0; j < cols; j++)
                cin >> mat[i][j];
        }
    }
    void resize(int newRows, int newCols, int val = 0)
    {
        int **temp = new int *[newRows];
        for (int i = 0; i < min(rows, newRows); i++)
        {
            temp[i] = new int[newCols];
            for (int j = 0; j < min(cols, newCols); j++)
                temp[i][j] = mat[i][j];
        }
        if(newCols > cols){
            for (int i = 0; i < newRows; i++)
                for (int j = cols; j < newCols; j++)
                    temp[i][j] = val;
        }
        if(newRows > rows){
            for (int i = rows; i < newRows; i++)
                for (int j = 0; j < newCols; j++)
                    temp[i][j] = val;
        }
    }
    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
            delete[] mat[i];
        delete[] mat;
    }
};

int main()
{

    return 0;
}