#include <iostream>
#include <fstream>
#include <iomanip>
const char FD[] = "U1.txt";
const char FR[] = "U1rez.txt";
using namespace std;

void read(int &n, int ilipo[], int islipo[]) {
    ifstream fin(FD);
    int num, zmones;
    fin >> n;
    for(int i = 0; i < n; i++) {
        fin >> num >> zmones;
        if(zmones < 0)
            islipo[num] += zmones;
        else if(zmones > 0)
            ilipo[num] += zmones;
    }
    fin.close();
}
int maximum(int ilipo[])
{
    int maximum = ilipo[0];
    int index;
    for(int i = 1; i <= 100; i++) {
        if(ilipo[i] != 0) {
            if(maximum < ilipo[i]) {
                maximum = ilipo[i];
                index = i;
            }
        }
    }
    return index;
}
void num_write(int ilipo[], int islipo[])
{
    ofstream fout(FR);
    for(int i = 1; i <= 100; i++) {
        if(islipo[i] != 0 || ilipo[i] != 0) {
             fout << setw(6) << left << i;
        }
    }
    fout.close();
}

int main() {
    int n, ilipo[101] = {0}, islipo[101] = {0};
    read(n, ilipo, islipo);

    num_write(ilipo, islipo);
    ofstream fout(FR, ios::app);
    fout << endl;
    for(int i = 1; i <= 100; i++)   {
        if(ilipo[i] != 0 || islipo[i] != 0) {
            fout << setw(6) << left << ilipo[i];// ilipo
        }

    }
    fout << endl;
    for(int i = 1; i <= 100; i++)  {
        if(ilipo[i] != 0 || islipo[i] != 0) {
            fout << setw(6) << left << islipo[i];// islipo
        }
    }
    fout << endl;
    int maxim = maximum(ilipo);
    fout << maxim << endl; // maximum
    fout.close();
    return 0;
}
