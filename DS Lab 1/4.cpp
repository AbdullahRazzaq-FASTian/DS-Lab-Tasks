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
    int count;
    double discount = 0;

    Bundle(double discount) : discount(discount)
    {
        count = 0;
        productList = new Product[count];
    }
    // Shallow Copy
    Bundle(const Bundle &b)
    {
        productList = b.productList;
        count = b.count;
        discount = b.discount;
    }
    // Deep Copy
    // Bundle(const Bundle &b)
    // {
    //     count = count;
    //     discount = discount;
    //     productList = new Product[count];
    //     for (int i = 0; i < count; i++)
    //         productList[i] = b.productList[i];
    // }
    void applyDiscount()
    {
    }
    void addProduct(const Product &p)
    {
        Product *list = new Product[count + 1];
        for (int i = 0; i < count; i++)
            list[i] = productList[i];
        list[count++] = p;
        delete[] productList;
        productList = list;
    }
    void display()
    {
        cout << "---Product Details---" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << "Product " << i + 1 << ":-" << endl;
            productList[i].display();
            cout << "Discount Applied: " << productList[i].price * (discount / 100) << endl;
        }
    }
    ~Bundle()
    {
        delete[] productList;
    }
};

int main()
{
    Bundle b1(20);
    b1.addProduct(Product("P1", 1000, 14));
    b1.addProduct(Product("P2", 1280, 10));
    b1.addProduct(Product("P3", 2145, 21));
    Bundle b2(b1);
    cout << "After adding Product 4" << endl;
    b2.addProduct(Product("P4", 999, 11));
    b2.display();
    b1.display();
    return 0;
}