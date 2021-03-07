#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;


//다익스트라
struct Edge{
    int vex;
    int dis; //vex까지 가는 데 드는 비용

    Edge(int a, int b){
        vex=a;
        dis=b;
    }

    bool operator<(const Edge &b)const {
        return dis > b.dis; // 내림차순
        //매개변수로 넘어온 b.dis가  기준값이 되어 🌟최소힙이 됨.
    }
};

int main(){
    ios_base::sync_with_stdio(false);

    priority_queue<Edge> Q; //최소힙의 우선순위 큐
    vector <pair <int,int>> graph[30]; //인접가중치 연결리스트

    int i,n,m,a,b,c;
    scanf("%d %d",&n,&m);

    vector <int> dist(n+1,2147000000); //무한대로 초기화

    for(i=1;i<m;i++){
        scanf("%d %d %d",&a,&b,&c);
        graph[a].push_back(make_pair(b,c));
    }

    Q.push(Edge(1,0)); //출발 정점, 그리고 드는 비용은 0

    dist[1]=0;

    while(!Q.empty()){
        int now=Q.top().vex; //현재 dist가 최소인 노드의 정점
        int cost=Q.top().dis; // dist가 최소인 노드까지의 cost

        Q.pop();

        if(cost>dist[now]) continue; //업데이트 이전에 큐에 들어가있던 거
        for(i=0;i<graph[now].size();i++){ //인접 정점
            int next=graph[now][i].first;
            int nextDis=cost+graph[now][i].second; //cost+ 임!! 터치한 정점까지의 dis를 더해주기.

            if(dist[next]>nextDis){ //업데이트 해야하는 상황
                dist[next]=nextDis;
                Q.push(Edge(next,nextDis));
            }

        }

    }

    for(i=2;i<=n;i++){
        if(dist[i]!=2147000000) printf("%d : %d",i,dist[i]);
        else printf("%d : impossible",i);
    }

}