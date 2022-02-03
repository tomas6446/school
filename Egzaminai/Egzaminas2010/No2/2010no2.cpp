#include <iostream>
#include <fstream>
using namespace std;
int patiekalokaina(int n, int kiekis[], int kaina[])
{
    int sum = 0;
    for(int j = 0; j < n; j++)
    {
        sum += kaina[j]*kiekis[j];
    }
    return sum;
}

int main()
{
    ifstream fin("U2.txt");
    int n, p;
    fin >> n >> p;

    string pavad[12];
    int kaina[12], kiekis[12];
    int patiekkain[12];
    int pietokaina = 0;

    for(int i = 0; i < n; i++)
    {
        fin >> kaina[i];
        fin.ignore();
    }
    fin.ignore();
    char eil[15];
    for(int i = 0; i < p; i++)
    {
        fin.get(eil, sizeof eil);
        pavad[i] = eil;
        for(int j = 0; j < n; j++)
        {
            fin >> kiekis[j];
            fin.ignore();
        }
        patiekkain[i] = patiekalokaina(n, kiekis, kaina);
        pietokaina += patiekalokaina(n, kiekis, kaina);
        fin.ignore();
    }
    fin.close();

    ofstream fout("U1rez.txt");
    for(int i = 0; i < p; i++)
    {
        fout << pavad[i] << patiekkain[i] << endl;
    }
    fout << pietokaina/100 << " " << pietokaina%100 << endl;
    fout.close();

    return 0;
}
