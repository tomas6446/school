#include <iostream>
#include <fstream>
using namespace std;

struct str_geles{
    int num;
    int prad;
    int pab;
};

int menesiai_i_dienas(int menuo){
    if(menuo == 7){
        return 30;
    }
    else if(menuo == 8){
        return 61;
    }
    else{
        return 0;
    }
}

void isvedimas(int dienos){
    if(dienos > 61){
        cout << "8 " << dienos-61 << endl;
    }
    else if(dienos > 30){
        cout << "7 " << dienos-30 << endl;
    }
    else{
        cout << "6 " << dienos << endl;
    }
}

void diena_kai_zydi_daugiausia(int sarasas[], int j, int &kada_prasidejo, int &maxim){
    if(maxim < sarasas[j]){
        maxim = sarasas[j];
        kada_prasidejo = j;
    }
}

int main()
{
    ifstream fin("U1.txt");
    ofstream fout("U1rez.txt");

    str_geles geles[30];
    int n, sarasas[92], maxim = 0, dienu_maxim = 0, kada_prasidejo;
    for(int i = 0; i < 92; i++){
        sarasas[i] = 0;
    }

    fin >> n;
    for(int i = 0; i < n; i++){
        int prad_men, pab_men;
        fin >> geles[i].num >> prad_men >> geles[i].prad >> pab_men >> geles[i].pab;
        geles[i].prad += menesiai_i_dienas(prad_men);
        geles[i].pab += menesiai_i_dienas(pab_men);
    }//Zapolnenije struktury

    for(int i = 0; i < n; i++){
        for(int j = geles[i].prad; j < geles[i].pab; j++){
            sarasas[j]++;
            diena_kai_zydi_daugiausia(sarasas, j, kada_prasidejo, maxim);
        }
    }//Zapolnenije spiska, nahozdenije maksimuma i pervogo dnia maksimuma

    for(int i = 0; i < 92; i++){
        if(sarasas[i] == maxim){
            dienu_maxim++;
        }
    }

    cout << maxim << endl;
    isvedimas(kada_prasidejo);
    isvedimas(kada_prasidejo+dienu_maxim);

    fin.close();
    fout.close();
    return 0;
}
