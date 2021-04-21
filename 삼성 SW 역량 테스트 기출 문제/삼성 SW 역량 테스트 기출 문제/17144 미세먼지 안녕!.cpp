#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//�������
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };

//����ü
struct Loc {
	int r; //��
	int c; //��

	//������
	Loc(int a, int b) {
		r = a;
		c = b;
	}
};


int R, C, T;
int map[51][51];
vector<int> clean; //���� û������ �ุ ����! �׻� 1���̹Ƿ�
queue<Loc> Q;

int main() {

	cin >> R >> C >> T;

	//�Է� �ޱ�
	int num;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> num;
			map[i][j] = num;

			//���� û����
			if (num == -1) {
				clean.push_back(i);
			}
			
		}
	}

	int time = 0;


	while (time < T) {

		//1) ���� �̼������� �ִ� ���� ť�� �ֱ�
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {

				if (map[i][j] > 0) {
					Q.push(Loc(i, j));
				}
			}
		}

		//2) �̼����� Ȯ��
		int tmp[51][51] = { 0, }; //���ÿ� Ȯ���ϹǷ� ������ ������ �迭

		//ť���� ���鼭
		while (!Q.empty()) {
			Loc loc = Q.front(); //�̼����� ��ǥ
			Q.pop();

			// Ȯ��Ǵ� ��
			int spreadval = map[loc.r][loc.c] / 5;

			// ������ �� �������� Ȯ��
			for (int i = 0; i < 4; i++) {
				int nr = loc.r + dr[i];
				int nc = loc.c + dc[i];

				if (nr<1 || nr>R || nc<1 || nc>C || map[nr][nc] == -1) continue;
				
				tmp[nr][nc] += spreadval;
				tmp[loc.r][loc.c] -= spreadval;
			}

		}

		// Ȯ���� ���� �迭(map)�� �����ֱ�
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				map[i][j] += tmp[i][j];
			}
		}
	
		//3) ����û���� �۵�
		int afterclean[51][51] = { 0, };

		int top = clean[0]; //���� ����û���� ��
		int bottom = clean[1]; //�Ʒ��� ����û���� ��


		// 1.
		for (int i = 2; i <= C - 1; i++) {
			afterclean[top][i + 1] = map[top][i];
		}
		//2.
		for (int i = top; i >= 2; i--) {
			afterclean[i-1][C] = map[i][C];
		}
		//3.
		for (int i = C; i >= 2; i--) {
			afterclean[1][i-1] = map[1][i];
		}

		//4. 
		for (int i = 1; i <= top - 2; i++) {
			afterclean[i + 1][1] = map[i][1];
		}

		//5.
		for (int i = 2; i <= C - 1; i++) {
			afterclean[bottom][i + 1] = map[bottom][i];
		}

		//6.
		for (int i = bottom; i <= R-1; i++) {
			afterclean[i + 1][C] = map[i][C];
		}

		//7.
		for (int i = C; i >= 2; i--) {
			afterclean[R][i - 1] = map[R][i];
		}

		//8. 
		for (int i = R; i >= bottom+2; i--) {
			afterclean[i-1][1] = map[i][1];
		}

		//map�� ���� (��ȯ�� �׵θ��� �����ؾ���..!)
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (i == 1 || i == top || i == bottom || i == R || j == 1 || j == C) {
					map[i][j] = afterclean[i][j];
				}
			}
		}

		time++;


	}

	//�����ִ� �̼����� ��
	int ans = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {

			if (map[i][j] > 0) ans += map[i][j];
		}
	}
	
	cout << ans;
	return 0;

}

