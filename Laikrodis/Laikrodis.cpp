#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int h, m, s;
	cout << "h: ";
	cin >> h;
	cout << "m: ";
	cin >> m;
	m += h*60;
	s = m*60;
	cout << "m = " << m << endl;
	cout << "s = " << s << endl;
	return 0;
}
