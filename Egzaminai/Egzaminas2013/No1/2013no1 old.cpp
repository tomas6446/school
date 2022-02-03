#include <iostream>
#include <fstream>
#include <math.h>
const char FV[] = "Pradiniai duomenys.txt";
const char FD[] = "Rezultatas.txt";
using namespace std;
const int Cmax = 10;
void skaityti(const char FV[], int &n, int &m, string name[], int x[], int y[])
{
	ifstream fin(FV);
	fin >> n >> m;
	for(int i = 0; i < n; i ++)
		fin >> name[i] >> x[i] >> y[i];
	for(int i = 0; i < n; i ++)
		cout << name[i]<< " " << x[i] << " "<< y[i] << endl;
	fin.close();
}
void atstumas(int &n, int &m, int x[], int y[], int &k, int &atstum)
{
	for(int i = 0; i < n; i++)
	{
		atstum += abs(x[i]) + abs(y[i]);
		if(atstum*2 > m)
		{
			atstum -= abs(x[i]) + abs(y[i]);
			k = i-1;
			break;
		}
	} 
}
int main(int argc, char** argv) {
	int n, m, x[Cmax], y[Cmax], atstum, k;
	string name[Cmax];
	skaityti(FV, n, m, name, x, y);
	atstumas(n, m, x, y, k, atstum);
	cout << k+1 << " " << 2*atstum << " " << name[k] << endl;
	return 0;
}
