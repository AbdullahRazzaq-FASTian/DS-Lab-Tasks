#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Product {
public:
    string name;
    float price;
    string description;
    bool available;
};

int partition(Product arr[], int start, int end) {
    float pivot = arr[end].price;
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (arr[j].price <= pivot) {
            i++;
            Product temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    Product temp = arr[i + 1];
    arr[i + 1] = arr[end];
    arr[end] = temp;
    return i + 1;
}

void quick(Product arr[], int start, int end) {
    if (start < end) {
        int p = partition(arr, start, end);
        quick(arr, start, p - 1);
        quick(arr, p + 1, end);
    }
}

int main() {
    Product products[3];
    for (int i = 0; i < 3; i++) {
        cout << "Enter product " << i + 1 << " name: ";
        getline(cin >> ws, products[i].name);
        cout << "Enter description: ";
        getline(cin >> ws, products[i].description);
        cout << "Enter price: ";
        cin >> products[i].price;
        cout << "Available (1 for Yes / 0 for No): ";
        cin >> products[i].available;
        cin.ignore();
        cout << endl;
    }

    quick(products, 0, 2);

    cout << "\nProducts sorted by price (ascending):\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << products[i].name
             << " | Price: " << products[i].price
             << " | Description: " << products[i].description
             << " | Available: " << (products[i].available ? "Yes" : "No") << endl;
    }
}
