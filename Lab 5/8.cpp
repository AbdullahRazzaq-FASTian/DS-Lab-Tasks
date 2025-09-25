#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class State
{
public:
    int *rows;
    int *cols;
    int *diag1;
    int *diag2;
    State(int n) : rows(new int[n]), cols(new int[n]), diag1(new int[2 * n - 1]), diag2(new int[2 * n - 1])
    {
        for (int i = 0; i < n; i++)
            rows[i] = cols[i] = 0;
        for (int i = 0; i < 2 * n - 1; i++)
            diag1[i] = diag2[i] = 0;
    }
    ~State()
    {
        delete[] cols;
        delete[] diag1;
        delete[] diag2;
    }
};

void find(int i, int n, State &s, int cnt, int &maxCnt)
{
    maxCnt = max(maxCnt, cnt);
    if (i == n)
        return;
    for (int j = 0; j < n; j++)
    {
        if (s.cols[j] || s.diag1[i + j] || s.diag2[(n - 1) + (j - i)])
            continue;
        s.cols[j] = s.diag1[i + j] = s.diag2[(n - 1) + (j - i)] = 1;
        find(i + 1, n, s, cnt + 1, maxCnt);
        s.cols[j] = s.diag1[i + j] = s.diag2[(n - 1) + (j - i)] = 0;
    }
}

int numberOfFlags(int n)
{
    State flags(n);
    int maxCnt = 0;
    find(0, n, flags, 0, maxCnt);
    return maxCnt;
}

int main()
{
    nl;
    cout << "Maximum flags that can be collected for Grid of size 1: " << numberOfFlags(1) << endl;
    cout << "Maximum flags that can be collected for Grid of size 2: " << numberOfFlags(2) << endl;
    cout << "Maximum flags that can be collected for Grid of size 3: " << numberOfFlags(3) << endl;
    cout << "Maximum flags that can be collected for Grid of size 4: " << numberOfFlags(4) << endl;
    cout << "Maximum flags that can be collected for Grid of size 5: " << numberOfFlags(5) << endl;
    nl;
    return 0;
}