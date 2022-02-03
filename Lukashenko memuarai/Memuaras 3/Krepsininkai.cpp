#include <iostream>
#include <fstream>
using namespace std;
const char FV[] = "Duomenys.txt";
const char FV2[] = "Naujokai.txt";
const char FD[] = "Rezultatas.txt";
const int Cmax = 20;
void skaitymas(const char FV[], int Krep[], int &n)
{
	ifstream fin(FV);
	fin >> n;
	for(int i = 0; i < n; i++)
		fin >> Krep[i];
	fin.close();
}
void iterpimas(int Krep[], int Nauj[], int &n, int k)
{
	int kur[k];
	if(n < Cmax)
	{
		for(int i = 0; i < k; i++)
		{
			for(int y = 0; y < n; y++)
			{
				if(Nauj[i] > Krep[y] && Krep[y+1] > Nauj[i])
					kur[i] = y+1;	
			}
			for(int j = n; j > kur[i]; j--)
				Krep[j] = Krep[j-1];
			Krep[kur[i]] = Nauj[i];
			n++;
		}
	}
}
void rasymas(const char FD[], int Krep[], int n)
{
	ofstream fout(FD);
	for(int i = 0; i < n; i++)
		fout << Krep[i] << " ";
	fout.close();
}
int main(int argc, char** argv) {
	int n, k, Krep[Cmax], Nauj[Cmax];
	skaitymas(FV, Krep, n);
	skaitymas(FV2, Nauj, k);
	iterpimas(Krep, Nauj, n, k);
	rasymas(FD, Krep, n);
	return 0;
}
