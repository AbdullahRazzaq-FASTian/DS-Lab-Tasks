#include <bits/stdc++.h>
#define nl (cout << endl)
#define f(i,s,e) for(int i=s;i<e;i++)
#define fr(i,s,e) for(int i=s;i>=e;i--)
#define N 1000
using namespace std;

class ExpressionHandler {
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }
    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }
public:
    string infixToPostfix(string infix) {
        stack<char> ops;
        string postfix = "";
        int len = infix.length();
        for (int i = 0; i < len; i++) {
            if (infix[i] == ' ') continue;
            if (isdigit(infix[i]) || infix[i] == '.') {
                while (i < len && (isdigit(infix[i]) || infix[i] == '.'))
                    postfix += infix[i++];
                postfix += ' ';
                i--;
            } else if (infix[i] == '(') ops.push('(');
            else if (infix[i] == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    postfix += ops.top(); postfix += ' '; ops.pop();
                }
                if (!ops.empty()) ops.pop();
            } else if (isOperator(infix[i])) {
                while (!ops.empty() && precedence(ops.top()) >= precedence(infix[i])) {
                    postfix += ops.top(); postfix += ' '; ops.pop();
                }
                ops.push(infix[i]);
            }
        }
        while (!ops.empty()) { postfix += ops.top(); postfix += ' '; ops.pop(); }
        return postfix;
    }

    double evaluatePostfix(string postfix) {
        stack<double> st;
        int len = postfix.length();
        for (int i = 0; i < len; i++) {
            if (postfix[i] == ' ') continue;
            if (isdigit(postfix[i]) || postfix[i] == '.') {
                string num = "";
                while (i < len && (isdigit(postfix[i]) || postfix[i] == '.'))
                    num += postfix[i++];
                st.push(stod(num)); i--;
            } else if (isOperator(postfix[i])) {
                double b = st.top(); st.pop();
                double a = st.top(); st.pop();
                switch (postfix[i]) {
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

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T value) { data = value; next = nullptr; }
};

template <typename T>
class Stack {
    Node<T>* top;
public:
    Stack() { top = nullptr; }
    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if (!top) return;
        Node<T>* temp = top;
        top = top->next;
        delete temp;
    }
    T peek() { return top->data; }
    bool isEmpty() { return top == nullptr; }
    void display() {
        Node<T>* temp = top;
        cout << "Stack top -> ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    string expr = "x=12+13-5*(0.5+0.5)+1";
    
    ExpressionHandler eH;
    Stack<string> st;
    char variable;
    
    f(i,0,expr.size()) if(expr[i] != ' ') { variable = expr[i]; break; }    // Have to find manually
    string rhs = expr.substr(expr.find('=') + 1);
    
    string postfix = eH.infixToPostfix(rhs);
    double result = eH.evaluatePostfix(postfix);

    st.push(to_string(result));
    st.push("=");
    st.push(string(1, variable));
    
    nl;
    st.display();
    nl;
}
