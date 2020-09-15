//#1330 두 수 비교하기
#include <iostream>
using namespace std;

int main(void) {
	int a, b;
	cin >> a >> b;

	if (a > b) cout << ">" << endl;
	else if (a < b) cout << "<" << endl;
	else cout << "==" << endl;
}