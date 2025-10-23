#include <bits/stdc++.h>
#include <windows.h>
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
    Node<T>* frontPtr;
    Node<T>* rearPtr;

public:
    Queue() {
        frontPtr = rearPtr = nullptr;
    }

    void enqueue(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (rearPtr == nullptr) {
            frontPtr = rearPtr = newNode;
        } else {
            rearPtr->next = newNode;
            rearPtr = newNode;
        }
    }

    void dequeue() {
        if (frontPtr == nullptr) return;
        Node<T>* temp = frontPtr;
        frontPtr = frontPtr->next;
        if (frontPtr == nullptr) rearPtr = nullptr;
        delete temp;
    }

    T front() {
        if (frontPtr == nullptr) throw runtime_error("Queue empty");
        return frontPtr->data;
    }

    bool isEmpty() {
        return (frontPtr == nullptr);
    }
};

class Patron {
public:
    string name;
    int serviceTime;
    Patron(string n = "", int t = 0) {
        name = n;
        serviceTime = t;
    }
};

class Staff {
public:
    bool busy;
    int remaining;
    Patron current;

    Staff() {
        busy = false;
        remaining = 0;
    }

    void assign(Patron p) {
        current = p;
        busy = true;
        remaining = p.serviceTime;
    }

    void work() {
        if (busy) {
            remaining--;
            if (remaining <= 0) busy = false;
        }
    }
};

void simulate(Queue<Patron>& line, Staff staff[], int totalStaff) {
    int time = 0;
    bool busyExist = true;

    while (!line.isEmpty() || busyExist) {
        busyExist = false;

        if (!line.isEmpty()) {
            for (int i = 0; i < totalStaff; i++) {
                if (!staff[i].busy && !line.isEmpty()) {
                    Patron p = line.front();
                    line.dequeue();
                    staff[i].assign(p);
                    cout << "Time " << time << ": Staff " << i+1 << " starts serving " << p.name << " for " << p.serviceTime << " mins\n";
                }
            }
        }

        Sleep(1000);
        nl;
        time++;

        for (int i = 0; i < totalStaff; i++) {
            if (staff[i].busy) {
                staff[i].work();
                busyExist = true;
                if (!staff[i].busy)
                    cout << "Time " << time << ": Staff " << i+1 << " finished serving " << staff[i].current.name << "\n";
            }
        }
    }
}

int main() {
    Queue<Patron> line;
    line.enqueue(Patron("Ali", 3));
    line.enqueue(Patron("Sara", 2));
    line.enqueue(Patron("Usman", 1));
    line.enqueue(Patron("Hina", 2));
    line.enqueue(Patron("Omar", 3));

    const int totalStaff = 4;
    Staff staff[totalStaff];
    nl;
    simulate(line, staff, totalStaff);
    nl;
}
