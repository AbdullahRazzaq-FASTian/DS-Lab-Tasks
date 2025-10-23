#include <bits/stdc++.h>
#define nl (cout << endl)
#define f(i,s,e) for(int i=s;i<e;i++)
#define fr(i,s,e) for(int i=s;i>=e;i--)
#define N 1000
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) {
        data = value;
        next = nullptr;
    }
};

template <typename T>
class Browser {
    Node<T>* top;

public:
    Browser() {
        top = nullptr;
    }

    void visit(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
    }

    void back() {
        if(!top) return;
        Node<T>* temp = top;
        top = top->next;
        delete temp;
    }

    T current() {
        if (top) {
            return top->data;
        }
    }

    bool isEmpty() {
        return (top == nullptr);
    }
};

int main()
{
    Browser<string> myWebBrowser;
    myWebBrowser.visit("www.google.com");
    myWebBrowser.visit("www.facebook.com");
    myWebBrowser.visit("www.twitter.com");
    myWebBrowser.visit("www.linkedin.com");
    myWebBrowser.visit("www.instagram.com");
    
    cout << "Current Web Page: " << myWebBrowser.current() << endl;

    myWebBrowser.back();
    myWebBrowser.back();

    cout << "Current Web Page: " << myWebBrowser.current() << endl;

    return 0;
}