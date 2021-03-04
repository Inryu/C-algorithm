#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int map[30][30];//인접행렬
int ch[30]; //방문했는지 체크
int cnt=0;
int n;


void DFS(int v){ //정점을 받음
    int i;
    if(v==n){ //종료 지점!! //여기까지 왔냐
        cnt++;
    }else{
        //계속 DFS로 뻗어 나가야 함
        //갈 수 있는 접점인지 확인
        for(i=1;i<=n;i++){
            if(map[v][i]==1 && ch[i]==0){
                ch[i]=1;
                DFS(i); //i정점으로 뻗어 나감
                ch[i]=0; //다시 백했을 때 체크를 풀어주고 다른 경로.
            }
        }

    }

}

int main(){

    int m,i,a,b;

    scanf("%d %d",&n,&m);

    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        map[a][b]=1;
    }

    ch[1]=1;
    DFS(1); //1번 정점에서 출발
    printf("%d\n",cnt);

}