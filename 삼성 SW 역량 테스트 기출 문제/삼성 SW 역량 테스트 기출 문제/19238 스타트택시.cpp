#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dx[4] = { -1,0,1,0 }; //�������
int dy[4] = { 0,1,0,-1 };
int n, m, fuel; //���� ũ��(n*n), �մ� ��, ����
int tr, tc; //�ý��� ��ġ

int map[21][21];

//BFS�� �̿��� �ִܰŸ� ��� ��
int dis[21][21]; //distance �����
bool visit[21][21]; //�湮 �ߴ���

vector <pair <int, int>> endpoint; //�� �մ��� ������

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
		if (dis != b.dis) return dis > b.dis; //�Ÿ� �ּ���
		if (r != b.r) return r > b.r; // �� �ּ���
		if (c != b.c) return c > b.c; // �� �ּ���
	}
};


//1) ó�� �ý� ��ġ ���� �մԱ��� �Ÿ� ���ϱ�
void Cal_Dist() { 

	//�ʱ�ȭ (m���� ���ϹǷ� �Ź� �ʱ�ȭ)
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visit[i][j] = false;
			dis[i][j] = -1;
		}
	}

	queue<Loc> Q;

	Q.push(Loc(tr, tc, 0)); //����� �ֱ� (�ý� ��ġ!)
	//�ٵ� �� dis�� Loc�̶� �迭 ���� ���ұ�!? ��
	// �ý� �������� dis�� ����������ϰ�, ���� ��ġ���� �ִܰŸ��� �˾ƾ��ؼ�
	dis[tr][tc] = 0;
	visit[tr][tc] = true;



	// �������� ���� �ִܰŸ��� 
	// �ý� -> �մԱ��� �� ������ �ٽ� ���ؾ��ϳ�?
	
	//�ִܰŸ� ���ϱ�
	while (!Q.empty()) {

		Loc tmp = Q.front();
		Q.pop();

		//���� ���� ���� (���Ͽ���)
		for (int i = 0; i < 4; i++) {
			int nr = tmp.r + dx[i];
			int nc = tmp.c + dy[i];

			if (nr<1 || nr>n || nc<1 || nc>n) continue; //map������ ���
			if (map[nr][nc] == 1 || visit[nr][nc]) continue; //�����̰ų�, �̹� �湮��


			Q.push(Loc(nr, nc, tmp.dis + 1));
			dis[nr][nc] = tmp.dis + 1;
			visit[nr][nc] = true;

			//�׷� ��������� �� �����ϰ� ��� ���� DIS�� ���� �ǰ�?
		
		}

		

	}


}

void Cal_Destination() {
	
	//�ٽ� dis�� visit�� �ʱ�ȭ�ϸ� DFS�� �ý�(�մ�)-> �մԸ�����
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visit[i][j] = false;
			dis[i][j] = -1;
		}
	}

	queue<Loc> Q;

	Q.push(Loc(tr, tc, 0)); //����� �ֱ� (�ý� ��ġ!)
	dis[tr][tc] = 0;
	visit[tr][tc] = true;


	//�ִܰŸ� ���ϱ� (�մ��¿��->������)
	while (!Q.empty()) {
		Loc tmp = Q.front();
		Q.pop();

		//���� ���� ���� (���Ͽ���)
		for (int i = 0; i < 4; i++) {
			int nr = tmp.r + dx[i];
			int nc = tmp.c + dy[i];

			if (nr<1 || nr>n || nc<1 || nc>n) continue; //map������ ���
			if (map[nr][nc] == 1 || visit[nr][nc]) continue; //�����̰ų�, �̹� �湮��

			Q.push(Loc(nr, nc, tmp.dis + 1));
			dis[nr][nc] = tmp.dis + 1; //�׷� ���⿡ �������� ���� dis�� ������� ����.
			visit[nr][nc] = true;

		}

	}



}


bool solve() { //���
	Cal_Dist(); //1) ���� �ý� ��ġ �������� dis�迭 ���ϱ�

	//�ʿ���, �մ��� �κ�(2~m+1)�� priority queue�� �־���
	priority_queue<Loc> Customer;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] >= 2) { //�մ��� ���
				Customer.push(Loc(i, j, dis[i][j]));
			}
		}
	}

	//2) priority queue�� ���� �Ÿ��� ���� ����� �մԱ���
	Loc customer = Customer.top();
	Customer.pop();

	//���� ����� dis�� -1�̶��, �ý�->�մ����� �� �� ���� ��
	if (customer.dis == -1) return false;

	//ó�� �ý� ��ġ -> �մԱ��� ���� �Ÿ�
	if (customer.dis > fuel) { 
		return false;
	}


	// �մ��� �¿췯 ��
	fuel -= customer.dis;
	tr = customer.r; //�մ� ��ġ (��)
	tc = customer.c; //�մ� ��ġ (��)
	


	//3) �մ� -> ������
	Cal_Destination(); 
	//dis�� �ִܰŸ� ������ ����

	int customer_num = map[tr][tc]; //���⿡ �մ� �ε��� (2~m+1)
	int des_r=endpoint[customer_num].first; // �մ� ������ (��)
	int des_c = endpoint[customer_num].second; //�մ� ������(��)

	// �մ��¿�� -> ���������� ���� �Ÿ�
	int destinatin_dis = dis[des_r][des_c];


	//���� ����� dis�� -1�̶��, �մ�->�������� �� �� ���� ��
	if (destinatin_dis == -1) return false;

	if (destinatin_dis > fuel) {
		return false;
	}

	//�մ� �������� ������
	fuel -= destinatin_dis;
	map[tr][tc] = 0; //���� �մ� ��ġ���� �մ� �������ϱ�
	tr = des_r; // ������ ��ġ (��)
	tc = des_c; //������ ��ġ (��)
	fuel +=destinatin_dis*2; // ���� �� �Ҹ�� ������ 2�� ����!
	


	return true;
}


int main() {

	//�Է�
	cin >> n >> m >> fuel;


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	cin >> tr >> tc; //������ ������ �����ϴ� ��ġ

	endpoint.push_back(make_pair(0, 0));
	endpoint.push_back(make_pair(0, 0)); //�ε��� 1������ �־��ֱ�

	int a, b, c, d;
	for (int i = 2; i <= m+1; i++) { //1�� �����̹Ƿ� 2�� �մ�~ m+1�� �մ����� �ް� �ʿ� ǥ��
		cin >> a >> b >> c >> d;
		map[a][b] = i;
		endpoint.push_back(make_pair(c, d));
	
	}

	//mȸ �ݺ�
	for (int i = 0; i < m; i++) {

		if (!solve()) { //solve�� mȸ ȣ���ϰ�, false�� ��ȯ���� ��
			fuel = -1; //-1 ����ϰ� ����
			break;
		}
	}

	cout << fuel;

	return 0;

}