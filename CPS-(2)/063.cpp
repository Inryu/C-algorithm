#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int map[51][51]; //가중치 인접 행렬
int main(){

    int n,m,i,j,a,b,c;
    scanf("%d %d",&n,&m);//노드, 엣지 개수

    for(i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&c);
        map[a][b]=c;

        //방향이면
//        map[a][b]=1;

        //무방향이면
//        map[a][b]=1;
//        map[b][b]=1;
    }

    //출력
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d ",map[i][j]);
        }
    }
}

