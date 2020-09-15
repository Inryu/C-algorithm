//#10871 X보다 작은 수
#include <iostream>
using namespace std;

int main(void) {

	//입출력 속도 향상
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N,X;
	int n; //수열 A의 원소
	cin >> N>>X;

	for (int i = 0; i < N; i++) {
		cin >> n;
		if (n < X) cout << n<<" "; 

		/*
		둘째줄 입력을 한 번에 받아서 이런식으로 하면 안 될 줄 알았는데 된다..왜지
		배열에 저장해야 되는 줄 알았음
		*/
	}

}
