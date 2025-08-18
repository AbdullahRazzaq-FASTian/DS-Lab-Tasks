#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

int main()
{
    int *ptr = new int[1];
    *ptr = 1;
    cout << ptr << endl;
    cout << *ptr << endl;
    delete ptr;
    cout << ptr << endl;
    cout << *ptr << endl;
    return 0;
}