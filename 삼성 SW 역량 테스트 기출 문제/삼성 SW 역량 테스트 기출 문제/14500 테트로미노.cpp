#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int map[500][500];
int ch[500][500]; // 0: false , 1 : true
int ans=-2147000000;//�ִ밪 ���ؾ� ��.

int dx[4] = { 0,1,0,-1 }; //�������
int dy[4] = { -1,0,1,0 };
int n, m;

//1. map�� �� ĭ �� ��ȸ�ϸ鼭 �ִ밪 ã��
//2. �̶� 4�� ����� DFS�� ����, �� ����� ����


// �� ��� ���� 4���� ��� �˻�
void DFS(int L, int x, int y, int sum) {
	if (L == 3) {
		ans = max(ans, sum); //max �� ������Ʈ
	}
	else {
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];


			if (xx >= 0 && xx < n&&yy >= 0 & yy < m&&ch[xx][yy]==0) {
				ch[xx][yy] = 1;
				DFS(L + 1, xx, yy, sum + map[xx][yy]); 
				ch[xx][yy] = 0;
			}
		}
	}

}

//�� ��� �˻�
void check_exshape(int x, int y) { //�� (n) �� (y) ����

	//��
	if (x-1>=0&&y-1>=0&&y+1<=m-1) {
		ans = max(ans, map[x][y] +map[x-1][y]+map[x][y-1]+map[x][y+1]);
	}

	//��
	if (x-1>=0&&x+1<=n-1&&y+1<=m-1) {
		ans = max(ans, map[x][y]+map[x-1][y]+map[x+1][y]+map[x][y+1]);
	}

	//��
	if (y-1>=0&&y+1<=m-1&&x+1<=n-1){
		ans = max(ans, map[x][y] + map[x][y-1] + map[x][y+1] + map[x+1][y]);
	}

	//��
	if (y-1>=0&&x-1>=0&&x+1<=n-1) {
		ans = max(ans, map[x][y] + map[x - 1][y] + map[x+1][y]+ map[x][y -1]);
	}

}


int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	//map�� ��ȸ�ϸ鼭 �˻�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//1) DFS�� 4���� ��� �˻�
			ch[i][j] = 1; //�湮üũ
			DFS(0, i, j, map[i][j]); //���� 0���� ����
			ch[i][j] = 0;

			//2) �� ��� �˻�
			check_exshape(i, j);
		}
	}

	cout << ans;

	return 0;

}