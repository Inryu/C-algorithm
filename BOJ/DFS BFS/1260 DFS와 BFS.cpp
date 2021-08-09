#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 1001

int N, M, V;
int map[MAX][MAX];
bool visited[MAX];

void dfs(int v){
    cout<<v<<" ";
    for(int i=1;i<=N;i++){
        if(map[v][i]&&!visited[i]){
            visited[i]=true;
            dfs(i);
        }
    }

}

void bfs(int v){
    queue <int> q;
    q.push(v);
    visited[v]=true;

    while(!q.empty()){
        int idx=q.front();
        q.pop();
        cout<<idx<<" ";

        for(int i=1;i<=N;i++){
            if(map[idx][i]&&!visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}

int main(){
    cin>>N>>M>>V;

    for(int i=0;i<M;i++){
        int a, b;
        cin>>a>>b; //양방향
        map[a][b]=1;
        map[b][a]=1;
    }

    visited[V]=true;
    dfs(V);
    cout<<"\n";

    //visited 초기화
    memset(visited, false, sizeof(visited));
    bfs(V);
    cout<<"\n";

    return 0;
}

