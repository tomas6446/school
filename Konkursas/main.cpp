#include <iostream>
#include <fstream>
using namespace std;
const char FD[] = "Duoments.txt";
const char FR[] = "Rezultatas.txt";
const int Cn = 100;
void read(int &n, int &vid, int balai[])
{
    int sum = 0;
    ifstream fin(FD);
    fin >> n;
    for(int i = 0; i < n; i++)
    {
        fin >> balai[i];
        sum += balai[i];
    }
    vid = sum / n;
    fin.close();
}

int main()
{
    int n, vid, balai[Cn];
    read(n, vid, balai);
    return 0;
}
