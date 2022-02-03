#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int sk1, sk2, sk3, sk4, sk5, sk6, x;
	cout << "x = ";
	cin >> x;
	sk6 = x%10;
	sk5 = x/10%10;
	sk4 = x/10/10%10;
	sk3 = x/10/10/10%10;
	sk2 = x/10/10/10/10%10;
	sk1 = x/10/10/10/10/10%10;
	if(sk1 == sk6 && sk2 == sk5 && sk3 == sk4)
		cout << "Bilietas yra laimingas" << endl;
	else
		cout << "Nelaimingas" << endl;
	
	
	return 0;
	
}
