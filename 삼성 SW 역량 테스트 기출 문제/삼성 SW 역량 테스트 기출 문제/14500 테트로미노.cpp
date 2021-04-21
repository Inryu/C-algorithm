#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int map[500][500];
int ch[500][500]; // 0: false , 1 : true
int ans=-2147000000;//최대값 구해야 함.

int dx[4] = { 0,1,0,-1 }; //상우하좌
int dy[4] = { -1,0,1,0 };
int n, m;

//1. map을 한 칸 씩 순회하면서 최대값 찾기
//2. 이때 4개 모양은 DFS로 가능, ㅗ 모양은 따로


// ㅗ 모양 제외 4가지 모양 검사
void DFS(int L, int x, int y, int sum) {
	if (L == 3) {
		ans = max(ans, sum); //max 값 업데이트
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

//ㅗ 모양 검사
void check_exshape(int x, int y) { //행 (n) 열 (y) 주의

	//ㅗ
	if (x-1>=0&&y-1>=0&&y+1<=m-1) {
		ans = max(ans, map[x][y] +map[x-1][y]+map[x][y-1]+map[x][y+1]);
	}

	//ㅏ
	if (x-1>=0&&x+1<=n-1&&y+1<=m-1) {
		ans = max(ans, map[x][y]+map[x-1][y]+map[x+1][y]+map[x][y+1]);
	}

	//ㅜ
	if (y-1>=0&&y+1<=m-1&&x+1<=n-1){
		ans = max(ans, map[x][y] + map[x][y-1] + map[x][y+1] + map[x+1][y]);
	}

	//ㅓ
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
	//map을 순회하면서 검사
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//1) DFS로 4가지 모양 검사
			ch[i][j] = 1; //방문체크
			DFS(0, i, j, map[i][j]); //레벨 0부터 시작
			ch[i][j] = 0;

			//2) ㅗ 모양 검사
			check_exshape(i, j);
		}
	}

	cout << ans;

	return 0;

}