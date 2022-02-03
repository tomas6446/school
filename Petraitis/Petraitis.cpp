#include <iostream>
#include <fstream>
using namespace std;
const char FV[] = "duom.txt";
const char FD[] = "rez.txt";
struct Mokinys {
	string pav, var;
	int ugis;
	double vid;
};

int main(int argc, char** argv) {
	Mokinys A, B;
	ifstream fin(FV);
	ofstream fout(FD);
	
	fin >> A.pav >> A.var >> A.ugis >> A.vid;
	fin >> B.pav >> B.var >> B.ugis >> B.vid;
	cout << A.pav << " " << A.var << " " << A.ugis << " " << A.vid << endl; 
	cout << B.pav << " " << B.var << " " << B.ugis << " " << B.vid << endl; 
	fin.close();
	fout.close();
	return 0;
}
