#include <iostream>
#include <fstream>
using namespace std;

struct Zmones {
    string vard;
    int met, men, dien;
    int mirtmet, mirtmen, mirtdien;
    int gyvtrukme;
} zm[100];

int gtrukme(int n, int i)
{
    int dien = zm[i].met*365 + zm[i].dien;
    int mirtdien = zm[i].mirtmet*365 + zm[i].mirtdien;

    for(int j = 1; j < zm[i].men; j++)
    {
        if(j == 4 || j == 6 || j == 9 || j == 11) {
            dien += 30;
        }
        else if(j == 2) {
            dien += 28;
        }
        else {
            dien += 31;
        }
    }

    for(int j = 1; j < zm[i].mirtmen; j++)
    {
        if(j == 4 || j == 6 || j == 9 || j == 11) {
            mirtdien += 30;
        }
        else if(j == 2) {
            mirtdien += 28;
        }
        else {
            mirtdien += 31;
        }
    }

    return mirtdien - dien;
}

void read(int &n)
{
    char eil[25];
    ifstream fin("Duomenys.txt");

    fin >> n;
    fin.ignore();

    for(int i = 0; i < n; i++)
    {
        fin.get(eil, sizeof eil);
        zm[i].vard = eil;
        fin >> zm[i].met >> zm[i].men >> zm[i].dien >> zm[i].mirtmet >> zm[i].mirtmen >> zm[i].mirtdien;
        zm[i].gyvtrukme = gtrukme(n, i);
        fin.ignore();
    }
    fin.close();
}

void result(int n)
{
    ofstream fout("Rezultatas.txt");

    for(int i = 0; i < n; i++)
    {
        fout << zm[i].vard << zm[i].met << " " << zm[i].men << " " << zm[i].dien << " ";
        fout << zm[i].mirtmet << " " << zm[i].mirtmen << " " << zm[i].mirtdien << " " << zm[i].gyvtrukme << endl;
    }
    fout.close();
}

int main()
{
    int n;
    read(n);
    result(n);
    return 0;
}
