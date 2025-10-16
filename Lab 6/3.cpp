#include <bits/stdc++.h>
#define nl (cout << endl)
#define f(i, s, e) for (int i = s; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)
using namespace std;

const int MAX_ITEMS = 50;

class Order {
public:
    int orderID;
    pair<string, int> items[MAX_ITEMS];
    int itemCount;

    Order() {
        orderID = 0;
        itemCount = 0;
    }

    void print() {
        cout << "Order ID: " << orderID << endl;
        f(i, 0, itemCount) {
            cout << "Item: " << items[i].first << ", Quantity: " << items[i].second << endl;
        }
        nl;
    }
};

struct Node {
    Order data;
    Node* next;

    Node(Order val) {
        data = val;
        next = nullptr;
    }
};

class OrderQueue {
    Node* front;
    Node* rear;
    int currentID;

public:
    OrderQueue() {
        front = rear = nullptr;
        currentID = 1;
    }

    void enqueue(Order o) {
        // The processed order is given some ID
        o.orderID = currentID++;
        Node* newNode = new Node(o);

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    Order dequeue() {
        if (front == nullptr) {
            return Order();
        }

        Node* temp = front;
        Order result = temp->data;
        front = front->next;

        if (front == nullptr) rear = nullptr;

        delete temp;
        return result;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void printAllOrders() {
        Node* current = front;
        while (current != nullptr) {
            current->data.print();
            current = current->next;
        }
    }
};

int main() {
    OrderQueue q;

    Order o1;
    o1.items[0] = {"Burger", 2};
    o1.items[1] = {"Fries", 1};
    o1.itemCount = 2;
    q.enqueue(o1);

    Order o2;
    o2.items[0] = {"Pizza", 1};
    o2.items[1] = {"Cola", 2};
    o2.itemCount = 2;
    q.enqueue(o2);

    Order o3;
    o3.items[0] = {"Nuggets", 3};
    o3.items[1] = {"Juice", 1};
    o3.itemCount = 2;
    q.enqueue(o3);

    cout << "\nAll Orders in Queue:" << endl;
    q.printAllOrders();

    cout << "Dequeued (Processed) Order:" << endl;
    Order served = q.dequeue();
    served.print();

    cout << "Remaining Orders in Queue:" << endl;
    q.printAllOrders();

    return 0;
}
