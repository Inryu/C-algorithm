//#10996 별 찍기 -21
#include <iostream>
using namespace std;

int main(void) {

	//입출력 속도 향상 
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, i, j;

	cin >> n;


	for (i = 0; i < 2*n; i++) {


		//0,2,4..번째 행(짝수)
		if (i % 2 == 0) {
			//열
			for (j = 0; j < n; j++) {
				//짝수 행 별 출력
				if (j % 2 == 0) cout << "*";
				//홀수 행 공백 출력
				else cout << " ";
			}
			cout << "\n";

		
		}

		//1,3,5..번재 행(홀수)
		else {

			for (j = 0; j < n; j++) {
				//짝수 행 공백 출력
				if (j % 2 == 0) cout << " ";
				//홀수 행 별 출력
				else cout << "*";
			}
			cout << "\n";

		
		}

	}



}