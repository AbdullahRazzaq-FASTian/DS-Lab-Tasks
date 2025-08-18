#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Product
{
public:
    string name;
    double price;
    int stock;

    Product() {}
    Product(string name, double price, int stock)
        : name(name), price(price), stock(stock) {}
    void display()
    {
        cout << "Product Name: " << name << endl;
        cout << "Product Price: " << price << endl;
        cout << "Product Stock: " << stock << endl;
    }
};

class Bundle
{
public:
    Product *productList = nullptr;
    int *count = nullptr;
    int capacity;
    double discount;

    Bundle(double discount)
        : discount(discount), count(new int(0)), capacity(10)
    {
        productList = new Product[capacity];
    }

    // Shallow Copy
    // Bundle(const Bundle &b)
    // {
    //     productList = b.productList;
    //     count = b.count;
    //     capacity = b.capacity;
    //     discount = b.discount;
    // }

    // Deep Copy
    Bundle(const Bundle &b)
    {
        count = new int(*(b.count));
        discount = b.discount;
        capacity = b.capacity;
        productList = new Product[capacity];
        for (int i = 0; i < capacity; i++)
            productList[i] = b.productList[i];
    }

    void applyDiscount()
    {
        for (int i = 0; i < capacity; i++)
            productList[i].price *= (1 - discount / 100);
    }

    void addProduct(const Product &p)
    {
        if (*count >= capacity)
        {
            cout << "Cannot add more products" << endl;
            return;
        }
        productList[(*count)++] = p;
    }

    void display()
    {
        for (int i = 0; i < *count; i++)
        {
            cout << "Product " << i + 1 << ":-" << endl;
            productList[i].display();
            cout << "Discount Applied: " << productList[i].price * (discount / 100) << endl;
        }
    }
};

int main()
{
    Bundle b1(20);
    b1.addProduct(Product("P1", 1000, 14));
    b1.addProduct(Product("P2", 1280, 10));

    // Copying
    Bundle b2(b1);

    // Modify b2
    b2.addProduct(Product("P3", 2145, 21));

    cout << "Displaying b1 (after modifying b2):" << endl;
    b1.display();

    cout << "\nDisplaying b2:" << endl;
    b2.display();

    return 0;
}
