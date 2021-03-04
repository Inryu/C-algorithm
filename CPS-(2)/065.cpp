#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int map[9][9]={1}; //전부 1로 초기화
int ch[9][9];
int cnt;


void DFS(int r,int c){
    if(r==7&&c==7){
        cnt++;
    }else{
        if(map[r-1][c]==0&&ch[r-1][c]==0){ //상
            ch[r-1][c]=1;
            DFS(r-1,c);
            ch[r-1][c]=0;
        }else if(map[r+1][c]==0&&ch[r+1][c]==0){//하
            ch[r+1][c]=1;
            DFS(r+1,c);
            ch[r+1][c]=0;
        }else if(map[r][c-1]==0&&ch[r][c-1]==0){ //좌
            ch[r][c-1]=1;
            DFS(r,c-1);
            ch[r][c-1]=0;
        }else if(map[r][c+1]==0&&ch[r][c+1]==0){ //우
            ch[r][c+1]=1;
            DFS(r,c+1);
            ch[r][c+1]=0;
        }
    }

}
//미로 탐색 (DFS)
int main(){

    int i,j;

    for(i=1;i<=7;i++){
        for(j=1;j<=7;j++){
            scanf("%d",&map[i][j]);
        }
    }
    ch[1][1]=1;
    DFS(1,1);
    printf("%d\n",cnt);

}