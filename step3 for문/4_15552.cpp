//#15552 빠른 A+B
#include <iostream>
using namespace std;

int main(void) {

	//입출력 속도 향상
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T, A, B;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		cout << A + B << "\n"; //endl대신 \n 사용
	}

}
