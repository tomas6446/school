#include <iostream>
#include <fstream>
using namespace std;
const char FV[] = "Duomenys.txt";
const char FD[] = "Rezultatas.txt";
const int km = 10;
const int kb = 20;
void result(const char FD[], int MB[])
{
	ofstream fout(FD);
	for(int i = 0; i < kb; i ++)
		fout << MB[i] << " ";
	fout.close();	
}
int main(int argc, char** argv) {
	int M[km], MB[kb];
	ifstream fin(FV);
	for(int i = 0; i < km; i++)
		fin >> M[i];
	fin.close();	
	for(int i = 0; i < kb; i++) 
		MB[i] = 0;
	for(int i = 0; i < km; i++)
	{
		MB[i] += M[i];
		for(int y = 1; y <= 10-M[i]; y++)
			MB[i+y]++;
	}
	result(FD, MB);
	return 0;
}
