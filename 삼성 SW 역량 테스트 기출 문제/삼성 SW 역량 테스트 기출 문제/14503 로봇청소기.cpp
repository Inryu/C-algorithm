#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt = 0; //로봇청소기가 청소하는 칸의 개수
int n, m,r,c,d;// (3<=n,m<=50), d: (0,1,2,3) =(북,동,남,서)
int map[51][51]; 
int ch[51][51]; //청소 했는지

int dx[4]={ 0,1,0,-1}; //북,동,남,서
int dy[4]= { -1,0,1,0};

// 현재 진행 방향을 기준으로 왼쪽을 볼 때 
// d: (0,1,2,3) =(북,동,남,서)
// (진행방향+3)%4

/*
ex) 
(0+3)%4=3 (북=>서)
(1+3)%4=0 (동=>북)

*/ 


int main() {
	cin >> n>> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}


	while (true) {

		//1. 현재 위치를 청소한다.
		//후진으로 오는 경우도 있기 때문에 청소 유무 체크, 현재 위치 청소
		if (!ch[r][c]) {
			cnt++;
			ch[r][c]=1;
		}

		//2. 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행
		bool check = false;

		//네 방향
		for (int i = 0; i < 4; i++) {
			//이동 가능할 때 까지 계속 왼쪽 방향으로 회전

			d = (d + 3) % 4; //현재 위치에서 왼쪽 방향 회전 (만약에 북쪽(0)이었다면, 서쪽(3)으로 변화)
			int nr = r + dy[d]; // 회전한 방향으로 한 칸 이동
			int nc = c + dx[d];

			//한 칸 이동 한 게 범위를 벗어나면
			if (nr < 0 || nr >= n || nc < 0 || nc >= m)
				continue;

			//벽이거나 청소되어있다면
			if (map[nr][nc] || ch[nr][nc])
				continue;

			//이동 가능하면 멈춤
			check = true; //가능했다면, 체크
			
			//이동
			r = nr;
			c = nc;
			break;
		}

		//후진 여부
		//c,d인 경우
		if (!check) {

			//후진
			// 후진 방향 (d+2)%4
			r = r + dy[(d + 2) % 4];
			c = c + dx[(d + 2) % 4];

			//후진했는데 더 이상 갈 곳이 없거나, 벽이라면
			if (r < 0 || r >= n || c < 0 || c >= m || map[r][c])
				break;
		}

	}

	cout << cnt;
	return 0;

}