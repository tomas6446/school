#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int M, num = 1;
	cout << "M: ";
	cin >> M;
	if (M >= 1896 && M % 4 == 0)
	{
		num += (M-1896)/4;
		cout << "Olimpiniu zaidimu numeris = " << num << endl; 
	}
	else
		cout << "Metai ne olimpiniai" << endl;
	return 0;
}
