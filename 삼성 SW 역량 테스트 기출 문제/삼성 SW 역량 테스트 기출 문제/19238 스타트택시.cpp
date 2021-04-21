#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dx[4] = { -1,0,1,0 }; //상우하좌
int dy[4] = { 0,1,0,-1 };
int n, m, fuel; //지도 크기(n*n), 손님 수, 연료
int tr, tc; //택시의 위치

int map[21][21];

//BFS를 이용한 최단거리 계산 용
int dis[21][21]; //distance 저장용
bool visit[21][21]; //방문 했는지

vector <pair <int, int>> endpoint; //각 손님의 도착점

struct Loc {
	int r;
	int c;
	int dis;

	Loc(int a, int b,int d) {
		r = a;
		c = b;
		dis = d;
	}

	bool operator <(const Loc &b)const {
		if (dis != b.dis) return dis > b.dis; //거리 최소힙
		if (r != b.r) return r > b.r; // 행 최소힙
		if (c != b.c) return c > b.c; // 열 최소힙
	}
};


//1) 처음 택시 위치 기준 손님까지 거리 구하기
void Cal_Dist() { 

	//초기화 (m번을 구하므로 매번 초기화)
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visit[i][j] = false;
			dis[i][j] = -1;
		}
	}

	queue<Loc> Q;

	Q.push(Loc(tr, tc, 0)); //출발점 넣기 (택시 위치!)
	//근데 왜 dis를 Loc이랑 배열 따로 구할까!? 아
	// 택시 기준으로 dis로 정렬해줘야하고, 현재 위치에서 최단거리도 알아야해서
	dis[tr][tc] = 0;
	visit[tr][tc] = true;



	// 목적지로 가는 최단거리는 
	// 택시 -> 손님까지 간 다음에 다시 구해야하나?
	
	//최단거리 구하기
	while (!Q.empty()) {

		Loc tmp = Q.front();
		Q.pop();

		//꺼낸 것의 인접 (상하우좌)
		for (int i = 0; i < 4; i++) {
			int nr = tmp.r + dx[i];
			int nc = tmp.c + dy[i];

			if (nr<1 || nr>n || nc<1 || nc>n) continue; //map범위를 벗어남
			if (map[nr][nc] == 1 || visit[nr][nc]) continue; //벽돌이거나, 이미 방문함


			Q.push(Loc(nr, nc, tmp.dis + 1));
			dis[nr][nc] = tmp.dis + 1;
			visit[nr][nc] = true;

			//그럼 여기까지는 벽 제외하고 모든 곳의 DIS를 구한 건가?
		
		}

		

	}


}

void Cal_Destination() {
	
	//다시 dis와 visit을 초기화하며 DFS로 택시(손님)-> 손님목적지
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visit[i][j] = false;
			dis[i][j] = -1;
		}
	}

	queue<Loc> Q;

	Q.push(Loc(tr, tc, 0)); //출발점 넣기 (택시 위치!)
	dis[tr][tc] = 0;
	visit[tr][tc] = true;


	//최단거리 구하기 (손님태우고->목적지)
	while (!Q.empty()) {
		Loc tmp = Q.front();
		Q.pop();

		//꺼낸 것의 인접 (상하우좌)
		for (int i = 0; i < 4; i++) {
			int nr = tmp.r + dx[i];
			int nc = tmp.c + dy[i];

			if (nr<1 || nr>n || nc<1 || nc>n) continue; //map범위를 벗어남
			if (map[nr][nc] == 1 || visit[nr][nc]) continue; //벽돌이거나, 이미 방문함

			Q.push(Loc(nr, nc, tmp.dis + 1));
			dis[nr][nc] = tmp.dis + 1; //그럼 여기에 목적지에 대한 dis가 들어있을 것임.
			visit[nr][nc] = true;

		}

	}



}


bool solve() { //계산
	Cal_Dist(); //1) 현재 택시 위치 기준으로 dis배열 구하기

	//맵에서, 손님인 부분(2~m+1)를 priority queue로 넣어줌
	priority_queue<Loc> Customer;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] >= 2) { //손님인 경우
				Customer.push(Loc(i, j, dis[i][j]));
			}
		}
	}

	//2) priority queue에 의해 거리가 가장 가까운 손님구함
	Loc customer = Customer.top();
	Customer.pop();

	//가장 가까운 dis가 -1이라면, 택시->손님으로 갈 수 없는 것
	if (customer.dis == -1) return false;

	//처음 택시 위치 -> 손님까지 가는 거리
	if (customer.dis > fuel) { 
		return false;
	}


	// 손님을 태우러 감
	fuel -= customer.dis;
	tr = customer.r; //손님 위치 (행)
	tc = customer.c; //손님 위치 (열)
	


	//3) 손님 -> 목적지
	Cal_Destination(); 
	//dis에 최단거리 구해져 잇음

	int customer_num = map[tr][tc]; //여기에 손님 인덱스 (2~m+1)
	int des_r=endpoint[customer_num].first; // 손님 도착점 (행)
	int des_c = endpoint[customer_num].second; //손님 도착점(열)

	// 손님태우고 -> 도착지까지 가는 거리
	int destinatin_dis = dis[des_r][des_c];


	//가장 가까운 dis가 -1이라면, 손님->목적지로 갈 수 없는 것
	if (destinatin_dis == -1) return false;

	if (destinatin_dis > fuel) {
		return false;
	}

	//손님 도착지로 데려감
	fuel -= destinatin_dis;
	map[tr][tc] = 0; //원래 손님 위치에서 손님 떠났으니깐
	tr = des_r; // 도착지 위치 (행)
	tc = des_c; //도착지 위치 (열)
	fuel +=destinatin_dis*2; // 도착 후 소모된 연료의 2배 충전!
	


	return true;
}


int main() {

	//입력
	cin >> n >> m >> fuel;


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	cin >> tr >> tc; //백준이 운전을 시작하는 위치

	endpoint.push_back(make_pair(0, 0));
	endpoint.push_back(make_pair(0, 0)); //인덱스 1까지는 넣어주기

	int a, b, c, d;
	for (int i = 2; i <= m+1; i++) { //1은 벽돌이므로 2번 손님~ m+1번 손님으로 받고 맵에 표시
		cin >> a >> b >> c >> d;
		map[a][b] = i;
		endpoint.push_back(make_pair(c, d));
	
	}

	//m회 반복
	for (int i = 0; i < m; i++) {

		if (!solve()) { //solve를 m회 호출하고, false를 반환했을 시
			fuel = -1; //-1 출력하고 종료
			break;
		}
	}

	cout << fuel;

	return 0;

}