#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const char FV[] = "Duomenys.txt";
const char FD[] = "Rezultatas.txt";
struct Mokiniai {
	string vard;
	int paz[15];
	double vid = {0};
}m[20];
void read(const char FV[], int &n, int &p, double &v)
{
	char eil[20];
	ifstream fin(FV);
	fin >> n >> p >> v;
	fin.ignore();
	for(int i = 0; i < n; i++)
	{
		fin.get(eil, 20);
		m[i].vard = eil;
		fin.ignore();
		for(int j = 0; j < p; j++)
		{
			fin >> m[i].paz[j];
			fin.ignore();
		}
	}
	fin.close();
}

void vidurkis(int n, int p)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < p; j++)
			m[i].vid += m[i].paz[j];
		m[i].vid = m[i].vid/p;
	}
}

int pirmunu(int n, double v, int k)
{
	for(int i = 0; i < n; i++)
		if(m[i].vid >= v) k++;	
	return k;	
}

void rezultatas(int n, int p, int kiek)
{
	ofstream fout(FD);
	for(int i = 0; i < n; i++)
	{
		fout << setw(20) << left << m[i].vard;
		fout << fixed << setprecision(1) << m[i].vid << endl;
	}	
	fout << kiek << endl;
	fout.close();
}

int main(int argc, char** argv) {
	int n, p, k = 0;
	double v;
	read(FV, n, p, v);
	vidurkis(n, p);
	int kiek = pirmunu(n, v, k);
	rezultatas(n, p, kiek);
	return 0;
}
