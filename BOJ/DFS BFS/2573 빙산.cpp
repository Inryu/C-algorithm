#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 300+1
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
int N,M;
int map[MAX][MAX];
bool visited[MAX][MAX];
int res=0; //두 덩어리 이상으로 분리되는 최초의 시간
int cntGroup=0;
bool isNotExist=false;
bool found=false;

void meltIce(){
    queue<pair<int,int>> q;
    int tmpMap[MAX][MAX]={0,}; //주변에 있는 0 개수 저장.

    // 빙산이 있는 좌표
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++) {
            if(map[i][j]==0) continue;
            q.push({i,j});
        }
    }

    //빙산이 다 녹아있는 경우
    if(q.empty()){ isNotExist=true; return;}

    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();

        int cnt=0;
        for(int d=0;d<4;d++){
            int nr=r+dr[d];
            int nc=c+dc[d];

            if(nr<0||nr>N-1||nc<0||nc>M-1||map[nr][nc]>0) continue;
            cnt++; //주변에 0인 거 개수 세기
        }

        tmpMap[r][c]=cnt;
    }

    // 빼주기!
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++) {

            //삼항연산자 문법.. 꽤나 웃기게 썼음
            map[i][j]=(map[i][j]-tmpMap[i][j]>0)? map[i][j]-tmpMap[i][j]:0;

            /*
            if(map[i][j]-tmpMap[i][j]>0){
                map[i][j]-=tmpMap[i][j];
            }else{
                map[i][j]=0;
            }
             */
        }
    }
}

void findGroup(int sr, int sc){

    queue<pair<int,int>> q;
    q.push({sr,sc});
    visited[sr][sc]=true;

    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();

        for(int d=0;d<4;d++){
            int nr=r+dr[d];
            int nc=c+dc[d];

            if(nr<0||nr>N-1||nc<0||nc>M-1||map[nr][nc]==0||visited[nr][nc]) continue;
            q.push({nr,nc});
            visited[nr][nc]=true;
        }
    }
}
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
        }
    }

    while(!found){
        res++;
        //1. 녹이기.
        meltIce();

        if(isNotExist){
            cout<<0<<"\n";
            exit(0);
        }

        //2. 덩어리 개수 세기
        memset(visited,false,sizeof(visited));
        cntGroup=0;

        //BFS 시작점
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++) {
                if(map[i][j]&&!visited[i][j]){
                    //덩어리 하나씩 세기
                    findGroup(i,j);
                    cntGroup++;

                    if(cntGroup>=2) {
                        found=true;
                        break;
                    }
                }
            }
        }
    }
    cout<<res<<"\n";
}
