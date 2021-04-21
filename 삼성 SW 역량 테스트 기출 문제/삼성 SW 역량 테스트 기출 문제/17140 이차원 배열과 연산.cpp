#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int r, c, k;
int time = 0;
vector< vector<int>> A(100, vector<int>(100)); //÷���� 100���� �ΰ�
int x = 3; //�� ����
int y = 3;// �� ����

struct map {
	int val; //��
	int cnt; //��� �ִ���

	//������
	map(int a, int b) {
		val = a;
		cnt = b;
	}

	//�� ������
	bool operator< (const map &b) const {
		if (cnt != b.cnt) return cnt < b.cnt; //cnt �������� ��������
		else return val < b.val; // val�������� ��������
	}
};

int main() {
	ios_base::sync_with_stdio(false);

	cin >> r >> c >> k;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> A[i][j];
		}
	}

	while (true) {
		if (A[r-1][c-1] == k) break;

		if (time > 100) {
			time = -1;
			break;
		}

		//100���� �Ѿ�� ���� ����?

		int newx = 0;
		int newy = 0;


		if (x >= y) { //R����
			for (int i = 0; i < x; i++) { //��� �࿡ ���ؼ� ����

			
				vector <int> numcnt(101, 0); 	//���� ���� ����
				for (int j = 0; j < y; j++) { // �� �࿡�� ������
					int val = A[i][j];

					if (val != 0) {
						numcnt[val]++;
						A[i][j] = 0;
					}
				}

				vector<map> MAP; //���� �� �� map ����ü�� �ֱ�
				for (int j = 0; j <= 100; j++) {
					if (numcnt[j] != 0) {
						MAP.push_back(map(j, numcnt[j])); //(val, cnt)
					}
				}
				sort(MAP.begin(), MAP.end()); // map ����ü ����

				int idx = 0; // A�迭�� �־��ֱ�
				for (int j = 0; j < MAP.size(); j++) {
					A[i][idx] = MAP[j].val;
					A[i][idx+1] = MAP[j].cnt;
					idx = idx + 2;
				}
				newy = max(newy, idx); //�ִ� ũ���� ��
			}
			
		}
		else if (x < y) { //C����
			for (int j = 0; j < y; j++) { //��� ���� ���ؼ� ����
				vector <int> numcnt(101, 0); //���� ���� ����
				for (int i = 0; i < x; i++) { // �� ������ �ึ��
					int val = A[i][j];
					if (val != 0) {
						numcnt[val]++;
						A[i][j] = 0;
					}
				}

				vector<map> MAP;//���� �� �� map ����ü�� �ֱ�
				for (int i = 0; i <= 100; i++) {
					if (numcnt[i] != 0) {
						MAP.push_back(map(i, numcnt[i])); //(val, cnt)
					}
				}
				sort(MAP.begin(), MAP.end());			// map ����ü ����

				int idx = 0; 
				for (int i = 0; i < MAP.size(); i++) {// A�迭�� �־��ֱ�
					A[idx++][j] = MAP[i].val;
					A[idx++][j] = MAP[i].cnt;
				}
				newx = max(newx, idx); //�ִ� ũ�� ��
			}
	}

	x = max(x, newx);
	y = max(y, newy);
	time++;

	}
	cout << time;
	return 0;
}