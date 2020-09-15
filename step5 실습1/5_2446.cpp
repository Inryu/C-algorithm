//#2446 별 찍기 -9
#include <iostream>
using namespace std;

int main(void) {

	//입출력 속도 향상 
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, i, j;

	cin >> n;

	// 위 절반
	for (i = n; i > 0; i--) {
		for (j = 0; j < n - i; j++) {
			cout << " "; // 공백 출력
		}
		for (j = 0; j < 2 * i - 1; j++) {
			cout << "*"; //별 출력
		}
		cout << "\n";

	}

	//아래 절반
	for (i = 1; i < n; i++) {
		for (j = n - (i + 1); j > 0; j--) {
			cout << " "; //공백 출력
		}

		for (j = 0; j < 2 * (i + 1) - 1; j++) {
			cout << "*"; // 별 출력
		}
		cout << "\n";

	}



}