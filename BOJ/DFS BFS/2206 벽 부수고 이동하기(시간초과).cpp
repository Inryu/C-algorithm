#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 1000+1

int N,M;
char map[MAX][MAX];
char tmpMap[MAX][MAX];
int length[MAX][MAX];
int minVal=2147000000;
bool visited[MAX][MAX];
bool flag=false;
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};

vector<pair<int,int>> walls;

void printMap(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++) {
            cout<<length[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}


void copyMap(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++) {
            tmpMap[i][j]=map[i][j];
        }
    }
}

int bfs(int sr, int sc){

    memset(length, 0, sizeof(length));
    memset(visited, false, sizeof(visited));
    queue<pair<int,int>> q;
    visited[sr][sc]=true;
    length[sr][sc]=1;
    q.push({sr,sc});

    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int d=0;d<4;d++){
            int nr=r+dr[d];
            int nc=c+dc[d];
            if(nr<1||nr>N||nc<1||nc>M||tmpMap[nr][nc]=='1'||visited[nr][nc]) continue;
            visited[nr][nc]=true;
            length[nr][nc]=length[r][c]+1;
            q.push({nr,nc});
        }
    }

    if(length[N][M]==0) return -1; //불가능 할 때
    else {
        flag=true; //한 번이라도 가능하면
        return length[N][M];
    }
}

int main(){
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            char val; cin>>val;
            map[i][j]=val;
            if(val=='1') walls.push_back({i,j});
        }
    }

    for(int i=0;i<walls.size();i++){
        copyMap();
        int r=walls[i].first;
        int c=walls[i].second;

        //1. 벽 부수기 (DFS)
        tmpMap[r][c]='0';
        //2. 최단 경로 (BFS)
        int res=bfs(1,1);
        if(res!=-1) { //가능 하면
            minVal=min(res,minVal);
        }
    }

    if(flag) cout<<minVal<<"\n";
    else{
        cout<<-1<<"\n";
    }

    return 0;
}