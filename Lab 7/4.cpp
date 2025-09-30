#include <bits/stdc++.h>
using namespace std;

class State {
public:
    int *cols;
    int *diag1;
    int *diag2;
    State(int n) : cols(new int[n]), diag1(new int[2 * n - 1]), diag2(new int[2 * n - 1]) {
        for (int i = 0; i < n; i++) cols[i] = 0;
        for (int i = 0; i < 2 * n - 1; i++) diag1[i] = diag2[i] = 0;
    }
    ~State() {
        delete[] cols;
        delete[] diag1;
        delete[] diag2;
    }
};

void printBoard(vector<int>& pos, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (pos[i] == j) cout << "Q ";
            else cout << "- ";
        }
        cout << endl;
    }
    cout << endl;
}

void solve(int i, int n, State &s, vector<int>& pos, vector<vector<int>>& allSolutions) {
    if (i == n) {
        allSolutions.push_back(pos);
        return;
    }
    for (int j = 0; j < n; j++) {
        if (s.cols[j] || s.diag1[i + j] || s.diag2[(n - 1) + (j - i)])
            continue;

        s.cols[j] = s.diag1[i + j] = s.diag2[(n - 1) + (j - i)] = 1;
        pos[i] = j;

        solve(i + 1, n, s, pos, allSolutions);

        s.cols[j] = s.diag1[i + j] = s.diag2[(n - 1) + (j - i)] = 0;
    }
}

void nQueens(int n) {
    State s(n);
    vector<int> pos(n, -1);
    vector<vector<int>> allSolutions;

    solve(0, n, s, pos, allSolutions);

    cout << "Number of solutions for N=" << n << ": " << allSolutions.size() << endl << endl;

    for (auto &sol : allSolutions) {
        printBoard(sol, n);
    }
}

int main() {
    int n = 4;
    nQueens(n);
    return 0;
}
