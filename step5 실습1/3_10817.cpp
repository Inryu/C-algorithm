//#10817 �� �� 
#include <iostream>
using namespace std;

int main(void) {

	//����� �ӵ� ��� 
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a,b,c;

	cin >>a >> b >> c;

	if (a >= b) {
		if (c >= a) cout << a;
		else {
			if (c >= b) cout << c;
			else cout << b;
		}
	}
	else {
		if (c >= b) cout << b;
		else {
			if (c >= a) cout << c;
			else cout << a;
		}
	}

}