#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int a, b;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	if(a == b && a != 0 && b != 0)
		cout << "Kvadratas" << endl;
	else if(a != b)
		cout << "Staciakampis" << endl;
	if(a == 0 && b == 0)
		cout << "Negalima sudaryti keturkampi" << endl;
	return 0;
}
