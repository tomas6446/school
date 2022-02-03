#include <iostream>
#include <fstream>

using namespace std;

int n = 100;
const char FIN[] = "duom.txt";
const char FOUT[] = "rez.txt";

void skaitymas(int arr[]){
    ifstream fin(FIN);
	int k;
	fin >> k;

	for(int i = 0; i < k; i++){
        fin >> arr[i];
	}

	fin.close();
}

void salinimas(int arr[], int arr2[], int &k, int &l){
    for(int i = 0; i < k; i++){
        if(i % 2 == 0){
            arr2[l] = arr[i];
            l++;
        }
    }
}

void isvedimas(int arr[], int &k){
    ofstream fout(FOUT);

    for(int i = 0; i < k; i++){
        fout << arr[i] << endl;
        cout << arr[i] << endl;
	}

    fout.close();
}

int main(){
    ifstream fin(FIN);

	int arr[n], arr2[n], k, l = 0;
	fin >> k;

	skaitymas(arr);
    salinimas(arr,arr2,k,l);
    isvedimas(arr2,l);

	fin.close();
	return 0;
}

