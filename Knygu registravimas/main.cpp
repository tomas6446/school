#include <iostream>
#include <fstream>
using namespace std;
void sk_iterpimas(int &n, int it, int iterpimas[], int numeriai[]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < it; j++) {
            if(iterpimas[j] < numeriai[i] && iterpimas[j] > numeriai[i-1]) {
                for(int j = n; j > i; j--) {
                    numeriai[j] = numeriai[j-1];
                }
                numeriai[i] = iterpimas[j];
                n++;
            }
        }
    }
}
void sk_salinimas(int &n, int sal, int salinimas[], int numeriai[]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < sal; j++) {
            if(numeriai[i] == salinimas[j]) {
                for(int j = i; j < n-1; j++) {
                    numeriai[j] = numeriai[j+1];
                }
                n--;
            }
        }
    }
}

void read(int n, int numeriai[], int salinimas[], int iterpimas[])
{
    int sal, it;
    ifstream fin("Duomenys.txt");
    fin >> n;

    fin >> sal;
    for(int i = 0; i < sal; i++) {
        fin >> salinimas[i]; // ввод чисел которые надо убрать из списка
    }

    fin >> it;
    for(int i = 0; i < it; i++) {
        fin >> iterpimas[i]; // ввод чисел которые надо добавить в список
    }

    for(int i = 0; i < n; i++) {
        fin >> numeriai[i];
    }
    fin.close();

    ofstream fout("Rezultatas.txt");
    fout << "knygu sarasas po isemimo: " << endl;
    sk_salinimas(n, sal, salinimas, numeriai);
    for(int i = 0; i < n; i++){
        fout << "Nr. " << numeriai[i] << endl;
    }
    fout << "knygu sarasas po isemimo ir pridejimo: " << endl;
    sk_iterpimas(n, it, iterpimas, numeriai);
    for(int i = 0; i < n; i++){
        fout << "Nr. " << numeriai[i] << endl;
    }
    fout.close();
}
int main() {
    int n, numeriai[100], salinimas[100], iterpimas[100];
    read(n, numeriai, salinimas, iterpimas);
    return 0;
}
