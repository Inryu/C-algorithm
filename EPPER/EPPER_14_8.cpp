#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4]={0,1,0,-1}; //상우하좌
int dy[4]={-1,0,1,0}; //상우하
int n,m;

struct Loc{ //좌표
    int x;
    int y;

    //생성자
    Loc(int a, int b){
        x=a;
        y=b;
    }
};


int solution(vector< vector<int>> box, vector< vector<int>> dis, queue<Loc> Q){
    while(!Q.empty()){
        Loc tmp=Q.front();
        Q.pop(); //익은 거 빼서

        //상하좌우 살피기
        for(int i=0;i<4;i++){
            int xx=tmp.x+dx[i];
            int yy=tmp.y+dy[i];

            //범위 검사
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m){
                if(box[xx][yy]==0){ //익지 않았다면
                    box[xx][yy]=1; //익은 토마토로 처리
                    Q.push(Loc(xx,yy));
                    dis[xx][yy]=dis[tmp.x][tmp.y]+1;  //레벨 저장(얼마만에 익었는지, 어디서 왔는지에 따라)
                }
            }

        }
    }

    //dis 배열 중 최대값이 최소 날짜 //모두 익은 상태로 주어졌을 때 자동으로 0

    int res=dis[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(box[i][j]==0){   //상자에 하나라도 안 익은 게 있으면 -1
                return -1;
            }

            if(res<dis[i][j]) res=dis[i][j];
        }
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);

    cin>>m>>n; //n행 m열

    queue<Loc> Q;
    vector< vector<int>> box (n+1,vector<int>(m+1));
    vector< vector<int>> dis (n+1,vector<int>(m+1,0)); //0으로 초기화!


    int tomato;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>tomato;
            box[i][j]=tomato;
            if(box[i][j]==1){ //익은 토마토라면
                Q.push(Loc(i,j)); //큐에 좌표 넣어주기
            }
        }
    }

    int res=solution(box,dis,Q);

    cout<<res;



}