#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

//��ǥ
struct Loc {
	int r;
	int c;

	Loc(int a, int b) {
		r = a;
		c = b;
	}
};
int n, m;
int map[10][10];
int tmp[10][10]; 

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int res = -1;


void bfs() {


	int afterspread[10][10]; //���̷��� ������
	queue <Loc> Q; //���̷��� ���� ����

	//�����صΰ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			afterspread[i][j] = tmp[i][j]; //tmp�� ���� �����ٰ�!!!!

		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (afterspread[i][j] == 2) Q.push(Loc(i, j)); //���̷��� ť�� �ֱ�(BFS�� ����)
		}
	}


	while (!Q.empty()) {
		Loc tmp = Q.front();
		Q.pop();

		//cout << "���̷��� ��ǥ :" << tmp.r << "," << tmp.c << "\n";

		for (int i = 0; i < 4; i++) {
			int nr = tmp.r + dr[i];
			int nc = tmp.c + dc[i];

			if (0 <= nr && nr < n && 0 <= nc && nc < m) {
				if (afterspread[nr][nc] == 0) {
					afterspread[nr][nc] = 2;
					Q.push(Loc(nr, nc));
				}
			}
		}
	}


	//��������
	int maxval = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (afterspread[i][j] == 0) maxval++;
		}
	}

	//cout << "maxval : " << maxval << "\n";

	res = max(res, maxval);

}


//�� �����
void dfs(int l) {
	if (l == 3) {
		bfs();
		return;
	}
	
	//�� �����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 0) {
				tmp[i][j] = 1;
				dfs(l + 1);
				tmp[i][j] = 0;
			}
		}
	}
}



int main() {

	cin >> n >> m;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a; cin >> a;
			map[i][j] = a;
		}
	}


	// �� �����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			//0 �߽߰� ������ ���¸� �����ϰ� ������ �����, DFS�� 2�� ��..
			if (map[i][j] == 0) {
				//���� ī���س���
				for (int k = 0; k < n; k++) {
					for (int l = 0; l < m; l++) {
						tmp[k][l] = map[k][l];
					}
				}

				//������ �����
				tmp[i][j] = 1;
				dfs(1); //������ 2�� ����..
				tmp[i][j] = 0;
			}

		}
	}
	

	cout << res;
	return 0;
	


}
