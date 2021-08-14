#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;


int N,M;
int map[10][10];
int tmpMap[10][10];
bool visited[10][10]; //BFS
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
int maxVal=-1;
vector<pair<int,int>> emptySpace;

void copyMap(){

}

void copyMap(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            tmpMap[i][j]=map[i][j];
        }
    }

}
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

    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        tmpMap[r][c]=2; //바이러스로 만들어주기

        for(int d=0;d<4;d++){
            int nr=r+dr[d];
            int nc=c+dc[d];

            if(nr<0||nr>N-1||nc<0||nc>M-1||visited[nr][nc]||tmpMap[nr][nc]!=0) continue;

            q.push({nr,nc});
            visited[nr][nc]=true;
        }
    }

}

//1. 안전 영역 구하기 (emptySpace에서 3개 구해야함) DFS
void makeWall(int startIdx, int L){

    //3개 조합 고른 후엔
    if(L==3) {
        spreadVirus();
        countSafeArea();
        return;
    }

    for(int i=startIdx;i<emptySpace.size();i++){
        int r=emptySpace[i].first;
        int c=emptySpace[i].second;

        tmpMap[r][c]=1; //벽으로 만들어주기
        makeWall(i+1, L+1);
        tmpMap[r][c]=0; //백트래킹 하고 나서는 다시 빈칸으로
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

    copyMap();
    //조합 사용해서 emptySpace에서 3개 골라야 함.
    makeWall(0, 0);

    cout << maxVal << "\n";

}