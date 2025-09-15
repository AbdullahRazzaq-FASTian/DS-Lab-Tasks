#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

void simulate()
{
    static int number = rand() % 100;
    int guess;
    cout << "Enter your guess: ", cin >> guess;
    if (guess == number)
    {
        cout << "Congratulations you guessed the number!" << endl;
        return;
    }
    else if (guess > number)
        cout << "The number is lesser than the guess" << endl;
    else
        cout << "The number is greater than the guess" << endl;
    simulate();
}

int main()
{
    srand(time(0));
    simulate();
    return 0;
}