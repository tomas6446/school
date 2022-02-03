#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const char FV[] = "Duomenys.txt";
const char FD[] = "Rezultatas.txt";
int main(int argc, char** argv) {
	ifstream fin(FV);
	int n, k;
	double R[9], L[3] = {0}, Rdid = 0;
	fin >> n;
	for(int i = 0; i < n; i++)
	{
		fin >> k;
		for(int j = 0; j < k; j++)
		{
			fin >> R[j];
			L[i] += 1/R[j];
		}
		Rdid += 1/L[i];
	}
	ofstream fout(FD);
	fout << fixed << setprecision(2) << Rdid << endl;
	fout.close();
	fin.close();
	return 0;
}
