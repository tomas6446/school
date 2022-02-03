#include <iostream>
#include <fstream>
using namespace std;
const char FV[] = "duompaj.txt";
const char FD[] = "rezpaj.txt";
const int Cmax = 20;
void skaitymas(const char FV[], int P[], int &n)
{
	ifstream fin(FV);
	fin >> n;
	for(int i = 1; i <= n; i++)
		fin >> P[i];
	fin.close();
}
void salinimas(int &n, int P[])
{
	for(int i = 1; i <= n; i++)
	{
		if(i/2 != 0)
		{
			for(int y = i; y < n-1; y++)
				P[y] = P[y+1];
			n--;
		}		
	}
}
void rasymas(const char FD[], int P[], int n)
{
	ofstream fout(FD);
	for(int i = 1; i <= n; i++)
		fout << P[i] << " ";
	fout.close();
	
}
int main(int argc, char** argv) {
	int n, P[Cmax];
	skaitymas(FV, P, n);
	salinimas(n, P);
	rasymas(FD, P, n);
	return 0;
}
