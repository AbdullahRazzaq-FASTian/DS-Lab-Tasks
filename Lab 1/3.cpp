#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Box
{
public:
    int *x = nullptr;
    Box(int x = 0) { this->x = new int(x); }
    // Shallow Copy
    Box(const Box &b) { x = b.x; }
    // Deep Copy
    // Box(const Box &b) { x = new int(*(b.x)); }
    Box &operator=(const Box &b)
    {
        x = new int(*(b.x));
        return *this;
    }
    void set(int x) { *this->x = x; }
    ~Box() { delete x; }
};

int main()
{
    cout << "Example 1: Shallow Copy" << endl;
    Box b1(11);
    Box b2(b1);
    cout << "Before Modifying" << endl;
    cout << "Box 1: " << *b1.x << endl;
    cout << "Box 2: " << *b2.x << endl;
    b2.set(12);
    cout << "After Modifying" << endl;
    cout << "Box 1: " << *b1.x << endl;
    cout << "Box 2: " << *b2.x << endl;

    cout << "Example 2: Deep Copy Assignment Operator" << endl;
    Box b3(99);
    Box b4;
    b4 = b3;
    cout << "Before Modifying" << endl;
    cout << "Box 3: " << *b3.x << endl;
    cout << "Box 4: " << *b4.x << endl;
    cout << "After Modifying" << endl;
    b4.set(100);
    cout << "Box 3: " << *b3.x << endl;
    cout << "Box 4: " << *b4.x << endl;
    return 0;
}