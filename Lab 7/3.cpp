#include <bits/stdc++.h>
#define nl (cout << endl)
#define n 4
using namespace std;

void print(int sol[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << " " << sol[i][j] << " ";
        nl;
    }
}

bool canMove(int maze[n][n], int row, int col){
    return (row >= 0 && row < n && col >= 0 && col < n && maze[row][col] == 1);
}

bool helper(int maze[n][n], int row, int col, int sol[n][n]) {
    if (row == n - 1 && col == n - 1 && maze[row][col] == 1) {
        sol[row][col] = 1;
        return true;
    }
    if(!canMove(maze, row, col))
        return false;
    if(sol[row][col] == 1)
        return false;
    sol[row][col] = 1;
    if(helper(maze, row+1, col, sol)){
        return true;
    }
    if(helper(maze, row, col+1, sol)){
        return true;
    }
    if(helper(maze, row-1, col, sol)){
        return true;
    }
    if(helper(maze, row, col-1, sol)){
        return true;
    }
    sol[row][col] = 0;
    return false;
}

void solve(int maze[n][n])
{
    int sol[n][n] = {{0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0}};
    if (helper(maze, 0, 0, sol))
        print(sol);
    else
        cout << "Solution doesn't exist" << endl;
}

int main()
{
    int maze[n][n] = {{1, 1, 1, 1},
                      {0, 0, 0, 1},
                      {1, 1, 0, 1},
                      {1, 1, 1, 1}};
    nl;
    solve(maze);
    nl;

    return 0;
}