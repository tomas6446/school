#include <iostream>
#include <fstream>
using namespace std;
const char FV[] = "U2.txt";
const char FD[] = "U2rez.txt";
int main(int argc, char** argv) {
	ifstream fin(FV);
	ofstream fout(FD);
	int n, k, x1, y1, x, y, x0, y0, komanda, kada;
	fin >> x0 >> y0 >> x1 >> y1;
	fin >> n;
	x = x0, y = y0;
	for(int i = 0; i < n; i++)
	{
		fin >> k;
		bool pasiektas = false;
		for(int j = 0; j < k; j++)
		{
			fin >> komanda;
			if(komanda == 1)
				y += 1;		
			else if(komanda == 2)
				x += 1;	
			else if(komanda == 3)
				y -= 1;	
			else if(komanda == 4)
				x -= 1;	
			cout << komanda << " ";
			if(x == x1 && y == y1)
			{
				pasiektas = true; // nashel tochku
				kada = j+1;
				break;
			}		
		}
		if(pasiektas == true) // esli nashel tochku
			cout << kada << " pasiektas tikslas " << endl; // kada = na kakom elemente marsohod nashel tochku
		else if(pasiektas == false)
			cout << k << " sekos pabaiga " << endl;
		pasiektas = false;
		x = x0, y = y0;		
	}
	fin.close();
	fout.close();
	return 0;
}
