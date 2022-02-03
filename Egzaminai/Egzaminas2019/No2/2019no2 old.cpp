#include <iostream>
#include <fstream>
using namespace std;

struct start
{ // structura startujushih
	string pav; // vardas
	int stnum, val, minim, sek; // vremia kogda startoval
} s[30];

struct finish
{ // structura finishistov
	string finishpav; // finishist
	int numpab, valpab, minpab, sekpab; // vremia kogda finishiroval
	int saudym[5]; // skolko shtravnyh;
} f[30];

void sortirovka(int m) // sortirovka po sekundam
{
	for(int i = 0; i < m; i++)
	{
		for(int j = i+1; j < m; j++)
		{
			if(f[i].sekpab > f[j].sekpab)
            {
                swap(f[i], f[j]);
            }
		}
		f[i].minpab = f[i].sekpab/60; // konvertiruju v chasy, minuty, sekundy
		f[i].sekpab = f[i].sekpab%60;
		f[i].valpab = f[i].minpab/60;
		f[i].minpab = f[i].minpab%60;
	}
}

void rezultatas(int m)
{
	ofstream fout("U2rez.txt");
	cout << "Merginos" << endl;
	for(int i = 0; i < m; i++)
	{
		if(f[i].numpab/100 == 1)
        {
            cout << f[i].numpab << " " << f[i].finishpav << f[i].valpab << "  " << f[i].minpab << "  " << f[i].sekpab << endl;
        }
	}
	cout << "Vaikinai" << endl;
	for(int i = 0; i < m; i++)
	{
		if(f[i].numpab/100 == 2)
        {
            cout << f[i].numpab << " " << f[i].finishpav << f[i].valpab << "  " << f[i].minpab << "  " << f[i].sekpab << endl;
        }
	}
	fout.close();
}

int main(int argc, char** argv) {

	int n, m; // n, m - skolko v spiske liudej
	char eil[21];

	ifstream fin("U2.txt");
	fin >> n;
	fin.ignore();
	for(int i = 0; i < n; i++) // vvod starta
	{
		fin.get(eil, 21);
		s[i].pav = eil;
		fin >> s[i].stnum >> s[i].val >> s[i].minim >> s[i].sek;
		fin.ignore();
	}
	fin >> m;
	for(int i = 0; i < m; i++) // vvod finisha
	{
		fin >> f[i].numpab >> f[i].valpab >> f[i].minpab >> f[i].sekpab;
		if(f[i].numpab/100 == 1)
		{
			for(int x = 0; x < 2; x++)
            {
                fin >> f[i].saudym[x];
            }
		}
		else if(f[i].numpab/100 == 2)
		{
			for(int x = 0; x < 4; x++)
            {
                fin >> f[i].saudym[x];
            }
		}
	}
    fin.close();

	for(int i = 0; i < n; i++) // skolko vremeni ot starta do finisha
	{
		for(int j = 0; j < m; j++)
		{
			if(s[i].stnum == f[j].numpab)
			{
				f[j].finishpav = s[i].pav;
				if(f[j].numpab/100 == 1) // shtraf dlia devochek
				{
					for(int x = 0; x < 2; x++)
                    {
                        f[j].sekpab += (5-f[j].saudym[x])*60;
                    }
				}
				else if(f[j].numpab/100 == 2) // shtraf dlia malchikov
				{
					for(int x = 0; x < 4; x++)
                    {
                        f[j].sekpab += (5-f[j].saudym[x])*60;
                    }
				}
				f[j].sekpab += f[j].valpab*3600+f[j].minpab*60; // skolko sekund vsego
				s[i].sek += s[i].val*3600+s[i].minim*60; // skolko sekund vsego
				f[j].valpab = 0
                f[j].minpab = 0;
				f[j].sekpab -= s[i].sek;
			}
		}
	}
	sortirovka(m);
	rezultatas(m);

	return 0;
}
