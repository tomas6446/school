#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int h, m, s;
	cout << "val: ";
	cin >> h ;
	cout << "min: ";
	cin >> m;
	cout << "sek: ";
	cin >> s;
	s += (h*3600)+(m*60)-1;
	m = s/60;
	s = s%60;
	h = m/60;
	m = m%60;
	cout << h << " : " << m << " : " << s; 
	return 0;
}
