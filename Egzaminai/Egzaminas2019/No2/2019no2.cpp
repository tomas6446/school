#include <iostream>
#include <fstream>
using namespace std;

struct Sportas
{ // structura startujushih i finishistov
	string pav; // vardas, pavarde
	int num, val, minut, sek; // vremia kogda startoval ili finishiroval
} start[30], finish[30];

void sortirovka(int m) // sortirovka
{
	for(int i = 0; i < m-1; i++)
	{
		for(int j = i+1; j < m; j++)
		{
			if(finish[i].sek > finish[j].sek)
            {
                swap(finish[i], finish[j]);
            }
            else if(finish[i].sek == finish[j].sek)
            {
                if(finish[i].pav > finish[j].pav)
                {
                    swap(finish[i], finish[j]);
                }
            }
		}
	}
}

void rezultatas(int m)
{
	ofstream fout("U2rez.txt");
	fout << "Merginos" << endl;
	for(int i = 0; i < m; i++)
	{
		if(finish[i].num/100 == 1)
        {
            fout << finish[i].num << " " << finish[i].pav << finish[i].sek/3600 << " " << finish[i].sek%3600/60 << " " << finish[i].sek%60 << endl;
        }
	}
	fout << "Vaikinai" << endl;
	for(int i = 0; i < m; i++)
	{
		if(finish[i].num/100 == 2)
        {
            fout << finish[i].num << " " << finish[i].pav << finish[i].sek/3600<< " " << finish[i].sek%3600/60 << " " << finish[i].sek%60 << endl;
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
		fin.get(eil, sizeof eil);
		start[i].pav = eil;
		fin >> start[i].num >> start[i].val >> start[i].minut >> start[i].sek;
		start[i].sek += start[i].val*3600+start[i].minut*60; // skolko sekund vsego
		fin.ignore();
	}
	fin >> m;
	for(int i = 0; i < m; i++) // vvod finisha
	{
	    int bauda;
		fin >> finish[i].num >> finish[i].val >> finish[i].minut >> finish[i].sek;
		finish[i].sek += finish[i].val*3600+finish[i].minut*60; // skolko sekund vsego
		if(finish[i].num/100 == 1) // shtraf dlia devochek
		{
			for(int x = 0; x < 2; x++)
            {
                fin >> bauda;
                finish[i].sek += (5-bauda)*60;
            }
		}
		else if(finish[i].num/100 == 2) // shtraf dlia malchikov
		{
			for(int x = 0; x < 4; x++)
            {
                fin >> bauda;
                finish[i].sek += (5-bauda)*60;
            }
		}
	}
    fin.close();

	for(int i = 0; i < n; i++) // skolko vremeni ot starta do finisha
	{
		for(int j = 0; j < m; j++)
		{
			if(start[i].num == finish[j].num)
			{
				finish[j].pav = start[i].pav;
				finish[j].sek -= start[i].sek;
				finish[j].val = 0;
				finish[j].minut = 0;
			}
		}
	}
	sortirovka(m);
	rezultatas(m);

	return 0;
}
