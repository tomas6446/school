#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int n, m;
	cout << "Jonas: ";
	cin >> n;
	cout << "Petras: ";
	cin >> m;
	cout << "Rezultatas: ";
	if(n > m)
		cout << "Jonas" << endl;
	else if(m > n)
		cout << "Petras" << endl;
	else
		cout << "Surinko vienodai" << endl;
	return 0;
}
