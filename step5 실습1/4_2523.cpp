//#2523 별 찍기 -13
#include <iostream>
using namespace std;

int main(void) {

	//입출력 속도 향상 
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n,i,j;

	cin >> n;

	// 위 절반
	for (i = 0; i < n; i++) {
		for (j = 0; j < (i+1); j++) {
			cout << "*"; //별 출력
		}
		cout << "\n";
	}

	//아래 절반
	for (i = n-1; i>0 ; i--) {

		for (j = i; j > 0;j--) {
			cout << "*"; // 별 출력
		}
		cout << "\n";
	}



}