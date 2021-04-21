#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int map[21][21], ch[21][21];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

//심바가 움직이는 상황 (좌표, 출발한 곳에서부터 거리)
struct State {
	int x, y, dis;
	State(int a, int b, int c) { 
		x = a; //심바의 좌표
		y = b; //심바의 좌표
		dis = c; //지금까지 움직인 거리
	}

	bool operator<(const State &b)const {
		if (dis != b.dis) return dis > b.dis; //거리가 같지 않으면 거리 기준으로 최소힙!!! 
		if (x != b.x) return x > b.x; //거리가 같고, x좌표가 다르면 x(행)기준으로 위에꺼(x가 가장 작은 거)가 탑으로 (최소힙)
		else return y > b.y; //거리가 같은데 x도 같으면 열(y가 가장 작은것이 탑으로 !최소힙)이 작은 걸로 (왼쪽)
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
	priority_queue<State> Q; //우선순위 큐
	Lion simba;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) { //심바 위치
				simba.x = i;
				simba.y = j;
				map[i][j] = 0; //이동할 거니깐 0으로 초기화
			}
		}
	}
	Q.push(State(simba.x, simba.y, 0)); //심바의 처음 위치, 거리
	simba.s = 2; //몸집 크기
	simba.ate = 0; //먹은 회수

	while (!Q.empty()) {
		State tmp = Q.top(); //하나를 꺼냄 (처음 심바 위치)
		Q.pop();
		int x = tmp.x;
		int y = tmp.y;
		int z = tmp.dis;

		//잡아 먹을 수 있는지
		if (map[x][y] != 0 && map[x][y] < simba.s) {

			//잡아 먹으므로, 토끼가 있던 위치가 심바의 위치
			simba.x = x;
			simba.y = y;
			simba.ate++;
			if (simba.ate >= simba.s) simba.sizeUp();
			map[x][y] = 0; //먹은 위치는 0으로


			//잡아먹은 위치부터 다시 퍼질 것이므로 체크배열은 다시 0으로 초기화
			for (i = 1; i <= n; i++) {
				for (j = 1; j <= n; j++) {
					ch[i][j] = 0; //체크 배열 초기화
				}
			}

			//다시 출발해야하니깐 싹 빼버림;
			while (!Q.empty()) Q.pop();

			//현재까지 움직인 거리..(최초부터)
			res = tmp.dis;
		}

		//심바의 위치에서 퍼져 나가기 (상하좌우)
		for (i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			//좌표가 경계를 벗어나고 simba 사이즈보다 크고... 방문을 했음 => 컨티뉴!
			if (xx<1 || xx>n || yy<1 || yy>n || map[xx][yy] > simba.s || ch[xx][yy] > 0) continue;

			//아니라면 (방문 할 수 있다면)
			Q.push(State(xx, yy, z + 1)); // 우선순위 큐에 좌표 넣어주고, dis는 출발점에서 +1
			ch[xx][yy] = 1; //방문했다고 표시
		}
	}
	printf("%d\n", res);
	return 0;
}