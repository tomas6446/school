#include <iostream>
#include <fstream>
using namespace std;
void daugiskaita(int n, int k, string budv[], string daikt[]) {
    for(int i = 0; i < n; i++) {
        budv[i] += "j";
    }
    for(int i = 0; i < k; i++) {
        daikt[i] += "j";
    }
}

void read(int &b, int &d, string budv[], string daikt[]) {
    ifstream fin("Duomenys.txt");
    string liet;
    fin >> b;
    for(int i = 0; i < b; i++) {
        fin >> budv[i] >> liet;
    }
    fin >> d;
    for(int i = 0; i < d; i++) {
        fin >> daikt[i] >> liet;
    }
    daugiskaita(b, d, budv, daikt);

    fin.close();
}

void rezultatas(int n, string deriniai[]) {
    ofstream fout("Rezultatas.txt");
    for(int i = 0; i < n; i++) {
        fout << deriniai[i] << endl;
    }
    fout.close();
}
int main() {
    int b, d, t = 0;
    string deriniai[20], budv[10], daikt[10];
    read(b, d, budv, daikt);
    for(int i = 0; i < b; i++){
        for(int j = 0; j < d; j++) {
            deriniai[t] = budv[i] + " " + daikt[j];
            t++;
        }
    }
    rezultatas(t, deriniai);
    return 0;
}
