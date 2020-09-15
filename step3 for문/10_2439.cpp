//#2439 별 찍기 - 2
#include <iostream>
using namespace std;

int main(void) {

	//입출력 속도 향상
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - (i + 1); j++) {
			cout << " ";
		}
		for (int j = 0; j < i + 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}

}
