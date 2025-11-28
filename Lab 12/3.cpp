#include <bits/stdc++.h>
#define nl (cout << endl)
#define f(i, s, e) for (int i = s; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)
using namespace std;

#define NO_OF_CHARS 256

void badCharHeuristic(string pattern, int badChar[]) {
    f(i,0,NO_OF_CHARS) badChar[i] = -1;
    f(i,0,pattern.length()) badChar[(int)pattern[i]] = i;
}

void boyerMooreSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int badChar[NO_OF_CHARS];
    badCharHeuristic(pattern, badChar);

    int s = 0;
    while(s <= n - m) {
        int j = m - 1;
        while(j >= 0 && pattern[j] == text[s + j]) j--;
        if(j < 0) {
            cout << "Pattern found at index " << s << endl;
            s += (s + m < n) ? m - badChar[(int)text[s + m]] : 1;
        } else {
            int shift = max(1, j - badChar[(int)text[s + j]]);
            s += shift;
        }
    }
}

int main() {
    string text = "ACGTACGTGACG";
    string pattern = "ACGS";
    nl;
    boyerMooreSearch(text, pattern);
    nl;
}
