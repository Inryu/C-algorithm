#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int map[21][21], ch[21][21];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
struct State {
	int x, y, dis;
	State(int a, int b, int c) { //심바가 움직이는 상황 (좌표, 출발한 곳에서부터 거리)
		x = a;
		y = b;
		dis = c;
	}

	bool operator<(const State &b)const {
		if (dis != b.dis) return dis > b.dis; //거리가 같지 않으면 거리 기준으로 최소힙
		if (x != b.x) return x > b.x; //거리가 같으면, x좌표가 다르면 x(행)기준으로 위에꺼가 탑으로
		else return y > b.y; //거리가 같은데 x도 같으면 열이 작은 걸로 (왼쪽)
	}
};

struct Lion {
	int x, y, s, ate; //심바의 상태 (출발점의 위치, 몸집 크기, 먹은 회수)

	void sizeUp() {
		ate = 0;
		s++;
	}
};

int main() {
	int n, i, j, res = 0;
	priority_queue<State> Q;
	Lion simba;


	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) { //심바 위치
				simba.x = i;
				simba.y = j;
				map[i][j] = 0;
			}
		}
	}
	Q.push(State(simba.x, simba.y, 0)); //심바의 위치, 거리
	simba.s = 2;
	simba.ate = 0;

	while (!Q.empty()) {
		State tmp = Q.top();
		Q.pop();

		int x = tmp.x;
		int y = tmp.y;
		int z = tmp.dis;

		//잡아 먹을 수 있는지
		if (map[x][y] != 0 && map[x][y] < simba.s) {
			simba.x = x;
			simba.y = y;
			simba.ate++;
			if (simba.ate >= simba.s) simba.sizeUp();
			map[x][y] = 0;

			for (i = 1; i <= n; i++) {
				for (j = 1; j <= n; j++) {
					ch[i][j] = 0; //체크 배열 초기화 //심바의 새로운 위치에서 다시 퍼져야 하니깐
				}
			}

			//다시 출발해야하니깐
			while (!Q.empty()) Q.pop(); //큐도 다 비워줌다.

			//현재까지 움직인 거리..
			res = tmp.dis;
		}

		//심바의 위치에서 퍼져 나가기
		for (i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			//좌표가 경계를 벗어나고, simba 사이즈보다 크고... 방문을 했음
			if (xx<1 || xx>n || yy<1 || yy>n || map[xx][yy] > simba.s || ch[xx][yy] > 0) continue;

			//아니라면
			Q.push(State(xx, yy, z + 1)); //출발점에서 dis++
			ch[xx][yy] = 1;
			//방문
		}
	}
	printf("%d\n", res);
	return 0;
}