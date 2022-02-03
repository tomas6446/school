#include <iostream>
#include <fstream>
using namespace std;
const int Cmax = 20;
void skaitymas(int &n, int S[])
{
	ifstream fin("Pradiniai duomenys.txt");
	fin >> n;
	for(int i = 0; i < n; i++)
		fin >> S[i];
	fin.close();
}
void iterpimas(int &n, int m, int &k, int S[])
{
	for(int i = 0; i < n; i++)
	{
		if(S[i] == m)
			k = i;
	}
	if(n < Cmax)
	{
		for(int j = n; j > k; j--)
		S[j] = S[j-1];
		S[k] = m;
		n++;
	}
}
void rasymas(int n, int S[])
{
	ofstream fout("Rezultatas.txt");
	for(int i = 0; i < n; i++)
		fout << S[i] << " ";
	fout.close();
}
int main(int argc, char** argv) {
	int n, m = 11, k, S[Cmax];
	skaitymas(n, S);
	iterpimas(n, m, k, S);
	rasymas(n, S);
	return 0;
}
