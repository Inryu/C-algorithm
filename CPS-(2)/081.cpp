// 벨만-포드
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int dist[101];

struct Edge{
    int s;
    int e;
    int val;

    Edge(int a, int b, int c){
        s=a;
        e=b;
        val=c;
    }
};

int main(){
    vector<Edge> Ed; // 간선 정보 넣을


    int i,n,m,a,b,c,j,s,e;

    scanf("%d %d",&n,&m);

    //간선 정보 입력
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&c);
        Ed.push_back(Edge(a,b,c));
    }

    //dist배열 초기화
    for(i=1;i<=n;i++){
        dist[i]=21470000;
    }

    scanf("%d %d", &s, &e); //출발 정점, 도착 정점

    for(i=1;i<n;i++){ //1번만에 ~n-1번 만에
        for(j=0;j<Ed.size();j++){ //각 엣지 살펴야함
            int u=Ed[j].s; //각 엣지마다 출발 정점
            int v=Ed[j].s; //끝 정점
            int w=Ed[j].val;

            if(dist[u]!=2147000000 && dist[u]+w<dist[v]){ //출발 정점 + 가중치 < 기존 값
                dist[v]=dist[u]+w;
            }

        }
    }

    //n번 만에 가는 경우 : 음의 사이클이 있음
    for(j=0;j<Ed.size();j++){
        int u=Ed[j].s; //각 엣지마다 출발 정점
        int v=Ed[j].s; //끝 정점
        int w=Ed[j].val;

        if(dist[u]!=2147000000 && dist[u]+w<dist[v]){ //출발 정점 + 가중치 < 기존 값
            printf("-1\n");
            exit(0);
        }
    }

    printf("%d\n",dist[e]);
    return 0;
}

