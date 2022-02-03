#include <iostream>
#include <fstream>
using namespace std;
const int SIZE = 100;

int skolko_gorelo(bool zibintai[SIZE], int n){
    int temp = 0;
    for(int i = 0; i < n; i++){
        if(zibintai[i] == true){
            temp++;
        }
    }
    return temp;
}

int main()
{
    ifstream fin("U1test.txt");
    int n, k, daug_zib, maz_zib, daug_index = 1, maz_index = 1;
    bool zibintai[SIZE], temp[SIZE];

    fin >> n >> k;
    for(int i = 0; i < n; i++){
        fin >> zibintai[i];
        cout << zibintai[i] << " ";
    }
    cout << endl;

    daug_zib = skolko_gorelo(zibintai, n);
    maz_zib = n - skolko_gorelo(zibintai, n);
    for(int i = 1; i < k; i++){
        memcpy(temp, zibintai, n);
        for(int j = 0; j < n; j++){
            if(temp[j-1] == true && temp[j+1] == true && j != 0 && j != n-1){
                zibintai[j] = false;
            }
            else if(((temp[j-1] == true && temp[j+1] == false) || (temp[j-1] == false && temp[j+1] == true)) && j != 0 && j != n-1){
                zibintai[j] = true;
            }
            else{
                if((i+1)%2 == 0){
                    zibintai[j] = true;
                }
                else{
                    zibintai[j] = false;
                }
            }
        }

        if(skolko_gorelo(zibintai, n) > daug_zib){
            daug_zib = skolko_gorelo(zibintai, n);
            daug_index = i+1;
        }
        else if(skolko_gorelo(zibintai, n) < maz_zib){
            maz_zib = n - skolko_gorelo(zibintai, n);
            maz_index = i+1;
        }

        for(int j = 0; j < n; j++){
            cout << zibintai[j] << " ";
        }
        cout << endl;
    }
    cout << "Naktis daugiausia " << daug_index << endl << "Naktis maziausia " << maz_index << endl;

    fin.close();
    return 0;
}
