#include <bits/stdc++.h>
#define nl (cout << endl)
#define f(i, s, e) for (int i = s; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)
#define N 1000
using namespace std;

void bruteForceSearch(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    int count = 0;
    for (int i = 0; i  <= n - m; i++)
    {
        int j = 0;
        while (j < m && text[i + j] == pattern[j])
            j++;
        if (j == m){
            cout << "Parent found at index: " << i << endl;
            count++;
        }
    }
}   
int main()
{
    string text = "the quick brown fox jumps over the lazy dog";
    string pattern = "the";
    nl;
    bruteForceSearch(text, pattern);
    nl;
    return 0;
}