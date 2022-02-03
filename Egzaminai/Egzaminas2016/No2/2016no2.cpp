#include <iostream>
#include <fstream>
using namespace std;

const char FV[] = "Duomenys.txt";
const char FD[] = "Rezultatas.txt";
struct Vytautas {
	string pavad = " ";
	string uniquepavad;
	int kart = 0;
	int uniquekart = 0;
} v[50];
void rikiavimas(int k)
{
	for(int i = 0; i < k-1; i++)
	{
		for(int j = i+1; j < k; j++)
		{
			if(v[i].uniquekart < v[j].uniquekart)
			{
				swap(v[i], v[j]);
			}
			else if(v[i].uniquekart == v[j].uniquekart)
			{
				if(v[i].uniquepavad > v[j].uniquepavad)
				{
					swap(v[i], v[j]);
				}
			}
		}
	}
}
int main(int argc, char** argv) {
	int n;
	ifstream fin(FV);
	fin >> n;
	int k = 0;
	int uniquepavad[10];
	int uniquekart[10] = {0};
	for(int i = 0; i < n; i++)
	{
		fin >> v[i].pavad >> v[i].kart;
		v[i].uniquepavad = v[i].pavad;
	}
	fin.close();
	for(int i = 0; i < k-1; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(v[i].pavad == v[j].pavad)
			{
                uniquepavad[i] = v[i].pavad;
                k++;
			}
		}
	}

	for(int i = 0; i < k; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(v[i].uniquepavad == v[j].pavad)
			{
				uniquekart[i] += v[j].kart;
			}
		}
	}
	rikiavimas(k);
	ofstream fout(FD);
	for(int i = 0; i < k; i++)
	{
		cout << v[i].uniquepavad << " " << v[i].uniquekart << endl;
	}
	fout.close();
	return 0;
}

