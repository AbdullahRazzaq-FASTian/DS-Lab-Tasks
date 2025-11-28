#include <bits/stdc++.h>
#define nl (cout << endl)
#define f(i, s, e) for (int i = s; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)
using namespace std;

void prefixFunction(string pattern, int pi[]) {
    int m = pattern.length();
    pi[0] = 0;
    f(i,1,m) {
        int j = pi[i-1];
        while(j > 0 && pattern[i] != pattern[j]) j = pi[j-1];
        if(pattern[i] == pattern[j]) j++;
        pi[i] = j;
    }
}

int main() {
    string text = "ababababc";
    string pattern = "abab";
    int n = text.length();
    int m = pattern.length();
    int pi[m];
    prefixFunction(pattern, pi);

    int positions[n];
    int posCount = 0;

    int j = 0;
    f(i,0,n) {
        while(j > 0 && text[i] != pattern[j]) j = pi[j-1];
        if(text[i] == pattern[j]) j++;
        if(j == m) {
            positions[posCount++] = i - m + 1;
            j = pi[j-1];
        }
    }

    cout << "\n[";
    f(i,0,posCount) {
        if(i>0) cout << ", ";
        cout << positions[i];
    }
    cout << "]\nS" << endl;
}
