#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

// Since every department has different number of core courses therefore jagged array will work great for this type of data

class JaggedArray
{
    int numDep;
    pair<string, int> *dep = nullptr;
    float **data = nullptr;

public:
    JaggedArray(int numDep, pair<string, int> dep[]) : numDep(numDep), dep(dep)
    {
        data = new float *[numDep];
        for (int i = 0; i < numDep; i++)
        {
            int size = this->dep[i].second;
            data[i] = new float[size];
            for (int j = 0; j < size; j++)
                data[i][j] = 0.0;
        }
    }
    ~JaggedArray()
    {
        for (int i = 0; i < numDep; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }
    void setData()
    {
        cout << "Enter data for respective departments: " << endl;
        nl;
        for (int i = 0; i < numDep; i++)
        {
            cout << "Grade Points for Department: " << this->dep[i].first << endl;
            int size = this->dep[i].second;
            for (int j = 0; j < size; j++)
                cout << "Course: " << j + 1 << " ", cin >> data[i][j];
            nl;
        }
    }
    void display() {
        for (int i = 0; i < numDep; i++) {
            cout << "Department: " << this->dep[i].first << endl;

            cout << "Courses: ";
            int size = this->dep[i].second;
            float total = 0;
            for (int j = 0; j < size; j++) {
                cout << data[i][j] << " ";
                total += data[i][j];
            }
            float sgpa = total / size;
            cout << endl << "SGPA: " << fixed << setprecision(2) << sgpa << endl << endl;
        }
    }
};

int main()
{
    pair<string, int> dep[] = {{"CS", 2}, {"AI", 4}, {"SE", 3}, {"DS", 1}}; // Department Names and the number of there core courses
    JaggedArray JA(4, dep);
    JA.setData();
    nl;
    JA.display();
    nl;
    return 0;
}