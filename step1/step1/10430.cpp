// #10430 ������

#include <iostream>
using namespace std;
int main(void) {
	int A, B,C;
	double n;
	cin >> A >> B>>C;

	//���
	cout << (A + B) % C << endl;
	cout << ((A%C) + (B%C)) % C << endl;
	cout << (A*B) % C << endl;
	cout << ((A%C)*(B%C)) % C << endl;
}