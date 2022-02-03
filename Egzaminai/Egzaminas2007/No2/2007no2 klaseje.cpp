#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;
const char FV[] = "Duomenys.txt";
const char FD[] = "Rezultatas.txt";
struct Grybautojas {
	string vardas;
	int b = 0, r = 0, l = 0;
	int sum;
} g[100];
void skaityti(const char FV[], int &k)
{
	ifstream fin(FV);
	fin >> k;
	for(int i = 0; i < k; i++)
	{
		int n;
		fin >> g[i].vardas >> n;
		for(int j = 0; j < n; j++)
		{
			int b, r, l;
			fin >> b >> r >> l;
			g[i].b += b;
			g[i].r += r;
			g[i].l += l;
		}
		g[i].sum = g[i].b+g[i].r+g[i].l;
	}
	fin.close();
}
int geriausiasgrybautojas(int k)
{
	int maximum = g[0].sum;
	for(int i = 0; i < k; i++)
	{
		if(maximum < g[i].sum)
		{
			maximum = g[i].sum;
			return i+1;
		}		
	}
}
void rasyti(const char FD[], int k)
{
	ofstream fout(FD);
	int geriausias = geriausiasgrybautojas(k);
	for(int i = 0; i < k; i++)
		cout << g[i].vardas << setw(abs(15-g[i].vardas.length())) << right << g[i].b << setw(5) << right << g[i].r << setw(5) << right << g[i].l << right << endl;
	cout << g[geriausias-1].vardas << " " << setw(abs(15-g[geriausias-1].vardas.length())) << right << endl;
}
int main(int argc, char** argv) {
	int k, geriausias;
	skaityti(FV, k);
	rasyti(FD, k);
	return 0;
}
