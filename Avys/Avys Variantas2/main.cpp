#include <iostream>
#include <fstream>
#include <iomanip>
const char FV[] = "Duomenys.txt";
const char FD[] = "Rezultatas.txt";
using namespace std;
struct Avys {
    string name;
    string dnr;
    int koef = 0;
}dnk[20];
void read(int &n, int &m, int &num)
{
    ifstream fin(FV);
    fin >> n >> m >> num;
    for(int i = 1; i <= n; i++)
        fin >> dnk[i].name >> dnk[i].dnr;
    fin.close();
}
void sutamp(int n, int m, int num)
{
    for(int i = 1; i <= n; i++)
    {
        if(i != num)
        {
            for(int j = 0; j < m; j++)
            {
                if(dnk[num].dnr[j] == dnk[i].dnr[j])
                    dnk[i].koef+=1;
            }
        }
    }
}
void rikiavimas(int n, int m, int num)
{
    for(int i = 1; i <= n-1; i++)
    {
        if(i != num)
        {
            for(int j = i+1; j <= n; j++)
            {
                if(j != num)
                {
                    if(dnk[i].koef < dnk[j].koef)
                        swap(dnk[i], dnk[j]);
                    else if(dnk[i].koef == dnk[j].koef)
                    {
                        if(dnk[i].name > dnk[j].name)
                            swap(dnk[i], dnk[j]);
                    }
                }
            }
        }
    }
}
void rezultatas(int n, int num)
{
    ofstream fout(FD);
    fout << dnk[num].name << endl;
    for(int i = 1; i <= n; i++)
    {
        if(i!=num)
            fout << setw(10) << left << dnk[i].name << " " << dnk[i].koef << endl;
    }
    fout.close();
}
int main()
{
    int n, m, num;
    read(n, m, num);
    sutamp(n, m, num);
    rikiavimas(n, m, num);
    rezultatas(n, num);
    return 0;
}
