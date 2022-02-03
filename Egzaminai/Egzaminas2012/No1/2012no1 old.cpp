#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
const char FV[] = "Duomenys.txt";
const char FD[] = "Rezultatas.txt";
void maxmin(int &n, int i, int k[], int &maxnum, int &maximum, int &minnum, int &minimum, int &psum, int &msum) 
// Krepšininkas, kuris daugiausiai laiko buvo aikšteleje, numeri ir laika. 
//Jeigu tokie buvo keli, tai nurodykiteviena, kurio numeris mažiausias
//Krepšininkas, kuris daugiausialaiko sedejo ant atsarginiu suolelio, numeri ir laika
//Jeigu tokie buvo keli, tai nurodykiteviena, kurio numeris mažiausias
{
	if(psum == maximum) {
		if(maxnum > k[i])
			maxnum = k[i];
	}	
	if(msum == minimum) {
		if(minnum > k[i])
			minnum = k[i];
	}
	if(maximum < psum) {
		maximum = psum;
		maxnum = k[i];
	}
	if(minimum > msum) {
		minimum = msum;
		minnum = k[i];
	}
}
void read(const char FV[], int &n, int &psum, int &msum, int laikas[], int k[], int t[], int c, int start[], int &maximum, int &minimum, int &minnum, int &maxnum)
{
	maximum = laikas[0];
	minimum = laikas[0];	
	ifstream fin(FV);
	fin >> n;
	for(int i = 0; i < n; i++)
	{
		fin >> k[i] >> t[i];
		for(int j = 0; j < t[i]; j++)
		{
			fin >> laikas[j]; 
			if(laikas[j] > 0) 
				psum += laikas[j];	// buvo aikšteleje
			else if(laikas[j] < 0)
				msum += laikas[j]; // sedejo ant atsarginiu suolelio
		}
		maxmin(n, i, k, maxnum, maximum, minnum, minimum, psum, msum);
		if(laikas[0] < 0) //startinio penketuku krepšininku numeriai
			c-=1;	
		if(laikas[0] > 0)
			start[i+c] = k[i];
		psum = 0;
		msum = 0;
	}
	fin.close();
}
void rezultatas(const char FD[], int &n, int &maximum, int &minimum, int &minnum, int &maxnum, int start[]) 
{
	ofstream fout(FD);
	bool daugiau = false;
	for(int i = 0; i < 5; i++) //startinio penketuko krepšininku numerius didejancia seka
	{
		for(int j = i+1; j < 5; j++)
		{
			if(start[i] > start[j])
				swap(start[i], start[j]);
		}
		fout << start[i] << " ";
	}	
	fout << endl;
	fout << maxnum << " " << maximum << endl;
	fout << minnum << " " << abs(minimum) << endl;
	fout.close();
}
int main(int argc, char** argv) {
	int n, msum = 0, psum = 0, c = 0; 
	int start[5], k[99], t[40], laikas[12] = {0}; //k(4 <= k <= 99), t(1 <= t <= 40), n(6 <= n <= 12).
	int minnum, maxnum, maximum, minimum;
	read(FV, n, psum, msum, laikas, k, t, c, start, maximum, minimum, minnum, maxnum);
	rezultatas(FD, n, maximum, minimum, minnum, maxnum, start);
	return 0;
}
