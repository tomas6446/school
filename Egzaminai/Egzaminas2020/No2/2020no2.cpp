#include <iostream>
#include <fstream>
using namespace std;
const char FV[] = "U2.txt";
const char FD[] = "U2rez.txt";
//__________________________
struct Zvejai {
	string zvpav;
	string zuvpav[5];
	int zuvsk;
	int zuvkg[5] = {0};
	int task = {0};
} zv[30];
//_________________________
struct Zuvys {
	string zuvpav;
	int zuvtask;
	int zuvkg = 0;
} zuv[30];
//_________________________________ sortirovka
void sort(int n, int k)
{
	for(int i = 0; i < n-1; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			if(zv[j].task > zv[i].task)
				swap(zv[i], zv[j]);
			else if(zv[j].task == zv[i].task)
			{
				if(zv[j].zvpav < zv[i].zvpav)
					swap(zv[i], zv[j]);
			}
		}
	}
	for(int i = 0; i < k-1; i++)
	{
		for(int j = i+1; j < k; j++)
		{
			if(zuv[j].zuvkg > zuv[i].zuvkg)
				swap(zuv[i], zuv[j]);
			else if(zv[j].task == zv[i].task)
			{
				if(zuv[j].zuvpav < zuv[i].zuvpav)
					swap(zuv[i], zuv[j]);
			}
		}
	}
}
//_______________________________
int main(int argc, char** argv) {
	//________________________________________ vvod
	int n, k;
	char zuvys[21], zvejis[21];
	ifstream fin(FV);
	fin >> n;
	fin.ignore();
	for(int i = 0; i < n; i++)
	{
		fin.get(zvejis, sizeof zvejis);
		zv[i].zvpav = zvejis;
		fin >> zv[i].zuvsk;
		fin.ignore();
		for(int j = 0; j < zv[i].zuvsk; j++)
		{
			fin.get(zuvys, sizeof zuvys);
			zv[i].zuvpav[j] = zuvys;
			fin >> zv[i].zuvkg[j];
			fin.ignore();
		}
	}
	fin >> k;
	fin.ignore();
	for(int i = 0; i < k; i++)
	{
		fin.get(zuvys, sizeof zuvys);
		zuv[i].zuvpav = zuvys;
		fin >> zuv[i].zuvtask;
		fin.ignore();
	}
	fin.close();
	//__________________________________ skolko tochek
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < zv[i].zuvsk; j++)
		{
			if(zv[i].zuvkg[j] < 200) {
				zv[i].task += 10;
			}
			else if(zv[i].zuvkg[j] >= 200) {
				zv[i].task += 30;
			}
		}
	}
	//__________________________________ // skolko kg
	for(int i = 0; i < k; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int x = 0; x < zv[j].zuvsk; x++)
			{
				if(zuv[i].zuvpav == zv[j].zuvpav[x])
				{
					zuv[i].zuvkg += zv[j].zuvkg[x];
					zv[j].task += zuv[i].zuvtask;
				}
			}
		}
	}
	//_______________________________________ //vyvod
	sort(n, k);
	ofstream fout(FD);
	fout << "Dalyviai" << endl;
	for(int i = 0; i < n; i++)
		fout << zv[i].zvpav << zv[i].task << endl;
	fout << "Laimikis" << endl;
	for(int i = 0; i < k; i++)
		fout << zuv[i].zuvpav << zuv[i].zuvkg << endl;
	fout.close();
	//________________________________________
	return 0;
}
