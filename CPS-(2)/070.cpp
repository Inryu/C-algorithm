//BFS, 큐 기본 개념 구현
#include<stdio.h>
#include <iostream>
#include<vector>
#include<algorithm>
#include <queue>
using namespace std;

int ch[30],dis[30];

int main() {
    int n, m, a, b, x, i;

    vector<int> map[30]; //연결 리스트
    //😇큐!
    queue<int> Q;

    scanf("%d %d", &n, &m);

    for (i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        map[a].push_back(b); //방향 그래프 연결 리스트
    }

    Q.push(1);
    ch[1] = 1;

    while (!Q.empty()) {
        x = Q.front(); //참초
        Q.pop(); //진짜 꺼내기

        //꺼낸 것에서 인접한 노드들
        for (i = 0; i <= map[x].size(); i++) {
            if (ch[map[x][i]] == 0) { //방문 안 했다면
                ch[map[x][i]] = 1;
                Q.push(map[x][i]); //넣어주고

                //😇최단 거리 계산!!해서 dis update
                dis[map[x][i]] = dis[x] + 1; //i까지는 x라는 노드를 통해 바로 가니깐

            }
        }
    }
    //dis 출력
    for (i = 2; i <= n; i++) {
        printf("%d : %d\n", i, dis[i]);
    }
}