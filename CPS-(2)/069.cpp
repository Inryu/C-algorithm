//BFS, 큐 기본 개념 구현
#include<stdio.h>
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Q[100],front=-1,back=-1,ch[10];//왔던 곳으로 다시 가면 안 되니간
vector<int> map[10];

int main(){

    int i,a,b,x;

    for(i=1;i<=6;i++){
        scanf("%d %d",&a,&b);
        map[a].push_back(b);
        map[b].push_back(a); //무방향 인접리스트
    }

    //큐 운행
    // 넣어주기
   Q[++back]=1;
    ch[1]=1;

    while(front<back){ //🌟같아지면 큐는 비는 것 (더 이상 꺼낼 자료가 없음)
        x=Q[++front]; //하나 꺼내주기
        printf("%d ",x);

        for(i=0;i<map[x].size();i++){
            if(ch[map[x][i]==0]){ //인접 노드 중//방문 안 했으면
                ch[map[x][i]]=1;
                Q[++back]=map[x][i];
            }
        }
    }return 0;

}