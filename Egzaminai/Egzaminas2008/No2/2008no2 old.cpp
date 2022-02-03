#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const char FV[] = "U2.txt";
const char FD[] = "U2rez.txt";
//-----
struct Transportas {
	string pav;
	int k;
	int ilgis = 0;
	int uniquenum;
	int num[100];
} t[100];
//-----
int ilgiausias(int n, int &maximum, int k)
{
	for(int i = 0; i < k; i++) // schitaju skolko vsego ostanovok imejet kazhdyj marshrut
	{
		for(int x = 0; x < n; x++)
		{
			for(int y = 0; y < t[x].k; y++)
			{
				if(t[i].uniquenum == t[x].num[y])
					t[i].ilgis += 1;
			}
		}
	}
	int maximumilgis = 0;
	for(int i = 0; i < k; i++) // kakoj marshrut imejet bolshe vsego ostanovok
	{
		if(maximumilgis < t[i].ilgis)
		{
			maximumilgis = t[i].ilgis;
			maximum = t[i].uniquenum;
		}
	}
	return maximum;
}
//------
void read(const char FV[], int &n, int &k)
{
	char eil[20];
	ifstream fin(FV);
	fin >> n;
	fin.ignore();
	for(int i = 0; i < n; i++) // schityvaju file
	{
		fin.ignore();
		fin.get(eil, 20);
		t[i].pav = eil;
		fin >> t[i].k;
		for(int j = 0; j < t[i].k; j++)
		{
			fin >> t[i].num[j];
			t[k].uniquenum = t[i].num[j];
			fin.ignore();
			k+=1; // razmer massiva unikaljnyh nomerov
		}
	}
	for(int i = 0; i < k; i++) // nahozhu unikalnyje nomera marshrutov
	//(objedeniaju vsio v odin massiv i udaliaju odinakovyje nomera)
	{
		for(int j = i+1; j < k; j++)
		{
			if(t[i].uniquenum == t[j].uniquenum)
			{
				for(int x = j; x < k-1; x++)
					t[x].uniquenum = t[x+1].uniquenum;
				k-=1;
			}
		}
	}
	fin.close();
}
//-----
void write(const char FD[], int n, int maximum)
{
	ofstream fout(FD);
	fout << maximum << endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < t[i].k; j++)
		{
			if(maximum == t[i].num[j]) // sravnivaju kakije ostanovki imejut etot nomer
				fout << t[i].pav << endl;
		}
	}
	fout.close();
}
//-----
int main(int argc, char** argv) {
	int n, k = 0; // n - razmer structury, k - razmer massiva s unikalnymi nomerami
	int maximum;
	read(FV, n, k);
	maximum = ilgiausias(n, maximum, k);
	write(FD, n, maximum);
	return 0;
}
