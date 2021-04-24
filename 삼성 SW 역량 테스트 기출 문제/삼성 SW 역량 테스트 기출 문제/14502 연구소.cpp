#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

//좌표
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


	int afterspread[10][10]; //바이러스 퍼진거
	queue <Loc> Q; //바이러스 넣을 것임

	//복사해두고
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			afterspread[i][j] = tmp[i][j]; //tmp에 벽을 세웠다고!!!!

		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (afterspread[i][j] == 2) Q.push(Loc(i, j)); //바이러스 큐에 넣기(BFS를 위해)
		}
	}


	while (!Q.empty()) {
		Loc tmp = Q.front();
		Q.pop();

		//cout << "바이러스 좌표 :" << tmp.r << "," << tmp.c << "\n";

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


	//안전영역
	int maxval = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (afterspread[i][j] == 0) maxval++;
		}
	}

	//cout << "maxval : " << maxval << "\n";

	res = max(res, maxval);

}


//벽 세우기
void dfs(int l) {
	if (l == 3) {
		bfs();
		return;
	}
	
	//벽 세우기
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


	// 벽 세우기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			//0 발견시 연구소 상태를 복사하고 벽으로 만들고, DFS로 2개 더..
			if (map[i][j] == 0) {
				//맵을 카피해놓고
				for (int k = 0; k < n; k++) {
					for (int l = 0; l < m; l++) {
						tmp[k][l] = map[k][l];
					}
				}

				//벽으로 만들고
				tmp[i][j] = 1;
				dfs(1); //나머지 2개 고르기..
				tmp[i][j] = 0;
			}

		}
	}
	

	cout << res;
	return 0;
	


}
