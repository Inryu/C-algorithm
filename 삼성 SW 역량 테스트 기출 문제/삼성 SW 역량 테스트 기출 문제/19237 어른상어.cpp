#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, k; //격자 크기, 상어개수, 냄새 지속 시간
int map[21][21];
Loc tmp[21][21]; //냄새 뿌리는 용
Shark sh[401]; //상어
int priority[401][4];


int time = 0;


//(1,2,3,4 )= up,down, left, right
int dr[5] = { 100,-1,1,0,0 };
int dc[5] = { 100,0,0,-1,1 };

struct Loc {
	int shark_num;
	int cnt;
	
	Loc(int a, int b) {
		shark_num = a;
		cnt = b;
	}
};

struct Shark {
	int r;
	int c;
	int dir; //방향

	Shark(int a, int b, int d) {
		r = a;
		c = b;
		dir = d;
	}
};


//1. 일단 맵을 받고
//2. 순회하면서 상어 있는 것만 큐에 넣고
//3. 큐 빼면서 이동..!?	
	// 1) 상하우좌 순으로 보면서, 

int main() {

	cin >> n >> m >> k;


	int num;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> num;
			cin >> map[i][j];

			//입력받을 때 , 상어 자신의 위치에 냄새 뿌리기
			if (num > 0) {
				tmp[i][j] = Loc(num, k);  // (상어 넘버, 몇초 남았는지)
				sh[num].r = i;
				sh[num].c = j;
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		cin >> num;
		sh[i].dir = num;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= 4; j++) {
			cin >> priority[i][j];
		}
	}



	while (true) {

		for (int i = 1; i <= m; i++) {
			int shark_r = sh[i].r;
			int shark_c = sh[i].c;
			int shark_dir = sh[i].dir;


			int isPossible = 0; //아무 냄새가 없는 칸이 있을 때
			for (int j = 1; j <= 4; j++) {
				int nr = shark_r + dr[j];
				int nc = shark_c + dc[j];


				//범위 벗어났을 때
				if(nr<1||nr>n||nc<1||nc>n) continue;

				//아무 냄새가 없는 칸이 있음
				//여러개면..?!
				//맵에 이미 상어가 있다면..!?
				if (tmp[nr][nc].shark_num == 0) {
					sh[i].r = nr;
					sh[i].c = nc;
					sh[i].dir = j; //방향
					isPossible = 1;
					break;
				}	

			}

			//4칸 다 안될 때
			if (!isPossible) {

			}



		}


		

		/*
		1) 상하좌우 이동, 냄새 뿌리기 
			1-1) 이동방향 결정
				1. 아무 냄새가 없는 곳
				2. 자신의 냄새가 있는 칸
				3. 가능한 게 여러개면, 특정한 우선순위 따름




		2) 이동후 , 여러마리라면 가장 작은 번호를 가진 상어를 삭제 
			-> 큐로 하나씩 빼면서 하면서, 이미 다른 상어가 있는지를 체크 해야겠ㄷㅏㅏ.?!
		*/


		time++;
	
	}




	cout << time << "\n";
	return 0;



}