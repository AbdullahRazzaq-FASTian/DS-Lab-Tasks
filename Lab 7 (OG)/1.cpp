#include <bits/stdc++.h>
#define nl (cout << endl)
#define f(i,s,e) for(int i=s;i<e;i++)
#define fr(i,s,e) for(int i=s;i>=e;i--)
#define N 1000
using namespace std;

class Student {
public:
    string name;
    int score;
    Student* next;
    Student(string n, int s) { name = n; score = s; next = nullptr; }
};

void insert(Student*& head, string n, int s) {
    Student* node = new Student(n, s);
    if (!head) head = node;
    else {
        Student* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = node;
    }
}

void display(Student* head) {
    while (head) {
        cout << head->name << " " << head->score << endl;
        head = head->next;
    }
}

void countSort(Student*& list, int exp) {
    Student* headBucket[10] = {nullptr};
    Student* tailBucket[10] = {nullptr};
    Student* cur = list;

    while (cur) {
        Student* nxt = cur->next;
        int digit = (cur->score / exp) % 10;
        if (!headBucket[digit]){
            headBucket[digit] = tailBucket[digit] = cur;
        } 
        else {
            tailBucket[digit]->next = cur;
            tailBucket[digit] = cur;
        }
        cur = nxt;
    }

    Student* head = nullptr, *tail = nullptr;

    int i = 0;
    while (i < 10 && !headBucket[i]) i++;
    if (i == 10) return;

    head = headBucket[i];
    tail = tailBucket[i];
    
    for (i = i + 1; i < 10; i++) {
        if (headBucket[i]) {
            tail->next = headBucket[i];
            tail = tailBucket[i];
        }
    }
    tail->next = nullptr;

    list = head;
}

void radixSort(Student*& list) {
    if (!list || !list->next) return;

    int maxVal = list->score;
    for (Student* cur = list; cur; cur = cur->next)
        maxVal = max(maxVal, cur->score);

    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countSort(list, exp);
}

Student* midNode(Student* start, Student* end) {
    Student* slow = start;
    Student* fast = start->next;
    while (fast != end && fast->next != end) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Student* binarySearch(Student* head, string key) {
    Student* start = head;
    Student* end = nullptr;
    while (start != end) {
        Student* mid = midNode(start, end);
        if (mid->name == key) return mid;
        else if (mid->name < key) start = mid->next;
        else end = mid;
    }
    return nullptr;
}

void deleteRecord(Student*& head, string key) {
    if (!head) return;
    if (head->name == key) {
        Student* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Student* cur = head;
    while (cur->next && cur->next->name != key)
        cur = cur->next;
    if (cur->next) {
        Student* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
    }
}

int main() {
    Student* list = nullptr;
    insert(list, "Ali", 41);
    insert(list, "Hassan", 52);
    insert(list, "Usman", 23);
    insert(list, "Bilal", 95);
    insert(list, "Ahmed", 8);

    radixSort(list);
    cout << "Sorted List:\n";
    display(list);

    cout << "\nEnter name to search and delete: ";
    string key; cin >> key;

    Student* found = binarySearch(list, key);
    if (found) {
        deleteRecord(list, key);
        cout << "\nAfter deletion:\n";
        display(list);
    } 
    else 
        cout << "\nRecord not found.\n";
    nl;
}
