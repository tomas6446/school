#include <iostream>
#include <fstream>
using namespace std;
int kieklaiko(int valpr, int minpr, int valpab, int minpab) {
    return (valpab*60+minpab)-(valpr*60+minpr);
}
int main()
{
    ifstream fin("U1.txt");
    int d;
    int rvalpr, rminpr, rvalpab, rminpab;
    int vvalpr, vminpr, vvalpab, vminpab;
    int kiek[31] = {0};
    int dien[31];
    fin >> d;
    for(int i = 0; i < d; i++) {
        fin >> dien[i];
        fin >> rvalpr >> rminpr >> rvalpab >> rminpab;
        fin >> vvalpr >> vminpr >> vvalpab >> vminpab;
        if(rvalpr != 0 && rvalpab != 0 && vvalpr !=0 && vvalpab != 0) {
            kiek[i] = kieklaiko(rvalpr, rminpr, rvalpab, rminpab);
            kiek[i] += kieklaiko(vvalpr, vminpr, vvalpab, vminpab);
        }
    }
    int minlaikas = kiek[0];
    int mindienas[31];
    for(int i = 0; i < d; i++) {
        if(kiek[i] != 0 && minlaikas > kiek[i]) {
            minlaikas = kiek[i];
        }
    }
    int t = 0;
    for(int i = 0; i < d; i++) {
        if(minlaikas == kiek[i]) {
            mindienas[t] = dien[i];
            t++;
        }
    }
    cout << minlaikas << endl;
    for(int i = 0; i < t; i++) {
        cout << mindienas[i] << " ";
    }
    return 0;
}
