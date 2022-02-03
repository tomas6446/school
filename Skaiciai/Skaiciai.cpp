#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int a, b, c;
	cout << "a, b, c: " << endl;
	cin >> a >> b >> c;
	if(a+b <= c || a+c <= b || b+c <= a)
		cout << "Yra" << endl;
	else
		cout << "Ne" << endl;
		
	return 0;
}
