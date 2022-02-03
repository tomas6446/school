#include <iostream>
#include <fstream>
using namespace std;
const char FV[] = "Duomenys.txt";
const char FD[] = "Rezultatas.txt";
void didzbalai(int k, int &t1, int &t2, int &t3, int pirmas, int antras, int trecias)
{
	if(pirmas > antras && pirmas > trecias)
		t1 += 4;
	else if(antras > pirmas && antras > trecias)
		t2 += 4;
	else if(trecias > pirmas && trecias > antras)
		t3 += 4;
	else if(pirmas == antras && pirmas > trecias && antras > trecias) {
		t1 += 2;
		t2 += 2;	
	}
	else if(antras == trecias && antras > pirmas && trecias > pirmas) {
		t2 += 2;
		t3 += 2;
	}
	else if(trecias == pirmas && trecias > antras && pirmas > antras) {
		t3 += 2;
		t1 += 2;
	}
}
int laimejo(int &k, int dir1, int dir2, int dir3, int t1, int t2, int t3)
{
	for(int i = 0; i < k; i++)
	{
		if(t1 > t2 && t1 > t3) return 1;
		else if(t2 > t1 && t2 > t3) return 2;
		else if(t3 > t1 && t3 > t2) return 3;
		else if(t1 == t2 && t2 == t3)
		{
			t1 += dir1;
			t2 += dir2;
			t3 += dir3;
			if(t1 > t2 && t1 > t3) return 1;
			else if(t2 > t1 && t2 > t3) return 2;
			else if(t3 > t1 && t3 > t2) return 3;
		}			
	}
}
int main(int argc, char** argv) {
	ifstream fin(FV);
	ofstream fout(FD);
	int k, dir1, dir2, dir3;
	int t1 = 0, t2 = 0, t3 = 0
	int pirm = 0, antr = 0, trec = 0;
	int pirmas, antras, trecias;
	fin >> k;
	for(int i = 0; i < k; i++)
	{
		fin >> pirmas >> antras >> trecias;
		pirm += pirmas;
		antr += antras;
		trec += trecias;
		didzbalai(k, t1, t2, t3, pirmas, antras, trecias);
	}
	fin >> dir1 >> dir2>> dir3;	
	int num = laimejo(k, dir1, dir2, dir3, t1, t2, t3);
	fout << pirm << " " << antr << " " << trec << endl;	
	fout << t1 << " " << t2 << " " << t3 << endl;	
	fout << num << endl;
	fout.close();
	fin.close();
	return 0;
}
