//#2523 �� ��� -13
#include <iostream>
using namespace std;

int main(void) {

	//����� �ӵ� ��� 
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n,i,j;

	cin >> n;

	// �� ����
	for (i = 0; i < n; i++) {
		for (j = 0; j < (i+1); j++) {
			cout << "*"; //�� ���
		}
		cout << "\n";
	}

	//�Ʒ� ����
	for (i = n-1; i>0 ; i--) {

		for (j = i; j > 0;j--) {
			cout << "*"; // �� ���
		}
		cout << "\n";
	}



}