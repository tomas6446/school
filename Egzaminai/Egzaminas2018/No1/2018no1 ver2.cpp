#include <iostream>
#include <fstream>
using namespace std;

void kiekveliavu(int &kiekveliav, int &Z, int &R, int &G)
{
    int minim = Z;
	if(G < minim)
		minim = G;
	else if(R < minim)
		minim = R;
    if(minim%2 > 0)
        minim -= 1;
    kiekveliav = minim/2;
    Z -= minim;
	R -= minim;
	G -= minim;
}

int main(int argc, char** argv) {

	int n, Z = 0, R = 0, G = 0, kiekveliav;

	ifstream fin("U1.txt");
	fin >> n;
	for(int i = 0; i < n; i++)
	{
		char spalva;
		int kiek;
		fin >> spalva >> kiek;
		if(spalva == 'G')
			G += kiek;
		else if(spalva == 'Z')
			Z += kiek;
		else if(spalva == 'R')
			R += kiek;
	}
	fin.close();

    kiekveliavu(kiekveliav, Z, R, G);

	ofstream fout("U1rez.txt");
	fout << kiekveliav << endl;
	fout << "G = " << G << endl << "Z = " << Z << endl << "R = " << R << endl;
	fout.close();

	return 0;
}
