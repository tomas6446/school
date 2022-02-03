#include <iostream>
#include <fstream>
using namespace std;
const char FV[] = "Duomenys.txt";
const char FD[] = "Rezultatas.txt";
const int Cmax = 20;
struct Avys {
	string name;
	char dnr[];
	int koof = 0;
} dnk[Cmax];
void read(const char FV[], int &n, int &m, int &num)
{
	ifstream fin(FV);
	fin >> n >> m >> num;
	for(int i = 1; i <= n; i++)
	{
		fin >> dnk[i].name;
		for(int y = 0; y < m; y++)
		{
			fin >> dnr[i].dnr[y];
			dnk[i].koof = 0;
		}
	}
	fin.close();
}
void sutamp(int n, int m, int num)
{
	for(int i = 1; i <= n; i++)
	{
		if(i != num)
		{
			for(int y = 0; y < m; y++)
			{
				if(dnk[num].dnr[y] == a[i].dnr[y])
				{
					dnk[y].koof++;
				}
			}
		}

	}
}
//rikiavimas <---
void result(const char FD[], int n, int num)
{
	ofstream fout(FD);
	for(int i = 1; i <= n; i++)
	{
		if(i!=num)
			cout << dnk[i].name << " " << a[i].koof << endl;
	}
	fout.close();
}

int main(int argc, char** argv) {
	int n, m, num;
	char dnr[Cmax];
	string name[Cmax];
	read(FV, n, m, num);
	sutamp(n, m, num);
	//rikiavimas(n, m, num);
	result(FD, n, num);
	return 0;
}
