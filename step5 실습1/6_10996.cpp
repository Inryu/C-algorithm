//#10996 �� ��� -21
#include <iostream>
using namespace std;

int main(void) {

	//����� �ӵ� ��� 
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, i, j;

	cin >> n;


	for (i = 0; i < 2*n; i++) {


		//0,2,4..��° ��(¦��)
		if (i % 2 == 0) {
			//��
			for (j = 0; j < n; j++) {
				//¦�� �� �� ���
				if (j % 2 == 0) cout << "*";
				//Ȧ�� �� ���� ���
				else cout << " ";
			}
			cout << "\n";

		
		}

		//1,3,5..���� ��(Ȧ��)
		else {

			for (j = 0; j < n; j++) {
				//¦�� �� ���� ���
				if (j % 2 == 0) cout << " ";
				//Ȧ�� �� �� ���
				else cout << "*";
			}
			cout << "\n";

		
		}

	}



}