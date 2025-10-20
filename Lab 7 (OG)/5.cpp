#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* curr) {
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node* getTail(Node* cur) {
    while (cur != nullptr && cur->next != nullptr)
        cur = cur->next;
    return cur;
}

Node* partition(Node* head, Node* tail) {
    Node* pivot = head;
    Node* pre = head;
    Node* curr = head;
    while (curr != tail->next) {
        if (curr->data < pivot->data) {
            swap(curr->data, pre->next->data);
            pre = pre->next;
        }
        curr = curr->next;
    }
    swap(pivot->data, pre->data);
    return pre;
}

void helper(Node* head, Node* tail) {
    if (head == nullptr || head == tail) {
        return;
    }
    Node* pivot = partition(head, tail);
    helper(head, pivot);
    helper(pivot->next, tail);
}

Node* quickSort(Node* head) {
    Node* tail = getTail(head);
    helper(head, tail);
    return head;
}

int main() {
    Node* head = new Node(30);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(20);
    head->next->next->next->next = new Node(5);
    cout << "\n Array before sorting: \n";
    printList(head);
    head = quickSort(head);
    cout << "\n Array after sorting: \n";
    printList(head);
    nl;
    return 0;
}
