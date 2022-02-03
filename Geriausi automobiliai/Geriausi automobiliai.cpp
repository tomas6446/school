#include <iostream>
#include <fstream>
using namespace std;
const char FV[] = "Duomenys.txt";
const char FD[] = "Rezultatas.txt";
struct automobiliai {
	string pav;
	int met, men, kaina;
} a[30];
void read(int &n)
{
	char eil[25];
	ifstream fin(FV);
	fin >> n;
	fin.ignore();
	for(int i = 0; i < n; i++)
	{
		fin.get(eil, sizeof eil);
		a[i].pav = eil;
		
		fin >> a[i].met >> a[i].men >> a[i].kaina;
		fin.ignore();
	}
	fin.close();
}
void rikiavimas(int n)
{
	for(int i = 0; i < n-1; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			for(int x = 0; x < 25; x++)
			{
				if(a[i].pav[x] > a[j].pav[x])
				{
					swap(a[j],a[i]);
					break;
				}
				else if(a[i].pav[x] == a[j].pav[x])
				{
					if((a[i].met*12)+a[i].men < (a[j].met*12)+a[j].men)
					{
						swap(a[i], a[j]);
					}	
				}
				else 
					break;
			}
		}
	}
}
void result(int n)
{
	ofstream fout(FD);
	for(int i = 0; i < n; i++)
		fout << a[i].pav << a[i].met << " " << a[i].men << " " << a[i].kaina << endl;
	fout.close();
}
int main(int argc, char** argv) {
	int n;
	read(n);
	rikiavimas(n);
	result(n);
	return 0;
}
