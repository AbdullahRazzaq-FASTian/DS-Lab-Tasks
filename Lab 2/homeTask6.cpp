#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class SeatingChart
{
    int numRows;
    string **seats = nullptr;
    int *size = nullptr;

public:
    SeatingChart(int numRows) : numRows(numRows)
    {
        seats = new string *[numRows];
        size = new int[numRows];

        for (int i = 0; i < numRows; i++)
        {
            int seatCapacity;
            cout << "Enter the number of seats in row " << i + 1 << ": ";
            cin >> seatCapacity;
            seats[i] = new string[seatCapacity];
            size[i] = seatCapacity;
        }
    }
    
    ~SeatingChart()
    {
        for (int i = 0; i < numRows; i++)
        {
            delete[] seats[i];
        }
        delete[] seats;
        delete[] size;
    }
    
    void setSeats()
    {
        cin.ignore();

        for (int i = 0; i < numRows; i++)
        {
            cout << "Enter names for row " << i + 1 << " seats:" << endl;
            for (int j = 0; j < size[i]; j++)
            {
                cout << "Seat " << j + 1 << ": ";
                getline(cin, seats[i][j]);
            }
            nl;
        }
    }
    
    void display()
    {
        for (int i = 0; i < numRows; i++)
        {
            cout << "Row " << i + 1 << " (" << size[i] << " seats): ";
            for (int j = 0; j < size[i]; j++)
            {
                cout << seats[i][j] << " ";
            }
            nl;
        }
    }
};

int main()
{
    int numRows;
    cout << "Enter the number of rows: ";
    cin >> numRows;

    SeatingChart SC(numRows);
    SC.setSeats();
    nl;
    SC.display();
    nl;

    return 0;
}
