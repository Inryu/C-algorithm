//😇최소비용 DFS - 가중치 방향 인접리스트

#include<stdio.h>
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m,minval=2147000;
vector <pair<int,int> > g[30];
int ch[30];

void DFS(int v, int val){
    int i;
    if(v==n){
        if(val<minval) minval=val;
    }
    else{
        for(i=0;i<g[v].size();i++){
            if(ch[g[v][i].first]==0){
                ch[g[v][i].first]==1;
                DFS(g[v][i].first,val+g[v][i].second);
                ch[g[v][i].first]==0;
            }
        }

    }

}

int main(){

    int i,a,b,c;
    scanf("%d %d",&n,&m);

    for(i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&c);
        g[a].push_back(make_pair(b,c)); //시작점 배열에 (도착점,가중치) 쌍으로 연결리스트 생성
    }

    ch[1]=1;
    DFS(1,0);
    printf("%d",minval);

}