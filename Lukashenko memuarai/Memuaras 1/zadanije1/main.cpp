#include <iostream>
#include <fstream>

using namespace std;

int cmax = 100;
const char FIN[] = "duom.txt";
const char FOUT[] = "rez.txt";

void skaitymas(int arr[]){
	int k;
	ifstream fin(FIN);
	fin >> k;

	for(int i = 0; i < k; i++){
		fin >> arr[i];
	}

	fin.close();
}

void iterpimas(int arr[], int m, int &k){
	for(int i = 0; i < k; i++){
		if(arr[i] == m){
			for(int j = k; j > i; j--){
                arr[j] = arr[j-1];
            }
            k++;
			break;
		}
        if(arr[i] != m && i == k-1){
            arr[k] = m;
            k++;
            break;
        }
	}
}

void rasymas(int arr[], int k){
    ofstream fout(FOUT);

    for(int i = 0; i < k; i++){
        fout << arr[i] << " ";
        cout << arr[i] << endl;
    }

    fout.close();
}

int main(){
	int k, arr[cmax], m = 11/*999 Dlia zameny*/;
	ifstream fin(FIN);
	fin >> k;

	skaitymas(arr);
	iterpimas(arr, m, k);
	rasymas(arr, k);

	fin.close();
	return 0;
}
