#include <bits/stdc++.h>
#define nl (cout << endl)
#define f(i,s,e) for(int i=s;i<e;i++)
#define fr(i,s,e) for(int i=s;i>=e;i--)
#define N 1000
using namespace std;

template <class T>
class myStack
{
    int top;

public:
    T a[N];
    myStack()
    {
        top = -1;
    }
    void push(T x)
    {
        if (top < (N - 1))
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

class expressionHandler
{
    int precedence(char op)
    {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }
    bool isOperator(char c)
    {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

public:
    string infixToPostfix(string infix)
    {
        stack<char> ops;
        string postfix = "";
        int len = infix.length();
        for (int i = 0; i < len; i++)
        {
            if (infix[i] == ' ') continue;
            if (isdigit(infix[i]) || infix[i] == '.')
            {
                while (i < len && (isdigit(infix[i]) || infix[i] == '.'))
                {
                    postfix += infix[i++];
                }
                postfix += ' ';
                i--;
            }
            else if (infix[i] == '(')
            {
                ops.push('(');
            }
            else if (infix[i] == ')')
            {
                while (!ops.empty() && ops.top() != '(')
                {
                    postfix += ops.top();
                    postfix += ' ';
                    ops.pop();
                }
                if (!ops.empty()) ops.pop();
            }
            else if (isOperator(infix[i]))
            {
                while (!ops.empty() && precedence(ops.top()) >= precedence(infix[i]))
                {
                    postfix += ops.top();
                    postfix += ' ';
                    ops.pop();
                }
                ops.push(infix[i]);
            }
        }
        while (!ops.empty())
        {
            postfix += ops.top();
            postfix += ' ';
            ops.pop();
        }

        return postfix;
    }

    double evaluatePostfix(string postfix)
    {
        stack<double> st;
        int len = postfix.length();
        for (int i = 0; i < len; i++)
        {
            if (postfix[i] == ' ') continue;
            if (isdigit(postfix[i]) || postfix[i] == '.')
            {
                string num = "";
                while (i < len && (isdigit(postfix[i]) || postfix[i] == '.'))
                {
                    num += postfix[i++];
                }
                st.push(stod(num));
                i--;
            }
            else if (isOperator(postfix[i]))
            {
                double b = st.top(); st.pop();
                double a = st.top(); st.pop();
                switch (postfix[i])
                {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
                }
            }
        }

        return st.top();
    }
};

int main()
{
    expressionHandler eH;
    string exp = "(9 / 4 + 9 * 4) + (9 * 4 + 9 / 4)";
    string inf(exp);
    string post = eH.infixToPostfix(inf);
    double result = eH.evaluatePostfix(post);

    nl;
    cout << "Original Expression (Infix): " << inf << endl;
    cout << "Compiled Expression (Postfix): " << post << endl;
    cout << fixed << setprecision(2) << "Evaluated Expression: " << result << endl;
    nl;
    
    return 0;
}