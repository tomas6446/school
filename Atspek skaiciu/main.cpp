#include <iostream>
#include <time.h>

using namespace std;

void logic(int win_number, int guess, bool &win, int &a, int &b, string player)
{
    if (guess <= 100 && guess >= 0)
    {
        if (win_number == guess)
        {
            win = true;
            cout << "Laimejo " << player << endl;
        }
        if (win == false)
        {
            if (guess < win_number)
            {
                cout << "Skaicius yra didesnis" << endl;
                a = guess + 1;
            }
            if (guess > win_number)
            {
                cout << "Skaicius yra mazesnis" << endl;
                b = guess - 1;
            }
        }
    }
    else
    {
        cout << "Skaicius uz intervalo" << endl;
    }

}

int main()
{
    srand(time(NULL));
    int a = 0, b = 100; // intervalas
    int win_number = rand() % 100; // random winning number
    bool win = false;
    while (win == false)
    {
        int guess;
        cout << "Jusu spejimas is intervalo [" << a << ", " << b << "]:";
        cin >> guess;
        logic(win_number, guess, win, a, b, "zmogus");
        cout << "--------------------------------------------------" << endl;

        if (win == false)
        {
            int computer_guess = rand() % (b + 1 - a) + a;
            cout << "Kompiuterio spejimas is intervalo [" << a << ", " << b << "]:";
            cout << computer_guess << endl;
            logic(win_number, computer_guess, win, a, b, "kompiuteris");
            cout << "--------------------------------------------------" << endl;
        }

    }
    return 0;
}
