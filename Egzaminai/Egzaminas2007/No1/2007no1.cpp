#include <iostream>
#include <fstream>
using namespace std;
const char FV[] = "Duomenys.txt";
const char FD[] = "Rezultatas.txt";
void sort(int &n, int d[], int b[], int r[], int l[]) // sort
{
	for (int i = 0; i < n; i++)   
	{
		for (int j = 0; j < n-1; j++) 
		{
			if (d[j] > d[j+1])  
	        {
	        	swap(d[j], d[j+1]);
	        	swap(b[j], b[j+1]);
	        	swap(r[j], r[j+1]);
	        	swap(l[j], l[j+1]);
			}
		}        
	}     
}
int maximum(int n, int d[], int b[], int r[], int l[])
{
	int sumgryb[31] = {0};
	int max = sumgryb[0];
	int maxindex = d[0];
	for(int i = 0; i < n; i++)
		sumgryb[i] += b[i]+r[i]+l[i];	
	for(int i = 0; i < n; i++)
	{
		if(sumgryb[i] > max)
		{
			max = sumgryb[i];
			maxindex = d[i];
		}		
	}
	return maxindex;
}
int sumup(int &n, int d[], int b[], int r[], int l[]) // kiek grybu
{
	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n;)
		{
			if(d[i] == d[j])
			{
				b[i] += b[j];
				r[i] += r[j];
				l[i] += l[j];
				for (int k = j; k < n; k++)
                {
                    d[k] = d[k+1];
                    b[k] = b[k+1];
                    r[k] = r[k+1];
                    l[k] = l[k+1];
                }
                n--;
			}
			else
                j++;
		}
	}
}
int main(int argc, char** argv) {
	ifstream fin(FV);
	ofstream fout(FD);
	int n, d[31], b[31], r[31], l[31], max; 
	//skaityti
	fin >> n;
	for(int i = 0; i < n; i++)
		fin >> d[i] >> b[i] >> r[i] >> l[i];
	//funkcijos
	sumup(n, d, b, r, l);	
	sort(n, d, b, r, l);
	max = maximum(n, d, b, r, l);
	//------------
	int sum;
	for(int i = 0; i < n; i++)
		if(d[i] == max) sum = b[i] + r[i] + l[i];	
	//------------
	//result
	for(int i = 0; i < n; i++)
		fout << d[i] << " " << b[i] << " " << r[i] << " "<< l[i] << endl;
	fout << max << " " << sum << endl;
	//----------------
	fin.close();
	fout.close();
	return 0;
}
