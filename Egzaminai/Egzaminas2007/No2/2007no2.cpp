#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;
const char FV[] = "Duomenys.txt";
const char FD[] = "Rezultatas.txt";
void bestone(int n, int i, int kiek, int &max, string &geriausias, string vardas[], int resb[], int resr[], int resl[])
{
	for(int i = 0; i < n; i++)
	{
		kiek = resb[i]+resr[i]+resl[i];
		if(max < kiek)
		{
			max = kiek;
			geriausias = vardas[i];
		}
	}		
}
void read(const char FV[], int &n, string vardas[], int d[], int b[], int r[], int l[], int resb[], int resr[], int resl[])
{
	ifstream fin(FV);
	fin >> n;
	for(int i = 0; i < n; i++)
	{
		fin >> vardas[i] >> d[i];
		for(int j = 0; j < d[i]; j++)
		{
			fin >> b[j] >> r[j] >> l[j];
			resb[i] += b[j];
			resr[i] += r[j];
			resl[i] += l[j];	
		}
	}
	fin.close();
}
void write(const char FD[], int &n, int resb[], int resr[], int resl[], string vardas[], string geriausias, int max, int kiek)
{
	ofstream fout(FD);	
	for(int i = 0; i < n; i++)
	{
		cout << vardas[i] << setw(abs(15-vardas[i].length())) << right << resb[i] << setw(5) << right << resr[i] << setw(5) << right << resl[i] << right << endl;
		bestone(n, i, kiek, max, geriausias, vardas, resb, resr, resl);
	}
	cout << geriausias << setw(abs(15-geriausias.length())) << right << max << endl;
	fout.close();
}
int main(int argc, char** argv) {
	int n, kiek, max = 0;
	string geriausias;;
	string vardas[100];
	int resb[50] = {0}, resr[50] = {0}, resl[50] = {0};
	int d[50],  b[500],  r[500],  l[500];
	read(FV, n, vardas, d, b, r, l, resb, resr, resl);
	write(FD, n, resb, resr, resl, vardas, geriausias, max, kiek);
	return 0;
}
