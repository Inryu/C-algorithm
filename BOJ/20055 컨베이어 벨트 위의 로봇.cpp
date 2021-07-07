#include <iostream>
#include <vector>
using namespace std;

int n, k;

struct belt {
    int score; //내구도
    bool isRobot;
};

vector <belt> rotate(vector <belt> Container);
vector <belt> moveRobot(vector <belt> Container);

int main() {
    vector <belt> Container(400);
    cin >> n >> k;

    //입력
    for (int i = 1; i <= 2*n; i++) {
        int a;
        cin >> a;

        Container[i].score = a;
        Container[i].isRobot = false;
    }

    int stage = 1;
    while (true) {
        Container=rotate(Container);  //1) 벨트 회전
        Container=moveRobot(Container); //2) 로봇 이동

        //3) 내구도가 0인 칸의 개수
        int zeroCnt=0;
        for (int i = 1; i <= 2 * n; i++) {
            if (Container[i].score == 0) zeroCnt++;
        }

        if(zeroCnt>=k) break;
        stage++;
    }

    cout << stage<<"\n";
    return 0;
}

vector <belt>  rotate(vector <belt> Container) {

    //1로 보낼 거
    int lastscore = Container[2 * n].score;
    bool lastRobot = Container[2 * n].isRobot;

    Container[n].isRobot = false; //내려갈 거니깐

    //회전 : 2n-1부터 시계방향으로 한 칸씩 옮김.
    for (int i = (2*n)-1; i >= 1; i--) {
        int score = Container[i].score;
        int isRobot = Container[i].isRobot;

        Container[i + 1].score = score;
        Container[i + 1].isRobot = isRobot;
    }

    Container[1].score = lastscore;
    Container[1].isRobot = lastRobot;

    return Container;
}

vector <belt> moveRobot(vector <belt> Container) {

    //2) 회전 후 로봇이 이동 => 아랫줄에는 로봇없음! 윗줄만 생각
    // 가장 먼저 벨트에 올라간 로봇부터,
    for (int i = n; i >= 1; i--) {

        //내려가는 위치에 박스가 있으면 반드시 땅으로
        if (i == n && Container[i].isRobot) {
            Container[i].isRobot = false;
            //땅으로 갔으니 내구도 낮아지는 거는 없다.
            continue;
        }

        //로봇이 칸에 있고, 다음 칸에는 로봇이 없고, 다음 칸의 내구도가 1보다 크면.
        if (Container[i].isRobot&&!Container[i + 1].isRobot&&Container[i + 1].score >= 1) {
            Container[i].isRobot = false;
            Container[i + 1].isRobot = true;
            Container[i + 1].score--;
        }
    }

    //3) 올라가는 위치에 로봇이 없다면 로봇을 하나 올린다.
    if (!Container[1].isRobot&&Container[1].score>= 1) {
        Container[1].isRobot = true;
        Container[1].score--;
    }

    return Container;
}