#include <iostream>
#include <fstream>
using namespace std;
const char FV[] = "Duomenys.txt";
struct preke
{
	string pav;
	int kiekis;	
	double kaina, suma;
};
int main(int argc, char** argv) {
	preke A, B;
	ifstream fin(FV);
	char eil[30];
	
	fin.get(eil, 30);
	A.pav = eil;
	fin >> A.kaina >> A.kiekis;
	fin.ignore();
	A.suma = A.kiekis*A.kaina;
	cout << A.pav << " " << A.kaina << " " << A.kiekis << " " << A.suma << endl;
	
	fin.get(eil, 30);
	B.pav = eil;
	fin >> B.kaina >> B.kiekis;
	fin.ignore();
	B.suma = B.kiekis*B.kaina;
	cout << B.pav  << " " << B.kaina << " " << B.kiekis << " " << B.suma << endl;
	
	return 0;
}
