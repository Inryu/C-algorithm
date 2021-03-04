#include<stdio.h>
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ch[30]; //체크 배열
int cnt=0,n;
vector<int> map[30];

void DFS(int v){
    if(v==n){
        cnt++;
    }else{
        for(i=0;i<map[v].size();i++){ //인접리스트를 통해 인접 정점 확인!
            if(ch[map[v][i]]==0){ //v하고 연결된 노드들 방문 안했는지 확인
                ch[map[v][i]]=1;
                DFS(map[v][i]);
                ch[map[v][i]]=0;
            }
        }
    }
}

int main() {
    int m,i,a,b;

    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){ //엣지 하나씩 읽기
        scanf("%d %d",&a,&b);
        map[a].push_back(b); //인접 리스트 생성!!
    }

    ch[1]=1;
    DFS(1);
    prinf("%d\n",cnt);#include<stdio.h>
                       #include <iostream>
                       #include<vector>
                       #include<algorithm>
    using namespace std;

    int ch[30]; //체크 배열
    int cnt=0,n;
    vector<int> map[30];

    void DFS(int v){
        if(v==n){
            cnt++;
        }else{
            for(i=0;i<map[v].size();i++){ //인접리스트를 통해 인접 정점 확인!
                if(ch[map[v][i]]==0){ //v하고 연결된 노드들 방문 안했는지 확인
                    ch[map[v][i]]=1;
                    DFS(map[v][i]);
                    ch[map[v][i]]=0;
                }
            }
        }
    }

    int main() {
        int m,i,a,b;

        scanf("%d %d",&n,&m);
        for(i=1;i<=m;i++){ //엣지 하나씩 읽기
            scanf("%d %d",&a,&b);
            map[a].push_back(b); //인접 리스트 생성!!
        }

        ch[1]=1;
        DFS(1);
        prinf("%d\n",cnt);

    }


}
