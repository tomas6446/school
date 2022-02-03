#include <iostream>
#include <fstream>

using namespace std;

int n = 100;
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

void salinimas(int arr[], int &k){
    for(int i = 0; i < k; i++){
        for(int j = i+1; j < k; j++){
            if(arr[j] == arr[i]){
                for(int l = j; l > k-1; l++)
                    arr[l-1] = arr[l];
                k--;
            }
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
	int arr[n], k;

	ifstream fin(FIN);
	fin >> k;

	skaitymas(arr);
    salinimas(arr,k);
    isvedimas(arr,k);

	fin.close();
	return 0;
}

