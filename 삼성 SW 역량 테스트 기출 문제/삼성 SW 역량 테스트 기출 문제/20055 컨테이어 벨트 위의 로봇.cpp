#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, k;

struct belt {
	int a; //������
	bool isBox;
};

vector <belt> Container(400);


void rotate() {

	//1�� ���� ��
	int lasta = Container[2 * n].a;
	bool lastBox = Container[2 * n].isBox;

	Container[n].isBox = false; //������ �Ŵϱ�
	 
	//ȸ�� ( 1 ~ 2n-1 �Ųٷ�)
	for (int i = (2*n)-1; i >= 1; i--) {
		int a = Container[i].a;
		int isBox = Container[i].isBox;

		Container[i + 1].a = a;
		Container[i + 1].isBox = isBox;
	}

	//2n->1��
	Container[1].a = lasta;
	Container[1].isBox = lastBox;
}

int main() {
	cin >> n >> k;


	//�Է�
	for (int i = 1; i <= 2*n; i++) {
		int aa;
		cin >> aa;

		Container[i].a = aa;
		Container[i].isBox = false;
	}


	int stage = 1;
	while (true) {

		//1) ��Ʈ ȸ��
		rotate();

		//2) ȸ�� �� �κ��� �̵�
		// ���� ���� ��Ʈ�� �ö� �κ����� = n
		for (int i = n; i >= 1; i--) {

			//�������� ��ġ�� �ڽ��� ������ �ݵ�� ������
			if (i == n && Container[i].isBox) {
				Container[i].isBox = false; 
				//������ ������ ������ �������� �Ŵ� ����.

				continue;
			}

			//�κ��� �� ĭ�� �־�� �Ѵ�!!
			if (Container[i].isBox&&!Container[i + 1].isBox&&Container[i + 1].a >= 1) {
				Container[i].isBox = false;
				Container[i + 1].isBox = true;
				Container[i + 1].a--;
			}
		}

		//3) �ö󰡴� ��ġ�� �κ��� ���ٸ� �κ��� �ϳ� �ø���.
		if (!Container[1].isBox&&Container[1].a >= 1) {
			Container[1].isBox = true;
			Container[1].a--;
		}

		//4) �������� 0�� ĭ�� ����
		int cnt = 0;
		for (int i = 1; i <= 2 * n; i++) {
			if (Container[i].a == 0) cnt++;
		}

		if (cnt >= k) break;
		stage++;

	}

	cout << stage<<"\n";
	return 0;
}

