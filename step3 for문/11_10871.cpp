//#10871 X���� ���� ��
#include <iostream>
using namespace std;

int main(void) {

	//����� �ӵ� ���
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N,X;
	int n; //���� A�� ����
	cin >> N>>X;

	for (int i = 0; i < N; i++) {
		cin >> n;
		if (n < X) cout << n<<" "; 

		/*
		��°�� �Է��� �� ���� �޾Ƽ� �̷������� �ϸ� �� �� �� �˾Ҵµ� �ȴ�..����
		�迭�� �����ؾ� �Ǵ� �� �˾���
		*/
	}

}
