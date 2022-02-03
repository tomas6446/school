#include <iostream>
#include <fstream>
using namespace std;
const char FV[] = "U2.txt";
const char FD[] = "U2rez.txt";
struct Slidininkai {
	string vardas;
	int val, min, sek;
} s[30];
struct Finish {
	string vardas;
	int val, min, sek;
} f[30];
//_______________________
void sort(int m)
{
	for(int i = 0; i < m-1; i++)
	{
		for(int j = i+1; j < m; j++)
		{
			if(f[i].sek > f[j].sek)
				swap(f[j], f[i]);
			else if(f[i].sek == f[j].sek)
			{
				if(f[i].vardas < f[j].vardas)
					swap(f[j], f[i]);	
			}	
		}
	}
}
//______________________
void result(int m)
{
	ofstream fout(FD);
	for(int i = 0; i < m; i++)
		fout << f[i].vardas << f[i].val << " " << f[i].min << " " << f[i].sek << endl;
	fout.close();
}
//_____________________
int main(int argc, char** argv) {
	int n, m;
	char vardas[30];
	//________________________________
	ifstream fin(FV);
	fin >> n;
	fin.ignore();
	for(int i = 0; i < n; i++)
	{
		fin.get(vardas, sizeof vardas);
		s[i].vardas = vardas;
		fin >> s[i].val >> s[i].min >> s[i].sek;
		fin.ignore();
	}
	fin >> m;
	fin.ignore();
	for(int i = 0; i < m; i++)
	{
		fin.get(vardas, sizeof vardas);
		f[i].vardas = vardas;
		fin >> f[i].val >> f[i].min >> f[i].sek;
		fin.ignore();
	}
	fin.close();
	//___________________________
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(s[i].vardas == f[j].vardas)
			{
				
				f[j].sek += (f[j].val*3600) + (f[j].min*60);
				s[i].sek += (s[i].val*3600) + (s[i].min*60);
				
				f[j].val = 0;
				f[j].min = 0;
				s[i].val = 0;
				s[i].min = 0;
				
				f[j].sek -= s[i].sek;
			}
		}
	}
	//__________________________
	sort(m);
	for(int j = 0; j < m; j++)
	{
		f[j].min = f[j].sek/60;
		f[j].sek = f[j].sek%60;
		f[j].val = f[j].min/60;
		f[j].min = f[j].min%60;
	}	
	result(m);
	//_________________________
	return 0;
}
