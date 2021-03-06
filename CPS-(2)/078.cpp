
// 🧤MST (크루스칼)

#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int unf[10001];

struct Edge{
    int s; //시작 정점
    int e;  //끝 정점
    int val; //가중

    //생성자
    Edge(int a, int b, int c){
        s=a;
        e=b;
        val=c;
    }

    //비교 연산자 오버로딩
    bool operator<(const Edge &b)const{
        return val<b.val; //val기준으로 오름차순
   }
};

int Find(int v){
    if(v==unf[v]) return v;
    else return unf[v]=Find(unf[v]);
}

void Union(int a, int b){
    a=Find(a);
    b=Find(b);
    if(a!=b) unf[a]=b;
}

int main(){

    //간선들 저장
   vector<Edge> Ed;


    int i, n, m, a, b, c, cnt=0, res=0;
    scanf("%d %d", &n, &m);

    //모든 정점의 unf 배열을 각자 자기 자신의 집합으로 초기화
    for(i=1; i<=n; i++){
        unf[i]=i;
    }


    //엣지 읽어서 넣음
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &a, &b, &c);
        Ed.push_back(Edge(a, b, c));
    }

    //val기준으로 오름차순 정렬
    sort(Ed.begin(), Ed.end());

    //각 오름차순된 Ed들엣지들
    for(i=0; i<m; i++){
        int fa=Find(Ed[i].s);
        int fb=Find(Ed[i].e);

        //서로 다른 집합이면 (사이클이 생기지 않으면)
        if(fa!=fb){
            res+=Ed[i].val; //가중치 누적
            Union(Ed[i].s, Ed[i].e); //두개의 노드는 집합으로 만듦
        }
    }
    printf("%d\n", res);
    return 0;
}
