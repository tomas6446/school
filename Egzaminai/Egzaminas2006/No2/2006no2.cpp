#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;
const char FV[] = "Duomenys.txt";
const char FD[] = "Rezultatas.txt";
void read(const char FV[], int &n, int &v, float &val, float &min, string st[], float atstum[])
{
	ifstream fin(FV);
	fin >> n >> v >> val >> min;
	for(int i = 0; i < n; i++)
		fin >> st[i] >> atstum[i];
	fin.close();
}
void skaiciavimas(int n, int v, float val, float min, string st[], float atstum[], float laikas[])
{
	for(int i = 0; i < n; i++)
	{
		
	}
}
int main(int argc, char** argv) {
	int n, v; 
	float laikas[100], atstum[100], val, min;
	string st[100]; 
	read(FV, n, v, val, min, st, atstum);
	skaiciavimas(n, v, val, min, st, atstum, laikas);
	return 0;
}
