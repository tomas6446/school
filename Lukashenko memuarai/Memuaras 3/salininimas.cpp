#include <iostream>
#include <fstream>
using namespace std;
const char FV[] = "duom.txt";
const char FD[] = "rez.txt";
const int Cmax = 20;
void skaitymas(const char FV[], int S[], int &n)
{
	ifstream fin(FV);
	fin >> n;
	for(int i = 0; i < n; i++)
		fin >> S[i];
	fin.close();
}
void salinimas(int &n, int S[])
{
	for(int i = 0; i < n; i++)
	{
		for(int y = i+1; y < n; y++)
		{
			if(S[i] == S[y])
			{
				for(int j = y; j < n-1; j++)
					S[j] = S[j+1];
				n--;
			}		
		}
	}	
}
void rasymas(const char FD[], int S[], int n)
{
	ofstream fout(FD);
	for(int i = 0; i < n; i++)
		fout << S[i] << " ";
	fout.close();
}
int main(int argc, char** argv) {
	int n, S[Cmax];
	skaitymas(FV, S, n);
	salinimas(n, S);
	rasymas(FD, S, n);
	cout << endl;
	return 0;
}
