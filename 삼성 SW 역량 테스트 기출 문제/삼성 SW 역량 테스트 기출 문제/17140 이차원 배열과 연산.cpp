#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int r, c, k;
int time = 0;
vector< vector<int>> A(100, vector<int>(100)); //첨부터 100으로 두고
int x = 3; //행 개수
int y = 3;// 열 개수

struct map {
	int val; //값
	int cnt; //몇번 있는지

	//생성자
	map(int a, int b) {
		val = a;
		cnt = b;
	}

	//비교 연산자
	bool operator< (const map &b) const {
		if (cnt != b.cnt) return cnt < b.cnt; //cnt 기준으로 오름차순
		else return val < b.val; // val기준으로 오름차순
	}
};

int main() {
	ios_base::sync_with_stdio(false);

	cin >> r >> c >> k;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> A[i][j];
		}
	}

	while (true) {
		if (A[r-1][c-1] == k) break;

		if (time > 100) {
			time = -1;
			break;
		}

		//100개를 넘어가는 경우는 어찌?

		int newx = 0;
		int newy = 0;


		if (x >= y) { //R연산
			for (int i = 0; i < x; i++) { //모든 행에 대해서 정렬

			
				vector <int> numcnt(101, 0); 	//숫자 개수 세기
				for (int j = 0; j < y; j++) { // 각 행에서 열마다
					int val = A[i][j];

					if (val != 0) {
						numcnt[val]++;
						A[i][j] = 0;
					}
				}

				vector<map> MAP; //개수 센 거 map 구조체에 넣기
				for (int j = 0; j <= 100; j++) {
					if (numcnt[j] != 0) {
						MAP.push_back(map(j, numcnt[j])); //(val, cnt)
					}
				}
				sort(MAP.begin(), MAP.end()); // map 구조체 정렬

				int idx = 0; // A배열에 넣어주기
				for (int j = 0; j < MAP.size(); j++) {
					A[i][idx] = MAP[j].val;
					A[i][idx+1] = MAP[j].cnt;
					idx = idx + 2;
				}
				newy = max(newy, idx); //최대 크기의 열
			}
			
		}
		else if (x < y) { //C연산
			for (int j = 0; j < y; j++) { //모든 열에 대해서 정렬
				vector <int> numcnt(101, 0); //숫자 개수 세기
				for (int i = 0; i < x; i++) { // 각 열에서 행마다
					int val = A[i][j];
					if (val != 0) {
						numcnt[val]++;
						A[i][j] = 0;
					}
				}

				vector<map> MAP;//개수 센 거 map 구조체에 넣기
				for (int i = 0; i <= 100; i++) {
					if (numcnt[i] != 0) {
						MAP.push_back(map(i, numcnt[i])); //(val, cnt)
					}
				}
				sort(MAP.begin(), MAP.end());			// map 구조체 정렬

				int idx = 0; 
				for (int i = 0; i < MAP.size(); i++) {// A배열에 넣어주기
					A[idx++][j] = MAP[i].val;
					A[idx++][j] = MAP[i].cnt;
				}
				newx = max(newx, idx); //최대 크기 행
			}
	}

	x = max(x, newx);
	y = max(y, newy);
	time++;

	}
	cout << time;
	return 0;
}