#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//상우하좌
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };

//구조체
struct Loc {
	int r; //행
	int c; //열

	//생성자
	Loc(int a, int b) {
		r = a;
		c = b;
	}
};


int R, C, T;
int map[51][51];
vector<int> clean; //공기 청정기의 행만 저장! 항상 1열이므로
queue<Loc> Q;

int main() {

	cin >> R >> C >> T;

	//입력 받기
	int num;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> num;
			map[i][j] = num;

			//공기 청정기
			if (num == -1) {
				clean.push_back(i);
			}
			
		}
	}

	int time = 0;


	while (time < T) {

		//1) 현재 미세먼지가 있는 곳만 큐에 넣기
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {

				if (map[i][j] > 0) {
					Q.push(Loc(i, j));
				}
			}
		}

		//2) 미세먼지 확산
		int tmp[51][51] = { 0, }; //동시에 확산하므로 누적값 더해줄 배열

		//큐에서 빼면서
		while (!Q.empty()) {
			Loc loc = Q.front(); //미세먼지 좌표
			Q.pop();

			// 확산되는 양
			int spreadval = map[loc.r][loc.c] / 5;

			// 인접한 네 방향으로 확산
			for (int i = 0; i < 4; i++) {
				int nr = loc.r + dr[i];
				int nc = loc.c + dc[i];

				if (nr<1 || nr>R || nc<1 || nc>C || map[nr][nc] == -1) continue;
				
				tmp[nr][nc] += spreadval;
				tmp[loc.r][loc.c] -= spreadval;
			}

		}

		// 확산후 원래 배열(map)에 더해주기
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				map[i][j] += tmp[i][j];
			}
		}
	
		//3) 공기청정기 작동
		int afterclean[51][51] = { 0, };

		int top = clean[0]; //위쪽 공기청정기 행
		int bottom = clean[1]; //아래쪽 공기청정기 행


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

		//map에 복사 (순환한 테두리만 복사해야함..!)
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (i == 1 || i == top || i == bottom || i == R || j == 1 || j == C) {
					map[i][j] = afterclean[i][j];
				}
			}
		}

		time++;


	}

	//남아있는 미세먼지 양
	int ans = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {

			if (map[i][j] > 0) ans += map[i][j];
		}
	}
	
	cout << ans;
	return 0;

}

