// #10430 °ö¼À
#include <iostream>
using namespace std;
int main(void) {
	int a,b;
	cin >> a >> b;
	
	cout << a * (b % 10) << endl; //3
	cout << a * (b % 100 / 10) << endl; //4
	cout << a * (b/100) << endl; //5
	cout << a * b << endl; //6
}