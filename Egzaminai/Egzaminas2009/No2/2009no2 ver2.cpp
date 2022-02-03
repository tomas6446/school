#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const char FV[] = "U2.txt";
const char FD[] = "U2rez.txt";
//_______________________________________
struct Varzybos {
	int k, laimetoju; // k = skolko uchastnikov v grupe, laimetoju - skolko pobeditelej v grupe
	string vardas[50];
	int min[50], sek[50];
} v[8];
//________________________________________
void rezultatas(int n)
{
	ofstream fout(FD);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < v[i].laimetoju; j++)
		{
			v[i].min[j] += v[i].sek[j]/60;
			v[i].sek[j] = v[i].sek[j]%60;	
			cout << v[i].vardas[j] << v[i].min[j] << " " << v[i].sek[j] << endl;
		}
	}
	fout.close();
}
//_______________________________________
int main(int argc, char** argv) {
	int n; // skolko grup
	char eil[20];
	ifstream fin(FV);
	fin >> n;
	fin.ignore();
	for(int i = 0; i < n; i++)
	{
		fin >> v[i].k;
		//__________________________ skolko pobeditelej v kazhdoj grupe
		v[i].laimetoju = v[i].k/2;
		//__________________________
		fin.ignore();
		for(int j = 0; j < v[i].k; j++)
		{
			fin.get(eil, sizeof eil);
			v[i].vardas[j] = eil;
			fin >> v[i].min[j] >> v[i].sek[j];
			v[i].sek[j] += v[i].min[j]*60;
			v[i].min[j] = 0;
			fin.ignore();
		}
		//________________________________ sorteruju po sekundam 
		for(int j = 0; j < v[i].k; j++)
		{
			for(int y = j+1; y < v[i].k; y++)
			{
				if(v[i].sek[j] > v[i].sek[y])
				{
					swap(v[i].sek[j], v[i].sek[y]);
					swap(v[i].vardas[j], v[i].vardas[y]);
				}
			}	
		}
		//________________________________ pobeditelj tot u kogo menshe vsego sekund v kazhdoj grupe
	}
	rezultatas(n);
	fin.close();
	return 0;
}
