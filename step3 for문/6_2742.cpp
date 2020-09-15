//#2742 찍기N
#include <iostream>
using namespace std;

int main(void) {

	//입출력 속도 향상
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = n; i >= 1; i--) {
		cout << i << "\n"; //endl대신 \n 사용
	}

}
