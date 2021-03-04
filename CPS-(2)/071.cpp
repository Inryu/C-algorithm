#include<stdio.h>
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int ch[10001],d[3]={1,-1,5};//이동하려는 좌표

int main(){
    int s,e,i,x;
    int pos; // 현재 지점에서 갈 수 있는 곳!

    queue<int> Q;

    scanf("%d %d",&s,&e); //s: 시작(현수) e: 도착(송아지)

    //출발지점 일단 넣고
    ch[s]=1;
    Q.push(s);

    while(!Q.empty()){
        x=Q.front();
        Q.pop();

        //한 번만에 갈 수 있는 지점
        for(i=0;i<3;i++){
            pos=x+d[i];
            if(pos<=0||pos>10000) continue;
            if(pos==e){
                printf("%d\n",ch[x]);//실제 점프는 한 단계 전
                exit(0); //프로그램 종료
            }
            if(ch[pos]==0){
                ch[pos]=ch[x]+1; //최소 점프 횟수!!+체,,출발점에서 1로 시작하니깐 실제 점프보다 1큰 상황
                Q.push(pos);
            }

        }
    }

}