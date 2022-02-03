#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
const char FV[] = "duom.txt";
const char FD[] = "rez.txt";
struct Dalyviai
{
	string vard;
	int at[11], tt[11];
	int atsum, ttsum;
	int sum = 0;
}d[10];
//______________________________________________________________
void skaityti(int &n, int &teis)
{
	ifstream fin(FV);
	fin >> n >> teis;
	for(int i = 0; i < n; i++)
	{
		fin.ignore();
		char eil[21];
		fin.get(eil, 21);
		d[i].vard = eil;
		cout << d[i].vard << endl;
		for(int j = 0; j < teis; j++) {
			fin >> d[i].tt[j];
			cout << d[i].tt[j] << " ";
		}
		cout << endl;
		for(int j = 0; j < teis; j++) {
			fin >> d[i].at[j];
			cout << d[i].at[j] << " ";
		}
		cout << endl;
	}
	fin.close();
}
//______________________________________________________________
int GautiTaskai(int M[0], int teis)
{
	int sum = M[0];
	int maxi = M[0];
	int mini = M[0];
	for(int j = 0; j < teis; j++)
	{
		sum += M[j];
		if(M[j] > maxi)
			maxi = M[j];
		if(M[j] < mini)
			mini = M[j];
	}
	sum -= maxi-mini;
	return sum;
}
//________________________________________________________________
void Rikiuoti()
{
	
}
//_________________________________________________________________
int main()
{
	int n, teis, sum;
	skaityti(n, teis);
	for(int i = 0; i < n; i++)
	{
		d[i].ttsum = GautiTaskai(d[i].tt, teis);
		d[i].atsum = GautiTaskai(d[i].at, teis);
		d[i].sum = d[i].ttsum+d[i].atsum;
		cout << d[i].sum << endl;
	}
    return 0;
}
