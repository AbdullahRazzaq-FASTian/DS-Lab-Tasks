#include <bits/stdc++.h>
#define nl (cout << endl)
#define f(i, s, e) for (int i = s; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)
#define MAX 1000
using namespace std;

template <class T>
class myStack
{
    int top;

public:
    T a[MAX];
    myStack()
    {
        top = -1;
    }
    void push(T x)
    {
        if (top < (MAX - 1))
            a[++top] = x;
    }
    T pop()
    {
        if (top > 0)
            top--;
    }
    T peek()
    {
        if (top >= 0)
        {
            return a[top];
        }
    }
    bool isEmpty()
    {
        return (top < 0);
    }
};

bool checkPalindrome(string s)
{
    int n = (int)s.length();
    myStack<char> st;
    f(i, 0, n) st.push(s[i]);
    f(i, 0, n)
    {
        char c = st.peek();
        st.pop();
        if (c != s[i])
            return false;
    }
    return true;
}

int main()
{
    string s1 = "BORROWROB";
    string s2 = "BORRORROB";
    nl;
    cout << "String (" << s1 << ") " << (checkPalindrome(s1) ? "is Palindrome" : "is not Palindrome") << endl;
    nl;
    cout << "String (" << s2 << ") " << (checkPalindrome(s2) ? "is Palindrome" : "is not Palindrome") << endl;
    nl;
    return 0;
}