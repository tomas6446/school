#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
const char FV[] = "Duomenys.txt";
const char FD[] = "Rezultatas.txt";
struct Krepsininkai {
	int k, t, laikas[40], plussum, minussum; // krepšininko numeris, laiku (aista ir/arba ilsetasi) skaicius, 
}krep[12];//eigiamas  skaicius – kiek  minuciu  buta  aikšteleje
	//neigiamas  skaicius – kiek  minuciu  sedeta  ant  atsarginiu  suolelio.
void read(const char FV[], int &n)
{
	ifstream fin(FV);
	fin >> n;
	for(int i = 0; i < n; i++)
	{
		fin >> krep[i].k >> krep[i].t;
		for(int j = 0; j < krep[i].t; j++)
			fin >> krep[i].laikas[j];
	}
	fin.close();
}
void maxminlaik(int &n, int &maxnum, int &maximum, int &minnum, int &minimum)
{
	for(int i = 0; i < n; i++)
	{
		if(maximum < krep[i].plussum)
		{
			maximum = krep[i].plussum;
			maxnum = krep[i].k;
		}
		if(minimum > krep[i].minussum)
		{
			minimum = krep[i].minussum;
			minnum = krep[i].k;
		}
	}
}
int main(int argc, char** argv) {
	int n, start[5], c = 0; 
	int maximum = krep[0].plussum;
	int minimum = krep[0].minussum;
	int maxnum, minnum;
	read(FV, n);

	for(int i = 0; i < n; i++)
	{
		if(krep[i].laikas[0] < 0)
			c-=1;	
		if(krep[i].laikas[0] > 0)
			start[i+c] = krep[i].k;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < krep[i].t; j++)
		{
			if(krep[i].laikas[j] > 0)
				krep[i].plussum += krep[i].laikas[j];	
			else if(krep[i].laikas[j] < 0)
				krep[i].minussum += krep[i].laikas[j];		
		}	
	}
	maxminlaik(n, maxnum, maximum, minnum, minimum);
	for(int i = 0; i < 5; i++)
		cout << start[i] << " ";
	cout << endl;
	cout << maxnum << " " << maximum << endl;
	cout << minnum << " " << minimum << endl;
	return 0;
}
