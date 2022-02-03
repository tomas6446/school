#include <iostream>
#include <fstream>
using namespace std;

struct zuvis_str{
    string pav;
    int taskai;
    int mase = 0;
}zuvis[30];

struct zvejas_str{
    string vardas;
    int prist_zuviu;
    int taskai = 0;
    zuvis_str zuvis[10];
}zvejas[30];

void sortiravimas(int n, int k){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(zvejas[i].taskai < zvejas[j].taskai){
                swap(zvejas[i], zvejas[j]);
            }
            else if(zvejas[i].taskai == zvejas[j].taskai && zvejas[i].vardas > zvejas[j].vardas){
                swap(zvejas[i], zvejas[j]);
            }
        }
    }
    for(int i = 0; i < k-1; i++){
        for(int j = i+1; j < k; j++){
            if(zuvis[i].mase < zuvis[j].mase){
                swap(zuvis[i], zuvis[j]);
            }
            else if(zuvis[i].mase == zuvis[j].mase && zuvis[i].pav > zuvis[j].pav){
                swap(zuvis[i], zuvis[j]);
            }
        }
    }
}

int main()
{
    ifstream fin("U2.txt");
    ofstream fout("U2rez.txt");
    int n, skir_zuv_sk;

    fin >> n;
    fin.ignore();
    for(int i = 0; i < n; i++){
        char temp[20];
        fin.get(temp, sizeof(temp));
        zvejas[i].vardas = temp;
        fin >> zvejas[i].prist_zuviu;
        fin.ignore();
        for(int j = 0; j < zvejas[i].prist_zuviu; j++){
            fin.get(temp, sizeof(temp));
            zvejas[i].zuvis[j].pav = temp;
            fin >> zvejas[i].zuvis[j].mase;
            fin.ignore();
        }
    }//zveju duomenu ivedimas

    fin >> skir_zuv_sk;
    fin.ignore();
    for(int i = 0; i < skir_zuv_sk; i++){
        char temp[20];
        fin.get(temp, sizeof(temp));
        zuvis[i].pav = temp;
        fin >> zuvis[i].taskai;
        fin.ignore();
    }//zuviu duomenu ivedimas

    for(int i = 0; i < n; i++){
        for(int j = 0; j < zvejas[i].prist_zuviu; j++){
            if(zvejas[i].zuvis[j].mase >= 200){
                zvejas[i].taskai += 30;
            }
            else{
                zvejas[i].taskai += 10;
            }
            for(int k = 0; k < skir_zuv_sk; k++){
                if(zvejas[i].zuvis[j].pav == zuvis[k].pav){
                    zvejas[i].taskai += zuvis[k].taskai;
                    zuvis[k].mase += zvejas[i].zuvis[j].mase;
                }
            }//Najti pravilnuu rybu && Dobavit za nee tochki && Dobavit ee ves k obshemu
        }
    }//magija / nacislenije ochkov

    sortiravimas(n, skir_zuv_sk);

    cout << "Dalyviai" << endl;
    for(int i = 0; i < n; i++){
        cout << zvejas[i].vardas << " " << zvejas[i].taskai << endl;
    }
    cout << "Laimiklis" << endl;
    for(int i = 0; i < skir_zuv_sk; i++){
        cout << zuvis[i].pav << " " << zuvis[i].mase << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
