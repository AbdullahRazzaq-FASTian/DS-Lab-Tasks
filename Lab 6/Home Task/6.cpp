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
class Queue {
    Node<T>* front;
    Node<T>* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " added to message queue." << endl;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "No messages to process (Queue Underflow)." << endl;
            return;
        }
        cout << "Processing message: " << front->data << endl;
        Node<T>* temp = front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
    }

    void peek() {
        if (front == nullptr)
            cout << "No pending messages." << endl;
        else
            cout << "Next message to process: " << front->data << endl;
    }

    bool isEmpty() {
        return (front == nullptr);
    }
};

int main() {
    Queue<string> messages;
    nl;
    messages.enqueue("Hello");
    messages.enqueue("How are you?");
    messages.enqueue("Goodbye");
    messages.peek();
    messages.dequeue();
    messages.dequeue();
    messages.dequeue();
    messages.dequeue();
    nl;
    return 0;
}
