#include <iostream>
#include <fstream>
using namespace std;
const char FV[] = "Duomenys.txt";
const char FD[] = "Rezultatas.txt";
struct Dievai {
	string vard;
	int kieklyg = 0;
	int taskai = 0;
} d[50];
void read(const char FV[], int &n, int &k)
{
	int t;
	ifstream fin(FV);
	fin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		fin >> d[i].vard;
		for(int j = 0; j < k; j++)
		{
			fin >> t;
			if(t%2 == 0)
			{
				d[i].taskai += t;
				d[i].kieklyg++;
			}
			else if(t%2 != 0)
				d[i].taskai -= t;
		}		
	}
	fin.close();
}
void kasvaldovas(int n, int k, string &valdovas, int &kiek)
{
	int max = d[0].taskai;
	int maxlyg = d[0].kieklyg;
	int x;
	for(int i = 0; i < n; i++)
	{
		if(d[i].taskai > max)
		{
			max = d[i].taskai;
			x = i;
		}	
	}
	
}
int main(int argc, char** argv) {
	int n, k, kiek;
	string valdovas;
	read(FV, n, k);
	for(int i = 0; i < n; i++)
	{
		cout << d[i].vard << " ";
		cout << d[i].taskai;
		cout << endl;		
	}
	kasvaldovas(n, k, valdovas, kiek);
	cout << valdovas << " " << kiek << endl;
	return 0;
}
