#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 101

int N,M;
int map[MAX][MAX];
bool visited[MAX][MAX];
int length[MAX][MAX]; //이동거리 저장
//상우하좌
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};

void bfs(int r, int c){

    queue<pair<int,int>> q;
    q.push(make_pair(r,c));
    length[r][c]=1;
    visited[r][c]=true;

    while(!q.empty()){
        int cr=q.front().first;
        int cc=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nr=cr+dr[i];
            int nc=cc+dc[i];

            if(nr>N||nr<1||nc>M||nc<1||map[nr][nc]==0||visited[nr][nc]) continue;

            length[nr][nc]=length[cr][cc]+1;
            q.push(make_pair(nr,nc));
            visited[nr][nc]=true;
        }

    }


}

int main(){

    cin>>N>>M;
    for(int i=1;i<=N;i++){
        string str;
        cin>>str;
        for(int j=1;j<=M;j++){
            int a=(int)str.at(j-1)-48;
            map[i][j]=a;
        }
    }

    bfs(1,1);

    cout<<length[N][M]<<"\n";
}