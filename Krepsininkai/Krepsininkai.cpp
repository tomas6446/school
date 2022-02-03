#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const char FV[] = "Pradiniai duomenys.txt";
const char FD[] = "Rezultatas.txt";
const int Cmax = 15;
void read(const char FV[], int &n, string name[], double ugis[], double balai[], double &p, double &k)
{
	ifstream fin(FV);
	fin >> n;
	for(int i = 0; i < n; i++)
		fin >> name[i] >> ugis[i] >> balai[i];	
	fin >> p >> k;
	fin.close();
}
int maximum(int n, double i[])
{
	int max = 0;
	for(int j = 0; j < n; j ++)
	{
		for(int y = j+1; y < n; y++)
		{
			if(i[y] > max)
				max = i[y];
		}
	}
	return max;
}
int main(int argc, char** argv) {
	ofstream fout(FD);
	int n, maxugis, maxbalai;
	string name[Cmax];
	double ugis[Cmax], balai[Cmax], p, k;
	read(FV, n, name, ugis, balai, p, k);
	fout << "-------------------------------------------" << endl;
	fout << "Vardas" << right  << setw(10) << "Ugis" << right << setw(10)  << "Taskai" << endl;
	fout << "-------------------------------------------" << endl;
	for(int i = 0; i < n; i++)
	{
		maxugis = maximum(n, ugis);
		maxbalai = maximum(n, balai);
		maxugis = maxugis*(1 - p/100);
		maxbalai = maxbalai*(1 - k/100);;
		if(ugis[i] >= maxugis || balai[i] >= maxbalai)
			fout << name[i] << right  << setw(10) << ugis[i] << right  << setw(10) << balai[i]  << endl;
	}
	fout << "-------------------------------------------" << endl;
	fout.close();
	return 0;
}
