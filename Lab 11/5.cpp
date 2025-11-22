#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

const int TABLE_SIZE = 15;

class StudentHashTable {
private:
    int roll[TABLE_SIZE];
    string name[TABLE_SIZE];
    bool occupied[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    StudentHashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            roll[i] = 0;
            name[i] = "";
            occupied[i] = false;
        }
    }

    void InsertRecord(int rollNo, const string& studentName) {
        int hash = hashFunction(rollNo);
        int index;
        int attempt = 0;

        while (attempt < TABLE_SIZE) {
            index = (hash + attempt * attempt) % TABLE_SIZE;

            if (!occupied[index] || roll[index] == rollNo) {
                roll[index] = rollNo;
                name[index] = studentName;
                occupied[index] = true;
                return;
            }

            attempt++;
        }

        cout << "Hash table full, cannot insert roll number " << rollNo << endl;
    }

    void SearchRecord(int rollNo) {
        int hash = hashFunction(rollNo);
        int index;
        int attempt = 0;

        while (attempt < TABLE_SIZE) {
            index = (hash + attempt * attempt) % TABLE_SIZE;

            if (!occupied[index]) {
                cout << "Record not found for roll number " << rollNo << endl;
                return;
            }

            if (roll[index] == rollNo) {
                cout << "Roll number " << rollNo << ": " << name[index] << endl;
                return;
            }

            attempt++;
        }

        cout << "Record not found for roll number " << rollNo << endl;
    }
};

int main() {
    StudentHashTable sht;

    sht.InsertRecord(1, "Ali");
    sht.InsertRecord(16, "Sara"); // collision with 1
    sht.InsertRecord(31, "Raza"); // collision again
    sht.InsertRecord(2, "Taha");

    nl;
    sht.SearchRecord(16);
    sht.SearchRecord(31);
    sht.SearchRecord(5);
    nl;
    
    return 0;
}
