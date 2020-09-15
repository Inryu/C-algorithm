//#10039 평균 점수
#include <iostream>
using namespace std;

int main(void) {

	//입출력 속도 향상 
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int arr[5];
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		if (arr[i] < 40)
			arr[i] = 40;
		sum += arr[i];
	}

	cout <<sum/5;


}