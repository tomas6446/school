#include <iostream>
#include <fstream>
const char FV[] = "duom.txt";
const char FD[] = "Rezultatas.txt";
const int Cmax = 30;
using namespace std;

int main(int argc, char** argv) {
	ifstream fin(FV);
	int n, sk[Cmax], k = 0, minim[Cmax], sum[Cmax], didz[Cmax];
	string miest[Cmax], apskr[Cmax], top[Cmax];
	fin >> n;
	for(int i = 0; i < n; i++)
		fin >> miest[i] >> apskr[i] >> sk[i];
	for(int i = 0; i < n; i++)
		cout << miest[i] << " " << apskr[i] << " " << sk[i] << endl;
	for(int i = 0; i < n; i++)
	{
		minim[i] = sk[i];
		didz[i] = sk[i];
		bool yra = false;
		for(int y = 0; y < n; y++)
		{
			if(apskr[i] == top[y])
			{
				sum[y] += sk[i];
				if(minim[y] > sk[i])
					minim[y] = sk[i];
				break;
			}
		}
		if(!yra)
		{
			top[i] = apskr[i];
			sum[i] = sk[i];
		}
	}
	for(int i = 0; i < n-1; i++)
		{
			for(int j = i+1; j < n; j++)
			{
				if(minim[i] > minim[j])
				{
					swap(sk[i], sk[j]);
					swap(apskr[i], apskr[j]);
					swap(minim[i], minim[j]);
				}
				else if(minim[i] == minim[j] && apskr[i] > apskr[j])
				{
					swap(sk[i], sk[j]);
					swap(apskr[i], apskr[j]);
					swap(minim[i], minim[j]);
				}
			}
		}
	cout << k << endl;
	for(int i = 0; i < n; i++)
		cout << top[i] << " " << minim[i] << " " << sum[i] << endl;
	fin.close();
	return 0;
}
