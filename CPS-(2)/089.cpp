#include <iostream>
#include <queue>
#include<vector>
#include<algorithm>
using namespace std;

int dx[4]={0,1,0,-1}; //상우하좌
int dy[4]={-1,0,1,0}; //상우하좌


int main() {

    int m, n, i, j;
    int res = -2147000000;

    cin >> m >> n;

    vector<vector<int> > tom(n, vector<int>(m,0));
    vector<vector<int> > dis(n, vector<int>(m,0)); //dis 2차원 배열
    queue<pair<int, int>> Q;

    int num;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> num;
            tom[i][j] = num;

            if (tom[i][j] == 1) { //익은 토마토는 큐에 넣어두기
                Q.push(make_pair(i, j)); //행,열
            }
        }
    }

    while (!Q.empty()) {
        pair<int, int> tomato = Q.front();
        Q.pop();

        for (i = 0; i < 4; i++) {
            int xx = tomato.first + dx[i]; //행
            int yy = tomato.second + dy[i]; //열

            if (tom[xx][yy] == 0) {
                if (xx >= 0 && xx < n && yy >= 0 && yy < m) { //tom박스 범위 검사
                    Q.push(make_pair(xx, yy));
                    tom[xx][yy] = 1;
                    dis[xx][yy] = dis[tomato.first][tomato.second] + 1; //레벨탐색에서 경로 개수 업데이트
                }
            }


        }
    }


    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (tom[i][j] == 0) {//하나라도 안익은 토마토가 있으면
                cout<<-1<<endl;
                return 0;
            }
            if (dis[i][j] > res) res = dis[i][j]; //최대일수
        }
    }

    cout<<res<<endl;
    return 0;

}

