//#11021 A+B-7
#include <iostream>
using namespace std;

int main(void) {

	//����� �ӵ� ���
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n,a,b;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		cout << "Case #" << i<<": "<<a+b<<"\n"; //endl��� \n ���
	}

}
