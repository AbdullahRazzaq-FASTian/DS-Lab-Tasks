#include <bits/stdc++.h>
#define N 1000
#define nl (cout << endl;)
#define f(i, s, e) for (int i = s; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)
using namespace std;

class myStack
{
    int top = -1;
    int size = 0;
    char arr[N];

public:
    myStack() {}
    int getSize() { return top + 1; }
    bool isEmpty() { return getSize() <= 0; }
    void push(char ch)
    {
        if (getSize() == N)
            __throw_runtime_error("Stack Overflow");
        arr[++top] = ch;
    }
    void pop()
    {
        if (top == -1)
            __throw_runtime_error("Stack Underflow");
        top--;
    }
    char peek()
    {
        if (top == -1)
            __throw_runtime_error("Stack Underflow");
        return arr[top];
    }
};

bool validate(string text, string pattern)
{
    // Assuming pattern to be of size 2
    myStack st;
    int n = (int)text.length();
    for (int i = 0; i < n; i++)
    {
        if(text[i] == pattern[0]) st.push(text[i]);
        else if(text[i] == pattern[1]){
            if(st.isEmpty()) return false;
            else st.pop();
        }
    }
    if(st.isEmpty()) return true;
    else return false;
}

int main()
{
    string text = "(a + b)";
    string pattern = "()";
    cout << (validate(text, pattern) ? "VALID" : "NOT VALID") << endl;
    text = "(a + b";
    cout << (validate(text, pattern) ? "VALID" : "NOT VALID") << endl;
    return 0;
}