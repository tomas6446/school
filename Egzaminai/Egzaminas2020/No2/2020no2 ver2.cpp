#include <iostream>
#include <fstream>
using namespace std;

struct Zvejai {
	string zvpav;
	string zuvpav[5];
	int zuvsk;
	int zuvkg[5] = {0};
	int task = 0;
} zv[30];

struct Zuvys {
	string zuvpav;
	int zuvtask;
	int zuvkg = 0;
} zuv[30];

void sortirovka(int n, int k)
{
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++) {
			if(zv[j].task > zv[i].task) {
                swap(zv[i], zv[j]);
			}
			else if(zv[j].task == zv[i].task) {
				if(zv[j].zvpav < zv[i].zvpav) {
                    swap(zv[i], zv[j]);
				}
			}
		}
	}
	for(int i = 0; i < k-1; i++) {
		for(int j = i+1; j < k; j++) {
			if(zuv[j].zuvkg > zuv[i].zuvkg) {
                swap(zuv[i], zuv[j]);
			}
			else if(zv[j].task == zv[i].task) {
				if(zuv[j].zuvpav < zuv[i].zuvpav) {
                    swap(zuv[i], zuv[j]);
				}
			}
		}
	}
}

int main(int argc, char** argv) {

	int n, k;
	char eil[21];

	ifstream fin("U2.txt");
	fin >> n;
	fin.ignore();
	for(int i = 0; i < n; i++) {
		fin.get(eil, sizeof eil);
		zv[i].zvpav = eil;
		fin >> zv[i].zuvsk;
		fin.ignore();
		for(int j = 0; j < zv[i].zuvsk; j++) {
			fin.get(eil, sizeof eil);
			zv[i].zuvpav[j] = eil;
			fin >> zv[i].zuvkg[j];
			fin.ignore();
		}
	}
	fin >> k;
	fin.ignore();
	for(int i = 0; i < k; i++) {
		fin.get(eil, sizeof eil);
		zuv[i].zuvpav = eil;
		fin >> zuv[i].zuvtask;
		fin.ignore();
	}
	fin.close();

	for(int i = 0; i < n; i++) { // prisvajevaji tochki
		for(int j = 0; j < zv[i].zuvsk; j++) {
			if(zv[i].zuvkg[j] < 200) {
				zv[i].task += 10;
			}
			else if(zv[i].zuvkg[j] >= 200) {
				zv[i].task += 30;
			}
		}
	}

	for(int i = 0; i < k; i++) {
		for(int j = 0; j < n; j++) {
			for(int x = 0; x < zv[j].zuvsk; x++) {
				if(zuv[i].zuvpav == zv[j].zuvpav[x]) { // sravnivaju rybu s rybami, kotoryje spojmal rybak
					zuv[i].zuvkg += zv[j].zuvkg[x];
					zv[j].task += zuv[i].zuvtask;
				}
			}
		}
	}

	sortirovka(n, k);

	ofstream fout("U2rez.txt");
	fout << "Dalyviai" << endl;
	for(int i = 0; i < n; i++)
		fout << zv[i].zvpav << zv[i].task << endl;
	fout << "Laimikis" << endl;
	for(int i = 0; i < k; i++)
		fout << zuv[i].zuvpav << zuv[i].zuvkg << endl;
	fout.close();

	return 0;
}
