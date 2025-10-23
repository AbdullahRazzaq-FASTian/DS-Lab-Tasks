#include <bits/stdc++.h>
#define nl (cout << endl)
#define f(i,s,e) for(int i=s;i<e;i++)
#define fr(i,s,e) for(int i=s;i>=e;i--)
#define N 1000
using namespace std;

template <typename T>
class myQueue
{
    int f, r;
    T *arr = nullptr;
    size_t size;

public:
    myQueue(size_t size) : size(size)
    {
        f = r = -1;
        arr = new T[size];
    }
    bool isFull() { return r == (int)size - 1; }
    bool isEmpty() { return f == -1 || f > r; }
    void enqueue(T data)
    {
        if (!isFull())
        {
            if (f == -1)
                f = 0;
            arr[++r] = data;
        }
    }
    void dequeue() { 
        if(!isEmpty()) {
            cout << "Customer "<< arr[f] << " checked out" << endl;
            f++; 
        }
    }
    T front(){ 
        if(!isEmpty()) return arr[f];
        else throw runtime_error("Queue is empty");
    }
    void printQueue(){
        if(f > -1 && r > -1){
            f(i,f,r+1){
                cout << arr[i] << " ";
            }
            nl;
        }
    }
    ~myQueue() { delete[] arr; }
};

int main()
{
    myQueue<int> cashier(N);
    cashier.enqueue(13);
    cashier.enqueue(7);
    cashier.enqueue(4);
    cashier.enqueue(1);
    cashier.enqueue(6);

    cout << "Queue after enqueuing: ";
    cashier.printQueue();
    
    cashier.dequeue();
    cout << "Queue now: ";
    cashier.printQueue();
    
    cashier.dequeue();
    cout << "Queue now: ";
    cashier.printQueue();

    return 0;
}