#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n, map[30][30],cnt=0;
int dx[8]={0,1,1,1,0,-1,-1,-1}; //상,오른쪽 대각선, 오른쪽 ... 으로 시계방향
int dy[8]={-1,-1,0,1,1,1,0,-1};

struct Loc{
    int x;
    int y;

    Loc(int a, int b){
        x=a;
        y=b;
    }
};

queue <Loc> Q; //구조체 큐

int main(){

    int i,j;

    cin>>n;
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) cin>>map[i][j];


    //1행 1열부터 시작해서 탐색!
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(map[i][j]==1){
                Q.push(Loc(i,j)); // 🌟좌표 큐에 넣고
                map[i][j]=0; //0으로 만들기 > 0으로 된 것은 다시 탐색 x

                //상하좌우 대각선 살피기!!! -> Q가 빌 때까지
                while(!Q.empty()){
                    Loc tmp=Q.front(); //🌟Loc형 변수로 받기.
                    Q.pop();

                    //상하좌우 대각선
                    for(i=0;i<8;i++){
                        if(map[tmp.x+dx[i]][tmp.y+dy[i]]==1){
                            Q.push(Loc(tmp.x+dx[i],tmp.y+dy[i]));
                            map[tmp.x+dx[i]][tmp.y+dy[i]]=0;
                        }
                    }
                }

                //큐가 비었으면 더이상 없음!
                cnt++;
            }
        }

    }
    printf("%d\n",cnt);
}
