#include <iostream>
#include <fstream>
using namespace std;
const char FV[] = "Duomenys.txt";
const char FD[] = "Rezultatas.txt";
const int Cmax = 20;
void read(const char FV[], int slyvos[])
{
	ifstream fin(FV);
	for(int i = 0; i < Cmax; i++) slyvos[i] = 0;
	for(int i = 0; i < Cmax / 2; i++)
		fin >> slyvos[i];	
	fin.close();
}
void slyvusk(int slyvos[])
{
	int temp[Cmax];
	for(int i = 0; i < Cmax; i++)
		temp[i] = slyvos[i];	
	for(int i = 0; i < Cmax / 2; i++)
	{
		for(int j = 1; j <= 10-temp[i]; j++)
			slyvos[i+j]++;
	} 
}
void result(const char FD[], int slyvos[])
{
	ofstream fout(FD);
	for(int i = 0; i < Cmax; i++)
		cout << slyvos[i] << " ";
	fout.close();
}
int main(int argc, char** argv) {
	int slyvos[Cmax];	
	read(FV, slyvos);
	slyvusk(slyvos);
	result(FD, slyvos);
	return 0;
}
