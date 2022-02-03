#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FIN[] = "U2.txt";
const char FOUT[] = "U2rez.txt";
const int CMAX = 50;

struct duomenys{
    string vardas[CMAX];
    int laikas[CMAX];
};

struct geriausiuduomenys{
    string vardas;
    int laikas;
}geriausi[CMAX];

void isvedimas(int temp){
    for(int i = 0; i < temp; i++){
        cout << setw(20) << left << geriausi[i].vardas << geriausi[i].laikas/60 << " " << geriausi[i].laikas%60 << endl;
    }
}

int main()
{
    ifstream fin(FIN);
    ofstream fout(FOUT);

    duomenys grupe[CMAX];
    int k, n, minutes, sekundes, temp = 0;
    string vardas, pavarde;

    fin >> k;
    for(int i = 0; i < k; i++){
        fin >> n;

        for(int j = 0; j < n; j++){
            fin >> vardas >> pavarde;
            grupe[i].vardas[j] = vardas + " " + pavarde;
            fin >> minutes >> sekundes;
            grupe[i].laikas[j] = minutes*60 + sekundes;
        } //Vvod

        for(int j = 0; j < n-1; j++){
            for(int k = j+1; k < n; k++){
                if(grupe[i].laikas[j] > grupe[i].laikas[k]){
                    swap(grupe[i].laikas[j], grupe[i].laikas[k]);
                    swap(grupe[i].vardas[j], grupe[i].vardas[k]);
                }
            }
        }//Sortirovka

        for(int j = 0; j < n/2; j++){
            geriausi[temp].laikas = grupe[i].laikas[j];
            geriausi[temp].vardas = grupe[i].vardas[j];
            temp++;
        }//Peremeshenije

        for(int j = 0; j < temp-1; j++){
            for(int k = j+1; k < temp; k++){
                if(geriausi[j].laikas > geriausi[k].laikas){
                    swap(geriausi[j], geriausi[k]);
                }
            }
        }//Sortirovka
    }

    isvedimas(temp);

    fin.close();
    fout.close();
    return 0;
}
