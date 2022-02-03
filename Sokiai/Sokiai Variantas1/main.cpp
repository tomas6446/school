#include <iostream>
#include <fstream>

using namespace std;
struct Sokiai {
    string vardas;
    int sum = 0; // is viso balu
} sok[100];

void Balu_rikiavimas(int k, int bal[]) {
    for(int i = 0; i < k-1; i++) {
        for(int j = i+1; j < k; j++) {
            if(bal[i] > bal[j]) {
                swap(bal[i], bal[j]);
            }
        }
    }
}

int isviso(int k, int bal[]) {
    int sum = 0;
    for(int j = 1; j < k-1; j++) { // pervyj i poslednij element ne uchityvajetsia
        sum += bal[j];
    }
    return sum;
}

void read(int &n, int &k) {
    char eil[20];
    int art[10], tech[10];
    ifstream fin("Duomenys.txt");
    fin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        fin.ignore();
        fin.get(eil, sizeof eil);
        sok[i].vardas = eil;

        for(int j = 0; j < k; j++) {
            fin >> tech[j]; // balai uz technika
        }
        Balu_rikiavimas(k, tech);
        sok[i].sum += isviso(k, tech); // balai isviso

        for(int j = 0; j < k; j++) {
            fin >> art[j]; // balai uz artistiskuma
        }
        Balu_rikiavimas(k, art);
        sok[i].sum += isviso(k, art); // balai isviso
    }
    fin.close();
}

void Sokeju_rikiavimas(int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(sok[i].sum < sok[j].sum) {
                swap(sok[i], sok[j]);
            }
        }
    }
}

int main() {
    int n, k;
    read(n, k);
    Sokeju_rikiavimas(n);
    ofstream fout("Rezultatas.txt");
    for(int i = 0; i < n; i++) {
        fout << sok[i].vardas << sok[i].sum << endl;
    }
    fout.close();
    return 0;
}
