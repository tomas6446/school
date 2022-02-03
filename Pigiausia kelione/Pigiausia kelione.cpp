#include <iostream>
#include <fstream>
using namespace std;
const char FV[] = "Duomenys2.txt";
const char FD[] = "Rezultatas.txt";
struct kelione {
	string pavad;
	float bk, dk, kaina;
} k[30];
void read(int &n, float &b, float &d, int &m)
{
	char eil[15];
	ifstream fin(FV);
	fin >> b >> d >> m >> n;
	fin.ignore();
	for(int i = 0; i < n; i++)
	{
		fin.get(eil, sizeof eil);
		k[i].pavad = eil;
		
		fin >> k[i].bk >> k[i].dk;
		
		k[i].kaina = (b*(m/2)/100*k[i].bk)+(d*(m/2)/100*k[i].dk);
		fin.ignore();
	}
	fin.close();
}
int minimum(int n)
{
	float min = k[0].kaina;
	int index = 0;
	for(int i = 0; i < n; i++)
	{
		if(k[i].kaina < min)
		{
			min = k[i].kaina;
			index = i;	
		}	
	}
	return index;
}
void result(int n, int index)
{
	ofstream fout(FD);
	fout << k[index].kaina << endl;
	fout << k[index].pavad << k[index].bk << " " << k[index].dk << endl;
	fout.close();
}
int main(int argc, char** argv) {
	int n, m, index;
	float b, d;
	read(n, b, d, m);
	index = minimum(n);
	result(n, index);
	return 0;
}
