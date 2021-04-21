#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, k;

struct belt {
	int a; //내구도
	bool isBox;
};

vector <belt> Container(400);


void rotate() {

	//1로 보낼 거
	int lasta = Container[2 * n].a;
	bool lastBox = Container[2 * n].isBox;

	Container[n].isBox = false; //내려갈 거니깐
	 
	//회전 ( 1 ~ 2n-1 거꾸로)
	for (int i = (2*n)-1; i >= 1; i--) {
		int a = Container[i].a;
		int isBox = Container[i].isBox;

		Container[i + 1].a = a;
		Container[i + 1].isBox = isBox;
	}

	//2n->1로
	Container[1].a = lasta;
	Container[1].isBox = lastBox;
}

int main() {
	cin >> n >> k;


	//입력
	for (int i = 1; i <= 2*n; i++) {
		int aa;
		cin >> aa;

		Container[i].a = aa;
		Container[i].isBox = false;
	}


	int stage = 1;
	while (true) {

		//1) 벨트 회전
		rotate();

		//2) 회전 후 로봇이 이동
		// 가장 먼저 벨트에 올라간 로봇부터 = n
		for (int i = n; i >= 1; i--) {

			//내려가는 위치에 박스가 있으면 반드시 땅으로
			if (i == n && Container[i].isBox) {
				Container[i].isBox = false; 
				//땅으로 갔으니 내구도 낮아지는 거는 없다.

				continue;
			}

			//로봇이 그 칸에 있어야 한다!!
			if (Container[i].isBox&&!Container[i + 1].isBox&&Container[i + 1].a >= 1) {
				Container[i].isBox = false;
				Container[i + 1].isBox = true;
				Container[i + 1].a--;
			}
		}

		//3) 올라가는 위치에 로봇이 없다면 로봇을 하나 올린다.
		if (!Container[1].isBox&&Container[1].a >= 1) {
			Container[1].isBox = true;
			Container[1].a--;
		}

		//4) 내구도가 0인 칸의 개수
		int cnt = 0;
		for (int i = 1; i <= 2 * n; i++) {
			if (Container[i].a == 0) cnt++;
		}

		if (cnt >= k) break;
		stage++;

	}

	cout << stage<<"\n";
	return 0;
}

