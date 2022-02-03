#include <iostream>
#include <fstream>
const char FV[] = "U1.txt";
const char FD[] = "U1rez.txt";
using namespace std;

int main(int argc, char** argv) {

	int n, Z = 0, R = 0, G = 0, kiekveliav = 0;

	ifstream fin(FV);
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

	int minim = Z;
	if(G < minim)
		minim = G;
	else if(Z < minim)
		minim = Z;
	else if(R < minim)
		minim = R;
	kiekveliav = min/2;
	Z -= minim;
	R -= minim;
	G -= minim;

	ofstream fout(FD);
	cout << kiekveliav << endl;
	cout << "G = "<< G << endl << "Z = " << Z << endl << "R = " << R << endl;
	fout.close();

	return 0;
}
