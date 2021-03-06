// 🧤MST (프림)

#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int ch[30];

struct Edge{ //우선순위큐 구조체
    int e;
    int val;
    Edge(int a, int b){
        e=a;
        val=b;
    }
    bool operator<(const Edge &b)const{
        return val>b.val; //내림차순 (최소 힙)
    }
};

int main(){
    priority_queue<Edge> Q;

    vector<pair<int, int> > map[30]; //가중치 인접 리스트
    int i, n, m, a, b, c, res=0;

    scanf("%d %d", &n, &m);
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &a, &b, &c);
        map[a].push_back(make_pair(b, c));
        map[b].push_back(make_pair(a, c)); //무방향이므로
    }

    Q.push(Edge(1, 0)); //임의의 정점에서 시작

    while(!Q.empty()){
        Edge tmp=Q.top(); //하나 빼고
        Q.pop();
        int v=tmp.e;
        int cost=tmp.val;

        if(ch[v]==0){ //현재 MST집합 됐냐 아니냐
            res+=cost; //안됐으면 넣어버리고
            ch[v]=1;

            //인접 정점중
            for(i=0; i<map[v].size(); i++){
                if(ch[map[v][i].first]==0){ //체크 안된 것들을

                    //우선순위 큐에 넣음 //최소힙인데 왜 - 안붙임?!!?!?!?
                    Q.push(Edge(map[v][i].first, map[v][i].second));
                }
            }
        }

    }
    printf("%d\n", res);
    return 0;
}