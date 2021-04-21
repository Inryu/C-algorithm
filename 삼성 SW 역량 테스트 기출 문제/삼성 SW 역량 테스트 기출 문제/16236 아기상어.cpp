#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int map[21][21], ch[21][21];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

//�ɹٰ� �����̴� ��Ȳ (��ǥ, ����� ���������� �Ÿ�)
struct State {
	int x, y, dis;
	State(int a, int b, int c) { 
		x = a; //�ɹ��� ��ǥ
		y = b; //�ɹ��� ��ǥ
		dis = c; //���ݱ��� ������ �Ÿ�
	}

	bool operator<(const State &b)const {
		if (dis != b.dis) return dis > b.dis; //�Ÿ��� ���� ������ �Ÿ� �������� �ּ���!!! 
		if (x != b.x) return x > b.x; //�Ÿ��� ����, x��ǥ�� �ٸ��� x(��)�������� ������(x�� ���� ���� ��)�� ž���� (�ּ���)
		else return y > b.y; //�Ÿ��� ������ x�� ������ ��(y�� ���� �������� ž���� !�ּ���)�� ���� �ɷ� (����)
	}
};

struct Lion {
	int x, y, s, ate; //�ɹ��� ���� (������� ��ġ, ���� ũ��, ���� ȸ��)

	void sizeUp() {
		ate = 0;
		s++;
	}
};

int main() {
	int n, i, j, res = 0;
	priority_queue<State> Q; //�켱���� ť
	Lion simba;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) { //�ɹ� ��ġ
				simba.x = i;
				simba.y = j;
				map[i][j] = 0; //�̵��� �Ŵϱ� 0���� �ʱ�ȭ
			}
		}
	}
	Q.push(State(simba.x, simba.y, 0)); //�ɹ��� ó�� ��ġ, �Ÿ�
	simba.s = 2; //���� ũ��
	simba.ate = 0; //���� ȸ��

	while (!Q.empty()) {
		State tmp = Q.top(); //�ϳ��� ���� (ó�� �ɹ� ��ġ)
		Q.pop();
		int x = tmp.x;
		int y = tmp.y;
		int z = tmp.dis;

		//��� ���� �� �ִ���
		if (map[x][y] != 0 && map[x][y] < simba.s) {

			//��� �����Ƿ�, �䳢�� �ִ� ��ġ�� �ɹ��� ��ġ
			simba.x = x;
			simba.y = y;
			simba.ate++;
			if (simba.ate >= simba.s) simba.sizeUp();
			map[x][y] = 0; //���� ��ġ�� 0����


			//��Ƹ��� ��ġ���� �ٽ� ���� ���̹Ƿ� üũ�迭�� �ٽ� 0���� �ʱ�ȭ
			for (i = 1; i <= n; i++) {
				for (j = 1; j <= n; j++) {
					ch[i][j] = 0; //üũ �迭 �ʱ�ȭ
				}
			}

			//�ٽ� ����ؾ��ϴϱ� �� ������;
			while (!Q.empty()) Q.pop();

			//������� ������ �Ÿ�..(���ʺ���)
			res = tmp.dis;
		}

		//�ɹ��� ��ġ���� ���� ������ (�����¿�)
		for (i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			//��ǥ�� ��踦 ����� simba ������� ũ��... �湮�� ���� => ��Ƽ��!
			if (xx<1 || xx>n || yy<1 || yy>n || map[xx][yy] > simba.s || ch[xx][yy] > 0) continue;

			//�ƴ϶�� (�湮 �� �� �ִٸ�)
			Q.push(State(xx, yy, z + 1)); // �켱���� ť�� ��ǥ �־��ְ�, dis�� ��������� +1
			ch[xx][yy] = 1; //�湮�ߴٰ� ǥ��
		}
	}
	printf("%d\n", res);
	return 0;
}