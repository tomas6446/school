#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FV[] = "U2.txt";
const char FD[] = "U2rez.txt";

struct Varzybos {
	string vardas[50], rezvardas;
	int minut[50], sek[50], rezminut, rezsek;
} v[8];

void rezultatas(int t)
{
	ofstream fout(FD);
	for(int i = 0; i < t; i++)
	{
		v[i].rezminut = v[i].rezsek/60;
		v[i].rezsek = v[i].rezsek%60;
		cout << setw(20) << left << v[i].rezvardas << v[i].rezminut << " " << v[i].rezsek << endl;
	}//vyvod
	fout.close();
}

int main(int argc, char** argv) {
	int n, k, t = 0;
	char eil[20];
	ifstream fin(FV);
	fin >> k;
	for(int i = 0; i < k; i++)
	{
		fin >> n;
		fin.ignore();
		for(int j = 0; j < n; j++)
		{
			fin.get(eil, sizeof eil);
			v[i].vardas[j] = eil;
			fin >> v[i].minut[j] >> v[i].sek[j];
			v[i].sek[j] += v[i].minut[j]*60;
			v[i].minut[j] = 0;
			fin.ignore();
		}//vvod
		for(int j = 0; j < n-1; j++)
		{
			for(int y = j+1; y < n; y++)
			{
				if(v[i].sek[j] > v[i].sek[y])
				{
					swap(v[i].sek[j], v[i].sek[y]);
					swap(v[i].vardas[j], v[i].vardas[y]);
				}
			}
		}//sortiruju po sekundam
		for(int j = 0; j < n/2; j++)
		{
			v[t].rezvardas = v[i].vardas[j];
			v[t].rezminut = v[i].minut[j];
			v[t].rezsek = v[i].sek[j];
			t++;
		}//rezultas zapisyvaju v otdeljnyj massiv struktury
	}
	for(int i = 0; i < t-1; i++)
	{
		for(int j = i+1; j < t; j++)
		{
			if(v[i].rezsek > v[j].rezsek)
			{
				swap(v[i].rezsek, v[j].rezsek);
				swap(v[i].rezvardas, v[j].rezvardas);
			}
		}
	}//sortiruju rezultat
	rezultatas(t); //vyvozhu
	fin.close();
	return 0;
}
