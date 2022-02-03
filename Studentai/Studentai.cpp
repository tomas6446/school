#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;
const char FV[] = "Duomenys.txt";
const char FD[] = "Rezultatas.txt";
struct Traukiniai {
	string pav;
	int val, min;
	int pval, pmin;
	int trukval, trukmin;
}t[100];
void read(const char FV[], int &n)
{
	ifstream fin(FV);
	fin >> n;
	for(int i = 0; i < n; i ++)
		fin >> t[i].pav >> t[i].val >> t[i].min >> t[i].pval >> t[i].pmin;	
	fin.close();
}
void time(int &n, int kiekv, int kiekm)
{
	for(int i = 0; i < n; i++)
	{
		//-----------------
		t[i].trukmin = abs((t[i].val*60+t[i].min)-(t[i].pval*60+t[i].pmin));
		t[i].trukval = t[i].trukmin/60;
		t[i].trukmin -= t[i].trukval*60;
		if(t[i].trukval == 0 && t[i].trukmin == 0)
		{
			t[i].trukval = 24;
			t[i].trukmin = 0;
		}
		//-----------------
		kiekv += t[i].trukval;
		kiekm += t[i].trukmin;
		if(kiekm >= 60)
		{
			kiekv += kiekm/60;
			kiekm = kiekm/60;
		}
	}
}
void write(const char FD[], int n)
{
	ofstream fout(FD);
	for(int i = 0; i < n; i++)
		fout << t[i].pav << setw(abs(t[i].pav.length()-20)) << right << t[i].trukval << setw(3) << right << t[i].trukmin << endl;
	fout.close();
}
int main(int argc, char** argv) {
	int n, kiekv, kiekm;
	read(FV, n);
	time(n, kiekv, kiekm);
	write(FD, n);
	return 0;
}
