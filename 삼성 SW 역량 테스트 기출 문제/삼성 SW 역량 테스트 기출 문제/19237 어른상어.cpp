#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, k; //���� ũ��, ����, ���� ���� �ð�
int map[21][21];
Loc tmp[21][21]; //���� �Ѹ��� ��
Shark sh[401]; //���
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
	int dir; //����

	Shark(int a, int b, int d) {
		r = a;
		c = b;
		dir = d;
	}
};


//1. �ϴ� ���� �ް�
//2. ��ȸ�ϸ鼭 ��� �ִ� �͸� ť�� �ְ�
//3. ť ���鼭 �̵�..!?	
	// 1) ���Ͽ��� ������ ���鼭, 

int main() {

	cin >> n >> m >> k;


	int num;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> num;
			cin >> map[i][j];

			//�Է¹��� �� , ��� �ڽ��� ��ġ�� ���� �Ѹ���
			if (num > 0) {
				tmp[i][j] = Loc(num, k);  // (��� �ѹ�, ���� ���Ҵ���)
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


			int isPossible = 0; //�ƹ� ������ ���� ĭ�� ���� ��
			for (int j = 1; j <= 4; j++) {
				int nr = shark_r + dr[j];
				int nc = shark_c + dc[j];


				//���� ����� ��
				if(nr<1||nr>n||nc<1||nc>n) continue;

				//�ƹ� ������ ���� ĭ�� ����
				//��������..?!
				//�ʿ� �̹� �� �ִٸ�..!?
				if (tmp[nr][nc].shark_num == 0) {
					sh[i].r = nr;
					sh[i].c = nc;
					sh[i].dir = j; //����
					isPossible = 1;
					break;
				}	

			}

			//4ĭ �� �ȵ� ��
			if (!isPossible) {

			}



		}


		

		/*
		1) �����¿� �̵�, ���� �Ѹ��� 
			1-1) �̵����� ����
				1. �ƹ� ������ ���� ��
				2. �ڽ��� ������ �ִ� ĭ
				3. ������ �� ��������, Ư���� �켱���� ����




		2) �̵��� , ����������� ���� ���� ��ȣ�� ���� �� ���� 
			-> ť�� �ϳ��� ���鼭 �ϸ鼭, �̹� �ٸ� �� �ִ����� üũ �ؾ߰ڤ�����.?!
		*/


		time++;
	
	}




	cout << time << "\n";
	return 0;



}