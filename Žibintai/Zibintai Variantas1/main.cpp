#include <iostream>
#include <fstream>
using namespace std;
int Naktis(int temp, int counter[]) // kogda bolshe ili menshe vsego svetilo
{
    int maxim = 0, naktis;
    for(int i = 0; i < temp; i++) {
        if(counter[i] > maxim) {
            maxim = counter[i];
            naktis = i;
        }
    }
    return naktis+1; // return naktis+1 potomu chto pervyj denj v massive nachinajetsia s 0
}
int main()
{
    int n, k, maz, daug;
    int zib[100], rezzib[100]; // zibintai(0,1)

    ifstream fin("Duomenys.txt");
    //ifstream fin("Duomenys2.txt");
    fin >> n >> k; // n - skolko fonarej, k - skolko dnej
    for(int i = 0; i < n; i++) {
        fin >> zib[i];
        rezzib[i] = zib[i];
    }
    fin.close();

    for(int j = 0; j < n; j++) { // Pervyj denj vyvod
            cout << rezzib[j] << " ";
    }
    cout << "Naktis 1" << endl;

    int nulcounter[k] = {0}, viencounter[k] = {0}; // skolko nulej, skolko edenic
    int temp = 0; // dni, gde budut hranitsia nuli i edenicy

    for(int i = 1; i < k; i++) { // i = 2 potomu chto nachenajem so vtorogo dnia
        for(int j = 0; j < n; j++) {
            if(rezzib[j] == 0) { // skolko nulej
                nulcounter[temp]++;
            }
            else if(rezzib[j] == 1) { // skolko edenic
                viencounter[temp]++;
            }
            if(zib[j-1] == 1 && zib[j+1] == 1 && j != 0 && j != n-1) {
                rezzib[j] = 0;
            }
            else if((zib[j-1] == 1 && zib[j+1] == 0 || zib[j-1] == 0 && zib[j+1] == 1) && j != 0 && j != n-1) {
                rezzib[j] = 1;
            }
            else {
                if((i+1)%2 == 0) {
                    rezzib[j] = 1;
                }
                else if((i+1)%2 != 0) {
                    rezzib[j] = 0;
                }
            }
        }
        temp++;
        for(int j = 0; j < n; j++) { // paaiskinimas
            cout << rezzib[j] << " ";
            zib[j] = rezzib[j];
        }
        cout << "Naktis " << i+1 << endl;
    }
    temp++;
    for(int i = 0; i < n; i++) {
        if(rezzib[i] == 0) { // skolko nulej u piatoj nochi
            nulcounter[temp-1]++;
        }
        else if(rezzib[i] == 1) { // skolko edenic u piatoj nochi
            viencounter[temp-1]++;
        }
    }

    maz = Naktis(temp, nulcounter); // menshe vsego fonarej svetilo
    daug = Naktis(temp, viencounter); // bolshe vsego

    ofstream fout("Rezultatas.txt");
    for(int i = 0; i < n; i++) {
         cout << rezzib[i] << " ";
    }
    cout << endl;
    cout << "Naktis, kai sviete daugiausia: " << daug << endl;
    cout << "Naktis, kai sviete maziausia: " << maz << endl;
    fout.close();

    return 0;
}
