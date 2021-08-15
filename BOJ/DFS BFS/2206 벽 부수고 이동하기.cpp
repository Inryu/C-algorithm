#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 1000+1

int N,M;
char map[MAX][MAX];
int visited[MAX][MAX][2]; // 3차원은 벽을 뚫었는지 여부!
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};

struct Loc{
    int r,c;
    bool isCrushed;

    Loc(int rr,int cc, bool iisCrushed){
        r=rr;
        c=cc;
        isCrushed=iisCrushed;
    }
};

int bfs(){
    queue<Loc> q;
    q.push(Loc(1,1,false)); //(1,1)에서 시작, 아직 벽 안뚫음
    visited[1][1][false]=1;

    while(!q.empty()){
        int r=q.front().r;
        int c=q.front().c;
        bool isCrushed=q.front().isCrushed;
        q.pop();

        //도착
        if(r==N&&c==M){
            return visited[r][c][isCrushed];
        }

        for(int d=0;d<4;d++){
            int nr=r+dr[d];
            int nc=c+dc[d];
            if(nr<1||nr>N||nc<1||nc>M) continue;
            if(visited[nr][nc][isCrushed]) continue; //방문한 적 있다면


            //1.벽 이고, 아직 뚫은 적이 없다
            if(map[nr][nc]=='1'&&!isCrushed){
                visited[nr][nc][true]=visited[r][c][isCrushed]+1; //뚫고, 거리 더해주기
                q.push(Loc(nr,nc,true));
            }

            //2. 벽이 없다.
            else if(map[nr][nc]=='0'&&!visited[nr][nc][isCrushed]){
                visited[nr][nc][isCrushed]=visited[r][c][isCrushed]+1;
                q.push(Loc(nr,nc,isCrushed));
            }

        }
    }

    return -1;
}

int main(){
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            char val; cin>>val;
            map[i][j]=val;
        }
    }

    cout<<bfs()<<"\n";
    return 0;
}