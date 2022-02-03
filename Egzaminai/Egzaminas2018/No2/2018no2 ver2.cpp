#include <iostream>
#include <fstream>

using namespace std;
const char FV[] = "U2.txt";
const char FD[] = "U2rez.txt";

struct Slidininkai {
	string vardas;
	int val, minut, sek;
} s[30], f[30];

void sortirovochka(int m)
{
	for(int i = 0; i < m-1; i++)
	{
		for(int j = i+1; j < m; j++)
		{
			if(f[i].sek > f[j].sek)
				swap(f[j], f[i]);
			else if(f[i].sek == f[j].sek)
			{
				if(f[i].vardas > f[j].vardas)
					swap(f[j], f[i]);
			}
		}
	}
	for(int j = 0; j < m; j++)
	{
		f[j].minut = f[j].sek/60;
		f[j].sek = f[j].sek%60;
	}
}

void result(int m)
{
	ofstream fout(FD);
	for(int i = 0; i < m; i++)
		fout << f[i].vardas << " " << f[i].minut << " " << f[i].sek << endl;
	fout.close();
}

int main(int argc, char** argv) {
	int n, m;
	char vardas[20];

	ifstream fin(FV);
	fin >> n;
	fin.ignore();
	for(int i = 0; i < n; i++)
	{
		fin.get(vardas, sizeof vardas);
		s[i].vardas = vardas;
		fin >> s[i].val >> s[i].minut >> s[i].sek;
		s[i].sek += (s[i].val*3600) + (s[i].minut*60);
		fin.ignore();
	}
	fin >> m;
	fin.ignore();
	for(int i = 0; i < m; i++)
	{
		fin.get(vardas, sizeof vardas);
		f[i].vardas = vardas;
		fin >> f[i].val >> f[i].minut >> f[i].sek;
		f[i].sek += (f[i].val*3600) + (f[i].minut*60);
		f[i].minut = 0;
		fin.ignore();
	}
	fin.close();

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(s[i].vardas == f[j].vardas)
				f[j].sek -= s[i].sek;
		}
	}

	sortirovochka(m);
	result(m);

	return 0;
}
