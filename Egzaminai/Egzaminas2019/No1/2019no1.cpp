#include <iostream>
#include <fstream>
using namespace std;

void panaudota(int &n1copy, int &n3copy, int &n5copy, int &k)
{
    while(n5copy > 0 && k >= 5)
    {
        n5copy -= 1;
        k -= 5;
    }
    while(n3copy > 0 && k >= 3)
    {
        n3copy -= 1;
        k -= 3;
    }
    while(n1copy > 0 && k >= 1)
    {
        n1copy -= 1;
        k -= 1;
    }
}

int main()
{
    ifstream fin("U1.txt");
    int n1, n3, n5, k;
    int kaina1, kaina3, kaina5, islaidos;
    fin >> n1 >> n3 >> n5 >> k >> islaidos >> kaina1 >> kaina3 >> kaina5;
    fin.close();

    int n1copy = n1, n3copy = n3, n5copy = n5; // n1copy, n3copy, n5copy - nepanaudota
    int n1papild = 0, n3papild = 0, n5papild = 0; // papildomai reikejo

    panaudota(n1copy, n3copy, n5copy, k);

    int kliko = k;
    while(kliko >= 5)
    {
        n5papild += 1;
        kliko -= 5;
    }
    while(kliko >= 3)
    {
        n3papild += 1;
        kliko -= 3;
    }
    while(kliko >= 1)
    {
        n1papild += 1;
        kliko -= 1;
    }

    ofstream fout("U1rez.txt");
    fout << n1-n1copy << " " << n3-n3copy << " " << n5-n5copy << " " << k << endl;
    fout << n1copy << " " << n3copy << " " << n5copy << endl;
    fout << n1papild << " " << n3papild << " " << n5papild << endl;
    fout << ((n1+n1papild-n1copy)*kaina1+(n3+n3papild-n3copy)*kaina3+(n5+n5papild-n5copy)*kaina5)-islaidos << endl;
    fout.close();

    return 0;
}
