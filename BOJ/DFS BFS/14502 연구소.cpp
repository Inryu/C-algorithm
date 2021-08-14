#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N,M;
int map[10][10];
int tmpMap[10][10];
bool visited[10][10]; //BFS 용
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
int maxVal=-1;

vector<pair<int,int>> threeWalls(3); //고른 3개의 벽
vector<pair<int,int>> emptySpace;

void copyMap(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            tmpMap[i][j]=map[i][j];
        }
    }

}

//3. 안전 영역 구하기
void countSafeArea(){
    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(tmpMap[i][j]==0) cnt++;
        }
    }
    maxVal=max(cnt,maxVal);
}

//2. 바이러스 퍼트리기 (BFS)
void spreadVirus(){
    copyMap();

    //벽 3개 고른 거 세워주기
    for(int i=0;i<3;i++){
        int r=threeWalls[i].first;
        int c=threeWalls[i].second;
        tmpMap[r][c]=1;
    }

    memset(visited,false,sizeof(visited));
    queue<pair<int,int>> q;

    //퍼질 바이러스들 넣어주기.
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(tmpMap[i][j]==2){
                q.push({i,j});
                 visited[i][j]=true;
            }
        }
    }

    //퍼트리기
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        tmpMap[r][c]=2;

        for(int d=0;d<4;d++){
            int nr=r+dr[d];
            int nc=c+dc[d];

            if(nr<0||nr>N-1||nc<0||nc>M-1||visited[nr][nc]||tmpMap[nr][nc]!=0) continue;

            q.push({nr,nc});
            visited[nr][nc]=true;
        }
    }
}

//1. 벽 3개 고르기 (emptySpace에서 3개 구해야함) DFS
void makeWall(int startIdx, int L){
    if(L==3) { //3개 조합 구한 경우
        spreadVirus();
        countSafeArea();
        return;
    }

    // 조합 구하기
    for(int i=startIdx;i<emptySpace.size();i++){
        int r=emptySpace[i].first; //🥲인덱스에 startIdx 그냥 넣는 실수🥲
        int c=emptySpace[i].second; //🥲인덱스에 startIdx 그냥 넣는 실수🥲
        threeWalls[L]=make_pair(r,c); //조합 저장
        makeWall(i+1, L+1); //🥲인덱스에 startIdx 그냥 넣는 실수🥲
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int val;
            cin >> val;
            map[i][j] = val;
            if (val == 0) emptySpace.push_back({i, j});
        }
    }

    //조합 사용해서 emptySpace에서 3개 골라야 함.
    makeWall(0, 0);
    cout << maxVal << "\n";

}