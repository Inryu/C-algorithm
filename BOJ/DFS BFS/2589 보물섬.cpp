#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 50+1

int N,M;
char map[MAX][MAX];
int visited[MAX][MAX];

int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
vector<pair<int,int>> lands;
int res=-2147000000;

int bfs(int sr, int sc){

    int maxVal=0;
    memset(visited,0,sizeof(visited));
    queue<pair<int,int>> q;
    q.push({sr,sc});
    visited[sr][sc]=1;

    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();

        for(int d=0;d<4;d++){
            int nr=r+dr[d];
            int nc=c+dc[d];

            if(nr<0||nr>N-1||nc<0||nc>M-1) continue;
            if(map[nr][nc]=='W'||visited[nr][nc]) continue;

            q.push({nr,nc});

            //✨ visited를 방문 여부 + 최단 경로 저장용으로 사용한다.
            visited[nr][nc]=visited[r][c]+1;

            //✨ 최단 경로중 가장 먼 거리가 어딘지 갱신
            maxVal=max(maxVal,visited[nr][nc]);
        }
    }
    return maxVal-1;
}


int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char val; cin>>val;
            map[i][j]=val;
            if(val=='L') lands.push_back({i,j});
        }
    }

    //각 육지 좌표를 시작점으로 하여 최단 경로로 최대한 먼 거리 구하기.
    for(int i=0;i<lands.size();i++){
        res=max(res,bfs(lands[i].first,lands[i].second));
    }
    cout<<res<<"\n";

}
