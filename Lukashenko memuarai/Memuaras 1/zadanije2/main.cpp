#include <iostream>
#include <fstream>

using namespace std;

int cmax = 100;
const char FIN[] = "duom.txt";
const char FIN2[] = "duom2.txt";
const char FOUT[] = "rez.txt";

void skaitymas(int arr[], int arr2[]){
    ifstream fin2(FIN2);
	ifstream fin(FIN);

	int k, k2;

	fin >> k;
	fin2 >> k2;

	for(int i = 0; i < k; i++)
		fin >> arr[i];
	for(int i = 0; i < k2; i++)
		fin2 >> arr2[i];

	fin.close();
	fin2.close();
}

void iterpimas(int arr[], int arr2[], int &k, int &k2){
	for(int i = 0; i < k2; i++){
		arr[k] = arr2[i];
		k++;
	}
}

void isvedimas(int arr[], int arr2[], int &k, int &k2){
    ofstream fout(FOUT);
    int temp;

    for(int i = 0; i < k; i++){
        for(int j = i+1; j < k; j++){
            if(arr[j] < arr[i]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        fout << arr[i] << endl;
        cout << arr[i] << endl;
    }

    fout.close();
}

int main(){
    ifstream fin2(FIN2);
	ifstream fin(FIN);

	int arr[cmax], arr2[cmax], k, k2;

	fin >> k;
	fin2 >> k2;

	skaitymas(arr,arr2);
    iterpimas(arr,arr2,k,k2);
    isvedimas(arr,arr2,k,k2);

	fin.close();
	fin2.close();
	return 0;
}

