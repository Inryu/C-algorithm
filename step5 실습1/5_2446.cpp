//#2446 �� ��� -9
#include <iostream>
using namespace std;

int main(void) {

	//����� �ӵ� ��� 
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, i, j;

	cin >> n;

	// �� ����
	for (i = n; i > 0; i--) {
		for (j = 0; j < n - i; j++) {
			cout << " "; // ���� ���
		}
		for (j = 0; j < 2 * i - 1; j++) {
			cout << "*"; //�� ���
		}
		cout << "\n";

	}

	//�Ʒ� ����
	for (i = 1; i < n; i++) {
		for (j = n - (i + 1); j > 0; j--) {
			cout << " "; //���� ���
		}

		for (j = 0; j < 2 * (i + 1) - 1; j++) {
			cout << "*"; // �� ���
		}
		cout << "\n";

	}



}