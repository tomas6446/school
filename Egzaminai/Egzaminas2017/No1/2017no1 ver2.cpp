#include <iostream>
#include <fstream>
using namespace std;
const char FIN[] = "Duomenys.txt";
const char FOUT[] = "Rezultatas.txt";
struct RGB {
	int num[5];
}rgb[200];
void read(const char FIN[], int &a, int &b)
{
	ifstream fin(FIN);
	fin >> a >> b;
	for(int i = 0; i < a*b; i++)
	{
		for(int y = 0; y < 3; y++)
			fin >> rgb[i].num[y];
	}
	fin.close();
}
void converter(int a, int b)
{
	for(int i = 0; i < a*b; i++)
	{
		for(int y = 0; y < 3; y++)
		{
			if(rgb[i].num[y] == 0)
				cout << "00";
			else
				cout << hex << rgb[i].num[y];
		}
		cout << ";";
	}
}
int main(int argc, char** argv) {
	int a, b;
	read(FIN, a, b);
	converter(a, b);
	return 0;
}
