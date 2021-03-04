#include<stdio.h>
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int map[21][21];
int ch[21];
int n,m;
int minval=2147000;

void DFS(int v,int val){
    int i;
    if(v==n){
        if(val<minval) minval=val;
    }else{
        for(i=1;i<=n;i++){
            if(map[v][i]!=0&&ch[i]==0){
                ch[i]=1;
                DFS(i,val+map[v][i]);
                ch[i]=0;
            }
        }
    }

}

//최소비용 DFS!
int main(){
    int i,a,b,c;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&c);
        map[a][b]=c;
    }

    ch[1]=1;
    DFS(1,0);

    printf("%d",minval);

}