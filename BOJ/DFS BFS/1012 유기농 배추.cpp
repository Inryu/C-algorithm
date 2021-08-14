#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 51
int map[MAX][MAX];
int M, N, K;

//상우하좌
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};


void bfs(int i, int j){
    queue<pair<int,int>> qq;
    qq.push(make_pair(i,j));
    map[i][j]=2; //이미 방문한 곳은 2로 만들어주기.

    while(!qq.empty()){
        int r=qq.front().first;
        int c=qq.front().second;

        qq.pop();

        for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];

            if(nr<0||nr>N-1||nc<0||nc>M-1||map[nr][nc]!=1) continue;

            qq.push(make_pair(nr,nc));
            map[nr][nc]=2;
        }
    }
}

int main(){
    int T;
    cin>>T;

    for(int t=0;t<T;t++){

        memset(map,0,sizeof(map));

        int cnt=0;
        cin>>M>>N>>K;

        for(int i=0;i<K;i++){
            int c, r;
            cin>>c>>r;
            map[r][c]=1;
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j]==1) {
                    bfs(i,j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
    }
}


