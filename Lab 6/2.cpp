#include <bits/stdc++.h>
#define nl (cout << endl)
#define f(i, s, e) for (int i = s; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)
using namespace std;

class Transaction
{
public:
    int transactionID;
    double amount;
    string description;
    bool flag;
    Transaction()
    {
        transactionID = 0;
        amount = 0;
        description = "";
        flag = 1;
    }
    Transaction(int id, double amt, string desc)
    {
        transactionID = id;
        amount = amt;
        description = desc;
        flag = (amount >= 0) ? 1 : 0;
    }
    void print() {
        cout << "ID: " << transactionID << endl;
        cout << "Amount: " << amount << endl;
        cout << "Description: " << description << endl;
        cout << "Type: " << (flag ? "Sale" : "Refund") << endl;
        nl;
    }
};

struct Node
{
    Transaction data;
    Node *next;
    Node(Transaction value) : data(value), next(nullptr) {}
};

class myStack
{
    Node *top;
    int currentID;

public:
    myStack() : top(nullptr), currentID(1) {}

    void push(Transaction x)
    {
        x.transactionID = currentID++;
        if (x.description.length() > 20)
        {
            x.description = x.description.substr(0, 17) + "...";
        }
        if (x.amount >= 0)
        {
            if (x.amount >= 1500)
                x.amount *= 0.7;
            else if (x.amount >= 1000)
                x.amount *= 0.85;
            else if (x.amount >= 500)
                x.amount *= 0.95;
        }
        x.flag = (x.amount >= 0) ? 1 : 0;
        Node *newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    Transaction pop()
    {
        if (top != nullptr)
        {
            Transaction t = top->data;
            Node *temp = top;
            top = top->next;
            delete temp;
            t.amount *= -1;
            t.description += " [REVERSED]";
            t.flag = (t.amount >= 0) ? 1 : 0;
            return t;
        }
        return Transaction();
    }

    Transaction peek()
    {
        if (top != nullptr)
        {
            return top->data;
        }
        return Transaction();
    }

    bool isEmpty()
    {
        return top == nullptr;
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
    srand(time(0));
    myStack s;
    Transaction transactions[7] = {
        Transaction(1, 1200, "Sale: Blue Jacket"),
        Transaction(2, 450, "Sale: Cotton Socks"),
        Transaction(3, -300, "Refund: Defective Shirt"),
        Transaction(4, 1700, "Sale: Leather Jacket"),
        Transaction(5, -150, "Refund: Color Fade Issue"),
        Transaction(6, 800, "Sale: Winter Gloves"),
        Transaction(7, -500, "Refund: Size Mismatch")
    };

    int N = 5;
    int ran[N]; // Tracks random indexes selected
    f(i, 0, N)
    {
        int idx = rand() % 7;   // Select Random Transactions
        ran[i] = idx;
        s.push(transactions[idx]);
    }
    Transaction reversed[N];
    int cnt = N-1;
    while (!s.isEmpty())
    {
        reversed[cnt] = s.pop();
        cnt--;
    }
    
    f(i, 0, N){
        transactions[ran[i]].print();
    }
    f(i, 0, N){
        reversed[i].print();
    }

    expressionHandler eH;

    string inf = "(100 + 20) * 0.9 - 5";
    string post = eH.infixToPostfix(inf);
    double result = eH.evaluatePostfix(post);

    nl;
    cout << "Original Expression (Infix): " << inf << endl;
    cout << "Compiled Expression (Postfix): " << post << endl;
    cout << fixed << setprecision(2) << "Evaluated Expression: " << result << endl;
    nl;

    return 0;
}
