#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 19+1
int map[MAX][MAX];
bool visited[MAX][MAX];

// ➡️↘️⬇️↙️
int dr[4]={0,1,1,1};
int dc[4]={1,1,0,-1};


//검:1 , 흰:2
void checkFive(int sr, int sc,int color){

    visited[sr][sc]=true;
    //한 방향마다
    for(int d=0;d<4;d++){
        int nr=sr;
        int nc=sc;
        int cnt=0;
        for(int i=1;i<=4;i++){ //4개 더 있으면!
            nr+=dr[d];
            nc+=dc[d];

            if(nr<1||nr>19||nc<1||nc>19) break;
            if(map[nr][nc]!=color) break;
            cnt++;
        }

        if(cnt==4){
            //하나 더 있는지 확인
            nr+=dr[d];
            nc+=dc[d];

        }
    }

}


int main(){
    for(int i=1;i<=19;i++){
        for(int j=1;j<=19;j++){
            cin>>map[i][j];
        }
    }

    for(int i=1;i<=19;i++){
        for(int j=1;j<=19;j++){
            if(!map[i][j]) continue;
            checkFive(i,j,map[i][j]);
        }
    }
}