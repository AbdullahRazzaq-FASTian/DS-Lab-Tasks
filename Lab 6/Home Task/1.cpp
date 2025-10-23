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

int main()
{
    myStack<string> toDoList;
    // Adding itme on top of Stack
    toDoList.push("Do DS Lab 6 Home-Tasks.");
    // Check if Stack is Empty
    cout << "List having an item." << endl;
    cout << "List is " << (toDoList.isEmpty()? "empty" : "not empty.") << endl;
    // Remove item from the Stack(list)
    toDoList.pop();
    cout << "List having no item." << endl;
    // Check if Stack is Empty
    cout << "List is " << (toDoList.isEmpty()? "empty" : "not empty.") << endl;
    return 0;
}