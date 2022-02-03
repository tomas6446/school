#include <iostream>
#include <fstream>
using namespace std;
const char FV[] = "U2.txt";
const char FD[] = "U2rez.txt";

struct Komandos
{
	int k;
	int kom[30];
	bool tikslas;
	int pz;
};

int main()
{
	Komandos k[10];
	int x0, y0, x1, y1;
	ifstream fin(FV);
	fin >> x0 >> y0;
	fin >> x1 >> y1;
	fin >> n;
	for(int i = 0; i < n; i++)
	{
		fin >> k[i].k;
		for(int j = 0; j < k[i].k; j++)
		{
			fin >> k[i].kom[j];
			
			if(x0 != x1 || y0 != y1)
			{
				k[i].pz++;
				switch(k[i].kom[j])
				{
					case 1: 
						y0 += 1;
						break;
					case 2: 
						x0 += 1;
						break;
					case 3: 
						y0 -= 1;
						break;
					case 4: 
						x0 -= 1;
						break;	
				};
			}
		}
	}
	fin.close();
    return 0;
}
