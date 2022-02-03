#include <iostream>
#include <fstream>
using namespace std;
struct Zmogus {
    string lytis;
    int met = 0, men = 0, dien = 0;
    int registracijos_num = 0;
} zm[3000];

void vyriausias(int n, int &mot, int &vyr) {
    int minimum = zm[1].registracijos_num;
    for(int i = 1; i <= n; i++) {
        if(minimum > zm[i].registracijos_num) {
            if(zm[i].lytis == "moteris") {
                mot = i;
            }
            else if(zm[i].lytis == "vyras") {
                vyr = i;
            }
        }
    }
}
int main()
{
    int n, mot = 0, vyr = 0;
    int64_t kodas; // ili long long
    string menesiai[12] =
    {"sausio ", "vasario ", "kovo ", "balandzio ", "geguzes ", "birzelio ",
    "liepos ", "rugpjucio ", "rugsejo ", "spalio ", "lapkricio ", "gruodzio "};
    ifstream fin("Duomenys.txt");
    fin >> n;
    for(int i = 1; i <= n; i++) {
        fin >> kodas;
        switch(kodas/10000000000) {
            case 3:
                zm[i].lytis = "vyras";
                zm[i].met += 1900;
            break;
            case 4:
                zm[i].lytis = "moteris";
                zm[i].met += 1900;
            break;
            case 5:
                zm[i].lytis = "vyras";
                zm[i].met += 2000;
            break;
            case 6:
                zm[i].lytis = "moteris";
                zm[i].met += 2000;
            break;
        }
        zm[i].met += kodas/100000000%100;
        zm[i].men = kodas/1000000%100;
        zm[i].dien = kodas/10000%100;
        zm[i].registracijos_num = kodas%10000;
    }
    fin.close();
    vyriausias(n, mot, vyr);
    ofstream fout("Rezultatai.txt");
    if(vyr > 0) {
        fout << "Vyriausias " << zm[vyr].lytis << " gime " << zm[vyr].met << " m. " << menesiai[zm[vyr].men-1] << zm[vyr].dien << " d. " << endl;
    }
    else if(vyr == 0) {
        fout << "Vyru nera" << endl;
    }

    if(mot > 0) {
        fout << "Moteris " << zm[mot].lytis << " gime " << zm[mot].met << " m. " << menesiai[zm[mot].men-1] << zm[mot].dien << " d. " << endl;
    }
    else if(mot == 0) {
        fout << "Moteru nera" << endl;
    }


    fout.close();
    return 0;
}
