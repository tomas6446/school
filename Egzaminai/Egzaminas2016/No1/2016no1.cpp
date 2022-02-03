#include <iostream>
#include <fstream>
using namespace std;
const char FV[] = "Duomenys.txt";
const char FD[] = "Rezultatas.txt";
int sunk(int kupr, int max)
{
	if(kupr > max)
		max = kupr;
	return max;
}
int kieklengv(const char FV[], int kupr, int max, int kiek)
{
	ifstream fin(FV);
	int x;
	fin >> x;
	for(int i = 0; i < x; i++)
	{
		fin >> kupr;
		if(kupr*2 <= max)
			kiek++;
	}
	return kiek;
	fin.close();
}
int main(int argc, char** argv) {
	ifstream fin(FV);
	int x, kupr, max = 0, kiek = 0;
	fin >> x;
	for(int i = 0; i < x; i++)
	{
		fin >> kupr;
		max = sunk(kupr, max);	
	}
	kiek = kieklengv(FV, kupr, max, kiek);
	fout << max << " " << kiek;
	fin.close();
	return 0;
}
